/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:22:02 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/26 19:48:16 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

char	is_flag(char c)
{
	size_t	i;

	i = 0;
	while (__FLAG_[i])
		if (c == __FLAG_[i++])
			return (1);
	return (0);
}

char	is_lformat(char c)
{
	size_t	i;

	i = 0;
	while (LFORMAT[i])
		if (c == LFORMAT[i++])
			return (1);
	return (0);
}
