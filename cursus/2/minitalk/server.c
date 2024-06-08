/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:57:05 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/08 19:55:01 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"

#include <stdio.h>
#include <stdlib.h>

static unsigned long long	v;
static unsigned int		i;

void	addb_one()
{
	v |= ((__LONG_MAX__ & 0x1) << i++);
	//v |= ((v | 0x1) << i--);
	printf("1");
}

void	addb_zero()
{
	v |= ((v & 0x0) << i++);
	//v |= ((v & 0x0) << i--);
	printf("0");
}

void	print()
{
	printf("\n%llu\n", v);
	printf("%p\n", (unsigned char *)v);
	printf("%s\n", (unsigned char *)v);
	exit(0);
}

void	recept_message()
{
	signal(SIGUSR1, addb_zero);
	signal(SIGUSR2, addb_one);
	signal(SIGINT, print);
}

int	main(void)
{
	int	pid;

	i = 0;
	v = 0;
	pid = getpid();
	ft_printf("ID du processus : %d\n", pid);
	while (1)
		recept_message();
	return (0);
}
