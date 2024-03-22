/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:10:32 by ymanchon          #+#    #+#             */
/*   Updated: 2024/03/18 20:10:33 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	count_words(const char *s, char sep)
{
	int	words;
	int	i;

	words = 0;
	i = -1;
	while (s[++i])
		if ((s[i - 1] == sep || i == 0) && s[i] != sep)
			words++;
	return (words);
}

static char	*ft_strdup(const char *s, char sep, int *start)
{
	char	*ret;
	int		tmp;
	int		i;

	tmp = *start;
	while (s[*start] && s[*start] != sep)
		(*start)++;
	ret = (char *)malloc((*start) - tmp + 1);
	if (!ret)
		return ((void *)0);
	ret[(*start) - tmp] = '\0';
	i = 0;
	while (tmp < *start)
		ret[i++] = s[tmp++];
	return (ret);
}

char	**ft_split(const char *s, char sep)
{
	char	**ret;
	int		size;
	int		i;
	int		j;

	if (!s || !s[0])
		return ((void *)0);
	size = count_words(s, sep);
	ret = (char **)malloc(sizeof(char *) * size + 1);
	if (!ret)
		return ((void *)0);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == sep)
			i++;
		if (!s[i])
			break ;
		ret[j] = ft_strdup(s, sep, &i);
		if (!ret[j++])
			return (NULL);
	}
	ret[j] = ((void *)0);
	return (ret);
}
