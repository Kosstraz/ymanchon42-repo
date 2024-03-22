/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:10:55 by ymanchon          #+#    #+#             */
/*   Updated: 2024/03/18 20:10:56 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t n)
{
	char	*ret;
	int		i;

	if (n - start == 0)
		ret = (char *)malloc(1);
	else
		ret = (char *)malloc(n - start);
	if (!ret)
		return ((char *)0);
	i = 0;
	while (s[start] && start < n)
		ret[i++] = s[start++];
	ret[i] = '\0';
	return (ret);
}