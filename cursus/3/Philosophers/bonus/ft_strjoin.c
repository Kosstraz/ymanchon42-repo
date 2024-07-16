/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:10:42 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/16 16:55:23 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_strlen_join(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char			*ret;
	unsigned long	alloc_size;
	unsigned long	i;

	alloc_size = ft_strlen_join(str);
	ret = (char *)malloc(sizeof(char) * (alloc_size + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strjoin_free(char *s1, const char *s2)
{
	char	*ret;
	int		size1;
	int		size2;
	int		i;
	int		n;

	if (!s1)
		return (ft_strdup(s2));
	size1 = ft_strlen_join(s1);
	size2 = ft_strlen_join(s2);
	ret = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
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
	free(s1);
	return (ret);
}
