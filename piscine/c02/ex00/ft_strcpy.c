/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:36:45 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/10 17:51:40 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
//#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src);

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int main()
{
	char name[] = "0123/\"";
	char src[]  = "bjr55555555555555555555k!k";
	printf("src :\t%s\n", src);
	printf("name :\t%s\n\n", name);

	strcpy(name, src);
	printf("src :\t%s\n", src);
	printf("name :\t%s\n\n", name);
	
	char name2[] = "0123/\"";
	char src2[]  = "bjr55555555!!!k";
	ft_strcpy(name2, src2);
	printf("src :\t%s\n", src2);
	printf("name :\t%s", name2);
}*/
