/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:42:41 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/10 12:56:18 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

void	recept_signal(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("PID du serveur invalide, ou probleme d'allocation memoire \
dans le serveur :/\n");
	else
		ft_printf("Message transmit avec succes :)\n");
	exit(0);
}
