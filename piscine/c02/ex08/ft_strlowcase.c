/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:44:11 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/09 13:04:41 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str);

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = (str[i] + 32);
		i++;
	}
	return (str);
}

/*#include <stdio.h>

int main(void)
{
	char lc[44] = "AsdnejsfnJfndsfesnfSDNFIf2s1fs532042][}{}dP";
	printf("classic : %s\n", lc); 
	ft_strlowcase(lc);
	printf("strupcase : %s", lc);
	return (0);
}*/
