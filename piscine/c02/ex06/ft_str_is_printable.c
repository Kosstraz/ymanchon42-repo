/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:28:37 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/12 13:45:35 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str);

//32 = ' '   126 = '~'
int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			return (0);
		i++;
	}
	return (1);
}

/*#include <stdio.h>

int main(void)
{
	char* pr = "";
	int   ret   = ft_str_is_printable(pr);
	printf("is_printable : %d", ret);
	return (0);
}*/
