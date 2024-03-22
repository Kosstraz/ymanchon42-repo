/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:10:18 by ymanchon          #+#    #+#             */
/*   Updated: 2024/03/18 20:10:19 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void		*ret;
	char		*v1;
	const char	*v2;

	if (!dest || !src)
		return ((void *)0);
	v1 = (void *)dest;
	v2 = (void *)src;
	ret = v1;
	while (n-- > 0)
		*(v1++) = *(v2++);
	return (ret);
}