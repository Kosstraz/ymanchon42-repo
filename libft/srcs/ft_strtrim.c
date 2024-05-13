/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:10:53 by ymanchon          #+#    #+#             */
/*   Updated: 2024/03/23 16:54:34 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	is_set(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

static size_t	count_set(const char *s1, const char *set)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s1[i])
		if (is_set(s1[i++], set))
			count++;
	return (count);
}

static unsigned long	ft_strlen2(const char *str)
{
	unsigned long	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*ret;
	int		size;
	int		i;
	int		offset;

	size = ft_strlen2(s1) - count_set(s1, set);
	ret = (char *)malloc(size + 1);
	if (!ret)
		return (NULL);
	offset = 0;
	i = 0;
	while (i < size)
	{
		while (is_set(s1[i + offset], set))
			offset++;
		ret[i] = s1[i + offset];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
