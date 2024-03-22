/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:10:35 by ymanchon          #+#    #+#             */
/*   Updated: 2024/03/18 20:10:36 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *str, const char c)
{
	unsigned long	i;

	i = 0;
	if (!str)
		return ((void *)0);
	while (str[i])
		if (str[i++] == c)
			return ((char *)&(str[i - 1]));
	return ((char *)str);
}