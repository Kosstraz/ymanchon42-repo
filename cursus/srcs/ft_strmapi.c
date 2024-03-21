/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:10:46 by ymanchon          #+#    #+#             */
/*   Updated: 2024/03/18 20:10:47 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	char				*ret;
	unsigned int		size;
	unsigned int		i;

	size = ft_strlen(str);
	ret = (char *)malloc(size + 1);
	if (!ret)
		return ((void *)0);
	ret[size] = '\0';
	i = 0;
	while (str[i])
	{
		ret[i] = f(i, str[i]);
		i++;
	}
	return (ret);
}