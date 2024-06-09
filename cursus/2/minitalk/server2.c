/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:27:11 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/09 18:48:48 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

void	*ft_memset(void *s, int c, unsigned long n)
{
	unsigned char	*ret;
	unsigned long	i;

	ret = (unsigned char *)s;
	i = 0;
	while (i < n)
		ret[i++] = (unsigned char)c;
	return (s);
}
