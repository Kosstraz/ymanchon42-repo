/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:09:31 by ymanchon          #+#    #+#             */
/*   Updated: 2024/03/21 15:50:52 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_libprintf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

static void	ft_printf_handle(const char *msg, va_list *args, int *i)
{
	char	c;

	(*i)++;
	c = msg[(*i)];
	if (c == 'i' || c == 'd' || c == 'c')
		ft_putnbr(va_arg(*args, int));
	else if (c == 's')
		ft_putstr(va_arg(*args, char *));
	else if (c == 'p')
		ft_puthexa(ft_addth(va_arg(*args, const void *), "0123456789abcdef"));
	else if (c == 'x')
		ft_puthexa(ft_ith(va_arg(*args, int), "0123456789abcdef"));
	else if (c == 'X')
		ft_puthexa(ft_ith(va_arg(*args, int), "0123456789ABCDEF"));
	else
		ft_putchar('%');
}

int	ft_printf(const char *msg, ...)
{
	int			i;

	va_list args;
	va_start(args, msg);
	i = 0;
	while (msg[i])
	{
		if (msg[i] != '%')
			ft_putchar(msg[i]);
		else
			ft_printf_handle(msg, &args, &i);
		i++;
	}
	va_end(args);
	return (0);
}