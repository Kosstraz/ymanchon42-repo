/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cachetra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:11:21 by cachetra          #+#    #+#             */
/*   Updated: 2024/07/09 19:11:21 by cachetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

// av[1] --> pid du server
// av[2] --> chaine a envoyer

static void	mt_putstr_fd(char *str, int fd)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(fd, str, len);
}

static pid_t	mt_atopid(char *nb)
{
	int		i;
	pid_t	rtn;

	i = 0;
	rtn = 0;
	while ((nb[i] == ' ') || ('\t' <= nb[i] && nb[i] <= '\r'))
		i++;
	while (nb[i] && nb[i] >= '0' && nb[i] <= '9')
		rtn = rtn * 10 + nb[i++] - '0';
	return (rtn);
}

static void	mt_send_message(pid_t pid, char *mess, int len)
{
	int		k;

	k = BIT32;
	while (k)
	{
		if (len & k)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		k >>= 1;
		usleep(7);
	}
	while (*mess)
	{
		k = BIT8;
		while (k)
		{
			if (*mess & k)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			k >>= 1;
			usleep(7);
		}
		mess++;
	}
}

int	main(int ac, char **av)
{
	int		len;
	pid_t	serv_pid;

	len = 0;
	if (ac != 3)
	{
		mt_putstr_fd(ARG_ERR, STDERR_FILENO);
		return (0);
	}
	while (av[2][len])
		len++;
	serv_pid = mt_atopid(av[1]);
	mt_send_message(serv_pid, av[2], len);
	return (0);
}
