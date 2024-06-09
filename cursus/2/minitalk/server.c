/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:57:05 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/09 16:58:25 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_servmsg
{
	unsigned int	i;
	unsigned int	byte;
	unsigned int	size;
	unsigned char	*message;
}	t_servmsg;

t_servmsg	g_sm;

void	init_servmsg(t_servmsg *servmsg)
{
	servmsg->i = 0;
	servmsg->size = 0;
	servmsg->byte = 0;
	servmsg->message = NULL;
}

void	take_size(int signum)
{
	if (signum == SIGUSR1)
		g_sm.size |= ((g_sm.size & 0x0) << g_sm.i++);
	else if (signum == SIGUSR2)
		g_sm.size |= ((__UINT32_MAX__ & 0x1) << g_sm.i++);
}

void	malloc_message(void)
{
	g_sm.i = 0;
	g_sm.message = (unsigned char *)malloc((g_sm.size + 1)
			* sizeof(unsigned char));
	if (!g_sm.message)
		exit(1);
}

void	signal_handler(int signum)
{
	if (g_sm.i < 32 && !g_sm.message)
		take_size(signum);
	if (g_sm.i >= 32 && !g_sm.message)
		malloc_message();
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
			ft_printf("%s\n", g_sm.message);
			free(g_sm.message);
			init_servmsg(&g_sm);
		}
	}
}

int	main(void)
{
	int			pid;

	pid = getpid();
	ft_printf("ID du processus : %d\n", pid);
	init_servmsg(&g_sm);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1);
	return (0);
}
