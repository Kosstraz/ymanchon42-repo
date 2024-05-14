/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:10:42 by ymanchon          #+#    #+#             */
/*   Updated: 2024/03/22 20:53:23 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static unsigned long	ft_strlen2(const char *str)
{
	unsigned long	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	int		size1;
	int		size2;
	int		i;
	int		n;

	size1 = ft_strlen2(s1);
	size2 = ft_strlen2(s2);
	ret = (char *)malloc(size1 + size2 + 1);
	if (!ret)
		return ((char *)0);
	i = 0;
	n = 0;
	while (s1[i])
		ret[n++] = s1[i++];
	i = 0;
	while (s2[i])
		ret[n++] = s2[i++];
	ret[n] = '\0';
	return (ret);
}
