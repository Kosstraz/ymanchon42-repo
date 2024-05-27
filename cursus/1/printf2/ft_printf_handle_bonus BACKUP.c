/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:15:55 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/27 19:41:27 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

char	is_lformat(char c)
{
	int	i;

	i = 0;
	while (LFORMAT[i])
		if (c == LFORMAT[i++])
			return (1);
	return (0);
}

char	is_flag(char c)
{
	int	i;

	i = 0;
	while (__FLAG_[i])
		if (c == __FLAG_[i++])
			return (1);
	return (0);
}

void	add_flag(t_flags_info *finfo, char c)
{
	if (c == ' ')
		finfo->space = 1;
	if (c == '#')
		finfo->diez = 1;
	if (c == '+')
		finfo->plus = 1;
}

void	init_flag(t_flags_info *finfo)
{
	finfo->diez = 0;
	finfo->plus = 0;
	finfo->space = 0;
	finfo->width = 0;
}

int	ft_printf_parse_bonus(const char *msg, int *i, va_list *args)
{
	t_flags_info	finfo;
	int				tmp;

	tmp = *i;
	init_flag(&finfo);
	while (msg[*i])
	{
		if (is_flag(msg[*i]))
			add_flag(&finfo, msg[*i]);
		else if (is_lformat(msg[*i]))
			return (ft_printf_handle_flags(msg[*i], finfo, args));
		else
			return (*i = tmp, 0);
		(*i)++;
	}
	return (0);
}

int	ft_printf_handle_flags(char c, t_flags_info finfo, va_list *args)
{
	int		count;
	int		va_int;
	va_list	cpy;

	count = 0;
	va_copy(cpy, *args);
	if (c == 'd' || c == 'i')									// int copy
		va_int = va_arg(cpy, int);
	if ((c == 'x' || c == 'X') && finfo.diez && va_arg(cpy, int))// Hexadecimal
		return (ft_putchar('0'), ft_putchar(c), 2);
	else if ((c == 'd' || c == 'i') && finfo.space && va_int >= 0
		&& !finfo.plus)
		count += ft_putchar(' ');
	else if ((c == 'd' || c == 'i') && finfo.plus && va_int >= 0)
		count += ft_putchar('+');
	return (count);
}
