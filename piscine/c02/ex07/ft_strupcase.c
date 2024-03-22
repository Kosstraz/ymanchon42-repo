/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:36:25 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/09 12:43:14 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str);

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = (str[i] - 32);
		i++;
	}
	return (str);
}

/*#include <stdio.h>

int main(void)
{
	char sc[44] = "AsdnejsfnJfndsfesnfSDNFIf2s1fs532042][}{}dP";
	printf("classic : %s\n", sc); 
	ft_strupcase(sc);
	printf("strupcase : %s", sc);
	return (0);
}*/
