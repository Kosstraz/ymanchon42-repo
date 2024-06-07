/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:56:54 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/07 19:54:43 by ymanchon         ###   ########.fr       */
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

void	talk_to(unsigned int sPID, const unsigned char *msg)
{
	unsigned long long	ptr;

	ptr = (unsigned long long)msg;
	kill(sPID, SIGUSR2);
}

int	main(int ac, char **av)
{
	if (ac <= 2)
	{
		write(2, "Deux arguments doivent etre passe en argument, le \
premier etant le PID du serveur et le second la chaine de \
caracteres a transmettre.\n", 135);
		return (0);
	}
	else if (ac > 3)
		write(2, "Les parametres suivant le second, seront ignores.\n", 51);
	talk_to(ft_atoui(av[1]), (unsigned char *)av[2]);
	return (0);
}
