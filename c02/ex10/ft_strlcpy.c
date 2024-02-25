/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:36:45 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/12 17:06:19 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
//#include <stdlib.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int n);

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	if (n == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < (n - 1) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (n != 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}

//Utiliser la librairie -lbsd pour compiler et tester avec le main()
/*int main()
{
	char name[] = "0123__;47";
	char src[]  = "bjggg1234abcd";
	printf("src :\t%s\n", src);
	printf("name :\t%s\n\n", name);


	printf("len :\t%d\n", strlcpy(name, src, 1));
	printf("src :\t%s\n", src);
	printf("name :\t%s\n\n", name);

	char name2[] = "0123__;47";
        char src2[]  = "bjggg1234abcd";

	printf("len :\t%d\n", ft_strlcpy(name2, src2, 1));
	printf("src :\t%s\n", src2);
	printf("name :\t%s", name2);
}*/
