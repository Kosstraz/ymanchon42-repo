/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:09:52 by ymanchon          #+#    #+#             */
/*   Updated: 2024/03/22 19:39:23 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	*ft_memset_forcalloc(void *s, int c, size_t n)
{
	unsigned char	*ret;
	unsigned long	i;

	if (!s)
		return ((void *)0);
	else if (n == 0)
		return (s);
	ret = s;
	i = 0;
	while (i < n)
		ret[i++] = c;
	return ((void *)ret);
}

void	*ft_calloc(size_t nmemb, size_t type_size)
{
	char			*ret;
	unsigned long	size;

	if (nmemb == 0 || type_size == 0)
		return ((void *)0);
	size = nmemb * type_size;
	//if (size < 0)
	//	return ((void *)0);
	ret = malloc(size);
	if (!ret)
		return ((void *)0);
	ft_memset_forcalloc(ret, 0, nmemb);
	return (ret);
}
