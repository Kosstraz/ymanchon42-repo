/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:10:32 by ymanchon          #+#    #+#             */
/*   Updated: 2024/03/22 21:29:33 by ymanchon         ###   ########.fr       */
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

static char	*ft_strdup_forsplit(const char *s, char sep, unsigned long *start)
{
	char			*ret;
	unsigned long	size;
	unsigned long	i;

	size = 0;
	while (s[(*start) + size] && s[(*start) + size] != sep)
		size++;
	ret = (char *)malloc(size + 1);
	if (!ret)
		return ((void *)0);
	i = 0;
	while (i < size)
	{
		ret[i] = s[(*start) + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	**ft_split(const char *s, char sep)
{
	char			**ret;
	unsigned long	size;
	unsigned long	i;
	unsigned long	j;

	if (!s)	
		return ((void *)0);
	size = count_words(s, sep);
	ret = (char **)malloc(size + 1);
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
		ret[j] = ft_strdup_forsplit(s, sep, &i);
		if (!ret[j++])
			return (NULL);
	}
	ret[j] = ((char *)0);
	return (ret);
}
/*
int	main()
{
	char **ez = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", ' ');

	printf("------------------------\n");
	for (unsigned long i = 0 ; ez[i] ; i++)
		printf("$%s$\n", ez[i]);

	    // Libérer la mémoire allouée pour chaque chaîne
    for (unsigned long i = 0; ez[i]; i++)
        free(ez[i]);
    // Libérer la mémoire allouée pour le tableau
    free(ez);

}*/