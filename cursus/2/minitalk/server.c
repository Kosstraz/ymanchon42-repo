/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:57:05 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/09 20:02:20 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

void	*ft_memset(void *s, int c, unsigned long n);

typedef struct s_servmsg
{
	unsigned int	cpid_idx;
	unsigned int	cpid;
	unsigned int	i;
	unsigned int	byte;
	unsigned int	size;
	unsigned char	*message;
}	t_servmsg;

t_servmsg	g_sm;

void	reset_servmsg(t_servmsg *servmsg)
{
	servmsg->i = 0;
	servmsg->size = 0;
	servmsg->byte = 0;
	servmsg->cpid = 0;
	servmsg->cpid_idx = 0;
	servmsg->message = NULL;
}

void	take_cpid(int signum)
{
	if (signum == SIGUSR1)
		g_sm.cpid |= ((g_sm.cpid & 0x0) << g_sm.cpid_idx++);
	else if (signum == SIGUSR2)
		g_sm.cpid |= ((__UINT32_MAX__ & 0x1) << g_sm.cpid_idx++);
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
	if (g_sm.i >= 32)
	{
		g_sm.i = 0;
		g_sm.message = (unsigned char *)malloc((g_sm.size + 1)
				* sizeof(unsigned char));
		if (!g_sm.message)
			exit(1);
		ft_memset(g_sm.message, 0, g_sm.size);
	}
}

void	signal_handler(int signum)
{
	if (!g_sm.message)
	{
		if (g_sm.cpid_idx < 32)
			take_cpid(signum);
		else
			setup_transmission(signum);
	}
	else if (g_sm.message)
	{
		if (signum == SIGUSR1)
			g_sm.message[g_sm.i] |= ((0xFF & 0x0) << g_sm.byte++);
		else if (signum == SIGUSR2)
			g_sm.message[g_sm.i] |= ((0xFF & 0x1) << g_sm.byte++);
		if (g_sm.byte == 8)
		{
			g_sm.byte = 0;
			g_sm.i++;
		}
		if (g_sm.i > g_sm.size - 1)
		{
			g_sm.message[g_sm.i] = '\0';
			ft_printf("Message transmit -> \e[34m%s\e[0m\n", g_sm.message);
			free(g_sm.message);
			reset_servmsg(&g_sm);
		}
	}
}

int	main(void)
{
	int			pid;

	pid = getpid();
	ft_printf("\e[32mID du processus : %d\e[0m\n", pid);
	reset_servmsg(&g_sm);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		;
	return (0);
}
