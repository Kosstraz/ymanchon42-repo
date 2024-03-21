/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:10:13 by ymanchon          #+#    #+#             */
/*   Updated: 2024/03/18 20:10:14 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	*ret;

	if (!str)
		return ((void *)0);
	ret = (void *)str;
	while (n-- > 0)
	{
		if (*ret == c)
			return ((void *)ret);
		ret++;
	}
	return ((void *)0);
}