/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:30:03 by ymanchon          #+#    #+#             */
/*   Updated: 2024/03/22 19:30:03 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *s, int c, size_t n)
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