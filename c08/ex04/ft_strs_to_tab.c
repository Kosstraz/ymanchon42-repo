/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:01:03 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/24 22:54:17 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *from, const unsigned int size)
{
	char	*ret;
	int		i;

	ret = malloc(size + 1);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (from[i])
	{
		ret[i] = from[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*ret;
	int					size;
	int					i;

	ret = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		size = ft_strlen(av[i]);
		ret[i].size = size;
		ret[i].str = av[i];
		ret[i].copy = ft_strdup(av[i], size);
		if (ret[i].copy == NULL)
			return (NULL);
		i++;
	}
	ret[i].size = 0;
	ret[i].str = NULL;
	ret[i].copy = NULL;
	return (ret);
}
