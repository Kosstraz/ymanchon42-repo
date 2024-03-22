/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:04:40 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/12 18:10:28 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int n)
{
	unsigned int	size;
	unsigned int	i;

	size = ft_strlen(dest);
	i = 0;
	while (src[i] && i < n)
		dest[size++] = src[i++];
	dest[size] = '\0';
	return (ft_strlen(src) + n);
}

// Compiler avec -lbsd pour strlcat
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const unsigned int	size = 3;

	char src1[] = "Salut gars !!";
	char dst1[] = "Bonjour les ptits fds esf";

	printf("len :\t%d\n", strlcat(dst1, src1, size));
	printf("src :\t%s\n", src1);
	printf("dest :\t%s\n\n", dst1);

	char src2[] = "Salut gars !!";
	char dst2[] = "Bonjour les ptits fds esf";

	printf("len :\t%d\n", ft_strlcat(dst2, src2, size));
	printf("src :\t%s\n", src2);
	printf("dest :\t%s", dst2);

	return (0);
}/**/
