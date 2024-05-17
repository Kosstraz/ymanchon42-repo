/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:30:17 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/15 16:46:08 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	find_occurence(char *str, char *to_find, int i, int limit)
{
	int	j;

	j = 0;
	while (to_find[j])
	{
		if (to_find[j++] != str[i] || i >= limit)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(char *str, char *to_find, long len)
{
	unsigned int	i;
	
	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] && i < len)
	{
		if (find_occurence(str, to_find, i, len) == 1)
			return ((str + i));
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	test[] = "Salut comment tu vas mec ?";
	char	find[] = "comm";

	printf("Find : %s\n", strnstr(test, find, 10));
	printf("Find ft_ : %s\n", ft_strnstr(test, find, 10));
	return (0);
}*/
