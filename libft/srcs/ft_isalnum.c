/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:09:55 by ymanchon          #+#    #+#             */
/*   Updated: 2024/03/22 19:41:16 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_isupper2(int c)
{
	return (c >= 'A' && c <= 'Z');
}

static int	ft_islower2(int c)
{
	return (c >= 'a' && c <= 'z');
}

static int	ft_isalpha2(int c)
{
	return (ft_isupper2(c) || ft_islower2(c));
}

int	ft_isalnum(int c)
{
	return (ft_isalpha2(c) || (c >= '0' && c <= '9'));
}