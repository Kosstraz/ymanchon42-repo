/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:20:19 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/19 15:17:33 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_char_swap(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	char	v1;
	char	v2;

	v1 = *s1;
	v2 = *s2;
	while (v1 == v2)
	{
		v1 = *s1++;
		v2 = *s2++;
		if (!v1)
			return (v1 - v2);
	}
	return (v1 - v2);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (i < argc - 1)
	{
		j = 1;
		while (j < argc - 1)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
				ft_char_swap(&argv[j], &argv[j + 1]);
			j++;
		}
		i++;
	}
	k = 1;
	while (k < argc)
	{
		write(1, argv[k], ft_strlen(argv[k]));
		k++;
		write(1, "\n", 1);
	}
	return (0);
}
