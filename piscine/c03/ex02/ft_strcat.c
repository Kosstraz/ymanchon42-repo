/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:04:40 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/12 16:22:25 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	size;
	int	i;

	size = ft_strlen(dest);
	i = 0;
	while (src[i])
		dest[size++] = src[i++];
	dest[size] = '\0';
	return (dest);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char src1[] = "Salut gars !!";
	char dst1[] = "Bonjour les ptits fds esf";

	strcat(dst1, src1);
	printf("src :\t%s\n", src1);
	printf("dest :\t%s\n\n", dst1);

	char src2[] = "Salut gars !!";
	char dst2[] = "Bonjour les ptits fds esf";

	ft_strcat(dst2, src2);
	printf("src :\t%s\n", src2);
	printf("dest :\t%s", dst2);

	return (0);
}*/
