/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:10:55 by ymanchon          #+#    #+#             */
/*   Updated: 2024/03/22 20:45:17 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t n)
{
	char			*ret;
	unsigned long	i;

	if (!s)
		return ((void *)0);
	ret = (char *)malloc(n + 1);
	if (!ret)
		return ((char *)0);
	i = 0;
	while (s[start] && i < n)
		ret[i++] = s[start++];
	ret[i] = '\0';
	return (ret);
}