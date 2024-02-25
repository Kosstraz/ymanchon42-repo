/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:36:45 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/12 13:44:50 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
//#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

/*int main()
{
	const int	size = 8;

	char name[] = "0123__;";
	char src[] = "bjigdfgfdzf";
	printf("src : %s\n", src);
	printf("name : %s\n\n", name);

	strncpy(name, src, size);
	printf("src :\t%s\n", src);
	printf("name :\t%s\n\n", name);

	char name2[] = "0123__;";
        char src2[] = "bjigdfgfdzf";
	ft_strncpy(name2, src2, size);
	printf("src :\t%s\n", src2);
	printf("name :\t%s", name2);
}*/
