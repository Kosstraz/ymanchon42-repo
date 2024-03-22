/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:10:37 by ymanchon          #+#    #+#             */
/*   Updated: 2024/03/18 20:10:38 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*ret;
	int		alloc_size;
	int		i;

	alloc_size = ft_strlen(str);
	ret = (char *)malloc(alloc_size + 1);
	if (!ret)
		return (NULL);
	ret[alloc_size] = '\0';
	i = -1;
	while (str[++i])
		ret[i] = str[i];
	return (ret);
}
