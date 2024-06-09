/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:56:54 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/09 20:01:46 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

unsigned int	ft_atoui(const char *s)
{
	unsigned int	ret;
	unsigned int	i;

	ret = 0;
	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		ret = ret * 10 + s[i++] - '0';
	return (ret);
}

int	ft_ustrlen(const unsigned char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	send_to(unsigned int sPID, unsigned int obj, unsigned int bytemax)
{
	unsigned int	b;

	(void)sPID;
	b = 0;
	while (b < bytemax)
	{
		if ((obj & 0x1) == 1)
			kill(sPID, SIGUSR2);
		else
			kill(sPID, SIGUSR1);
		obj >>= 1;
		b++;
		usleep(1);
	}
}

void	talk_to(unsigned int sPID, unsigned char *msg)
{
	unsigned int		i;

	i = 0;
	send_to(sPID, getpid(), 32);
	send_to(sPID, ft_ustrlen(msg), 32);
	while (msg[i])
		send_to(sPID, msg[i++], 8);
}

int	main(int ac, char **av)
{
	if (ac <= 2)
	{
		write(2, "Deux arguments doivent respectivement etre \
passes :\nLe PID du serveur et le message a envoyer.\n", 96);
		return (0);
	}
	else if (ac > 3)
		write(2, "Les parametres suivant le second, seront ignores.\n", 51);
	ft_printf("\e[34mID du processus client : %d\e[0m\n", getpid());
	if (av[2][0])
		talk_to(ft_atoui(av[1]), (unsigned char *)av[2]);
	//signal(SIGUSR2, );
	return (0);
}
