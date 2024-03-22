/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:09:52 by ymanchon          #+#    #+#             */
/*   Updated: 2024/03/18 20:09:53 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*calloc(size_t nmemb, size_t size)
{
	char	*ret;
	int		mult;

	if (nmemb == 0 || size == 0)
		return ((void *)0);
	mult = nmemb * size;
	if (mult < 0)
		return ((void *)0);
	ret = malloc(mult);
	if (!ret)
		return ((void *)0);
	while (size-- > 0)
		*(ret++) = 0;
	return (ret);
}