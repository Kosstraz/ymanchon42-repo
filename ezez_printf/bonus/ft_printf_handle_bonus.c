/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:22:02 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/26 20:57:40 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

void	add_flag(t_flags_info *finfo, char flag)
{
	if (flag == '#')
		finfo->diez = 1;
	else if (flag == ' ')
		finfo->space = 1;
	else if (flag == '+')
		finfo->plus = 1;
}

void	init_flag(t_flags_info *finfo)
{
	finfo->diez = 0;
	finfo->space = 0;
	finfo->plus = 0;
}

int	ft_printf_parse_bonus(const char *msg, int *i, va_list *args)
{
	t_flags_info	finfo;
	char			c;

	init_flag(&finfo);
	while (msg[*i])
	{
		c = msg[*i];
		if (is_flag(c) && !is_lformat(c))
			add_flag(&finfo, c);
		else if (is_lformat(c))
			return (ft_printf_handle_bonus(c, finfo, args));
		else
			break ;
		(*i)++;
	}
	return (0);
}

int	ft_printf_handle_bonus(char c, t_flags_info finfo, va_list *args)
{
	if (c == 'x' || c == 'X')
		return (write(1, "0x", 2), 2);
	else if (c == 'u')
		return (write(1, "+", 1), 1);
	else if ((c == 'i' || c == 'd') && va_arg(*args, int) >= 0)
		return ((*args)--, write(1, "+", 1), 1);
	return (0);
}