/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:57:05 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/07 19:55:22 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("ID du processus : %d\n", pid);

	pause();
	return (0);
}
