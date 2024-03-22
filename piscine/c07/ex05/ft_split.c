/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:44:37 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/25 10:28:05 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
		if (c == sep[i++])
			return (1);
	return (0);
}

int	ft_calcul_size(char *str, char *sep, int at)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (sep[j])
		{
			if (str[i] == sep[j])
				return (count);
			j++;
		}
		count++;
		i++;
	}
	return (count);
}

int	count_words(char *str, char *sep)
{
	int	words;
	int	i;

	words = 0;
	i = -1;
	while (str[++i])
		if (!is_sep(str[i], sep) && (is_sep(str[i - 1], sep) || i == 0))
			words++;
	return (words);
}

char	*check_flag(int *k, int *flag, int size)
{
	char	*ret;

	*k = 0;
	*flag = 1;
	ret = (char *)malloc(sizeof(char) * size);
	if (!ret)
		return (NULL);
	return (ret);
}

char	**ft_split(char *str, char *sep)
{
	char	**ret;
	int		flag;
	int		i;
	int		k;
	int		l;

	ret = (char **)malloc(sizeof(char *) * count_words(str, sep));
	if (!ret)
		return (NULL);
	flag = 0;
	l = -1;
	i = 0;
	while (str[i])
	{
		while (is_sep(str[i], sep))
		{
			flag = 0;
			i++;
		}
		if (flag == 0)
			ret[++l] = check_flag(&ret, &k, &flag, ft_calcul_size(str, sep, i));
		ret[l][k++] = str[i++];
	}
	return (ret);
}

int	main(void)
{
	char test[] = "Bonjour , ahahahh    !!. fs gf/";
	char	**ez = ft_split(test, ", ");
	int		c = count_words(test, ", ");
	for (int i = 0 ; i < count_words(test, ", ") ; i++)
		printf("$%s$\n", ez[i]);
	return (0);
}
