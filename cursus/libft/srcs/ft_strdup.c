/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:10:37 by ymanchon          #+#    #+#             */
/*   Updated: 2024/03/22 19:47:32 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static unsigned long	ft_strlen_forstrdup(const char *str)
{
	unsigned long	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char			*ret;
	unsigned long	alloc_size;
	unsigned long	i;

	alloc_size = ft_strlen_forstrdup(str);
	ret = (char *)malloc(alloc_size + 1);
	if (!ret)
		return (NULL);
	i = -1;
	while (str[++i])
		ret[i] = str[i];
	ret[i] = '\0';
	return (ret);
}
