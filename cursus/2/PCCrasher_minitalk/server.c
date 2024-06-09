/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:57:05 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/09 19:02:35 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

void	*ft_memset(void *s, int c, unsigned long n);

typedef struct s_servmsg
{
	int				byte;
	int				cpid;
	unsigned int	i;
	unsigned int	size;
	unsigned char	*message;
}	t_servmsg;

t_servmsg	g_sm;

void	reset_servmsg(t_servmsg *sm)
{
	sm->i = 0;
	sm->byte = -1;
	sm->cpid = -1;
	sm->size = 0;
	sm->message = NULL;
}

void	take_cpid(int signum)
{
	if (signum == SIGUSR1)
		g_sm.cpid |= ((g_sm.cpid & 0x0) << (-(g_sm.byte--) + 1));
	else if (signum == SIGUSR2)
		g_sm.cpid |= ((__UINT32_MAX__ & 0x1) << (-(g_sm.byte--) + 1));
	if (g_sm.byte == -32)
		g_sm.byte = 0;
}

void	setup_transmission(int signum)
{
	if (g_sm.i < 32)
	{
		if (signum == SIGUSR1)
			g_sm.size |= ((g_sm.size & 0x0) << g_sm.i++);
		else if (signum == SIGUSR2)
			g_sm.size |= ((__UINT32_MAX__ & 0x1) << g_sm.i++);
	}
	else
	{
		g_sm.byte = 0;
		g_sm.i = 0;
		g_sm.message = (unsigned char *)malloc((g_sm.size + 1)
				* sizeof(unsigned char));
		if (!g_sm.message)
		{
			kill(g_sm.cpid, SIGUSR1);
			exit(1);
		}
		ft_memset(g_sm.message, 0, g_sm.size);
	}
}

void	signal_handler(int signum)
{
	if (!g_sm.message)
	{
		if (g_sm.byte < 0)
			take_cpid(signum);
		else
			setup_transmission(signum);
	}
	else if (g_sm.message)
	{
		if (signum == SIGUSR1)
			g_sm.message[g_sm.i++] |= ((0x7F & 0x0) << g_sm.byte++);
		else if (signum == SIGUSR2)
			g_sm.message[g_sm.i++] |= ((0x7F & 0x1) << g_sm.byte++);
		if (g_sm.byte == 8)
			g_sm.byte = 0;
		if (g_sm.i > g_sm.size - 1)
		{
			g_sm.message[g_sm.i] = '\0';
			ft_printf("Message transmit -> \e[34m%s\e[0m\n", g_sm.message);
			kill(g_sm.cpid, SIGUSR2);
			free(g_sm.message);
			reset_servmsg(&g_sm);
		}
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("\e[32mID du processus serveur : %d\e[0m\n", pid);
	reset_servmsg(&g_sm);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		;
	return (0);
}
