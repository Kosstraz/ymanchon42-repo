/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:56:54 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/08 19:54:41 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <unistd.h>
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

#include <stdio.h>
#include <stdlib.h>

unsigned int	ft_strlen(const unsigned char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

unsigned char *ft_strdup(const unsigned char *s)
{
	unsigned char	*ret;
	unsigned int	i;

	ret = (unsigned char *)malloc(sizeof(unsigned char) * (ft_strlen(s) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	return (ret);
}

void	talk_to(unsigned int sPID, const unsigned char *msg)
{
	unsigned char		*dup;
	unsigned long long	ptr;
	unsigned int		i;

	i = 0;
	dup = ft_strdup(msg);
	ptr = (unsigned long long)dup;
	printf("%p\n", dup);
	while (i < 64)
	{
		if ((ptr & 0x1) == 1)
			kill(sPID, SIGUSR2);
		else
			kill(sPID, SIGUSR1);
		ptr = ptr >> 1;
		i++;
		usleep(1);
	}
	kill(sPID, SIGUSR1);
	pause();
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
	talk_to(ft_atoui(av[1]), (unsigned char *)av[2]);
	return (0);
}
