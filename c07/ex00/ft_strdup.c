/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:11:05 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/24 18:03:41 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*ret;
	int		size;
	int		i;

	size = ft_strlen(src);
	ret = malloc(size);
	i = 0;
	while (src[i])
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

/*#include <stdio.h>
int	main(int argc, char **argv)
{
	char src[] = "Bonjour !!!";
	char *str = ft_strdup(src);
	printf("%s", str);
	free(str);
}*/
