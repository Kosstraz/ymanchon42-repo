/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:14:45 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/07 16:19:17 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, unsigned int n)
{
	char			*ret;
	unsigned long	alloc_size;
	unsigned long	i;

	alloc_size = ft_strlen(str);
	ret = (char *)malloc(sizeof(char) * (n + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i] && i < n)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
