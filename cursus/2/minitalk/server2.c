/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:27:11 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/10 12:48:22 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

void	*ft_memset(void *s, int c, unsigned long n)
{
	unsigned char	*ret;
	unsigned long	i;

	ret = (unsigned char *)s;
	i = 0;
	while (i < n)
		ret[i++] = (unsigned char)c;
	return (s);
}

void	show_message(unsigned int pid, unsigned char *msg)
{
	ft_printf("Message transmit -> \e[34m%s\e[0m\n", msg);
	kill(pid, SIGUSR2);
	free(msg);
}
