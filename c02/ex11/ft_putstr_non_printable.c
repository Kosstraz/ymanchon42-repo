/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:33:42 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/14 13:40:28 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_putstr_non_printable(char *str);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{	
		ft_putchar(str[i]);
		i++;
	}
}

char	*ft_convert_print_ith(int a, int b, char *str_hexa)
{
	str_hexa[0] = '\\';
	str_hexa[1] = '0';
	str_hexa[2] = '0';
	str_hexa[3] = '\0';
	if (a <= 9)
		str_hexa[1] = (a + '0');
	else
		str_hexa[1] = ((a - 10) + 'a');
	if (b <= 9)
		str_hexa[2] = (b + '0');
	else
		str_hexa[2] = ((b - 10) + 'a');
	ft_putstr(str_hexa);
	return (str_hexa);
}

char	*ft_ith(char c)
{
	char	ret[4];
	char	i;
	char	j;

	i = 0;
	while (i <= 16)
	{
		j = 0;
		while (j <= 15)
		{
			if ((16 * i + j) == c)
				return (ft_convert_print_ith(i, j, ret));
			j++;
		}
		i++;
	}
	return (0);
}		

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			ft_ith(str[i]);
		else
			ft_putchar(str[i]);
		i++;
	}
	if (str[i] == '\0')
		ft_ith(str[i]);
}

int	main()
{
	char test[] = "Coucou\ntu vas bien ?";
	printf("%s\n", test);
	ft_putstr_non_printable(test);
	return (0);
}
