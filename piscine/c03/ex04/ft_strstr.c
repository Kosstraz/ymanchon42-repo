/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:30:17 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/20 21:09:52 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find);

int	find_occurrence(char *str, char *to_find, int i)
{
	int	j;

	j = 0;
	while (to_find[j])
		if (to_find[j++] != str[i++])
			return (0);
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		if (find_occurrence(str, to_find, i))
			return ((str + i));
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	test[] = "Salut comment tu vas mec ?";
	char	find[] = "";

	printf("Find : %s\n", strstr(test, find));
	printf("Find : %s", ft_strstr(test, find));
	return (0);
}*/
