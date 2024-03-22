/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:05:53 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/09 14:10:58 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);

int	ft_letter_is_up(char l)
{
	if (l >= 'A' && l <= 'Z')
		return (1);
	return (0);
}

int	ft_letter_is_low(char l)
{
	if (l >= 'a' && l <= 'z')
		return (1);
	return (0);
}

int	ft_is_numeric(char l)
{
	if (l >= '0' && l <= '9')
		return (1);
	return (0);
}

int	ft_is_alphanum(char l)
{
	if (ft_is_numeric(l))
		return (1);
	if (ft_letter_is_low(l))
		return (1);
	else if (ft_letter_is_up(l))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_alphanum(str[i]))
		{
			if (ft_letter_is_low(str[i]))
			{
				if (i != 0 && !ft_is_alphanum(str[i - 1]))
					str[i] -= 32;
				else if (i == 0)
					str[i] -= 32;
			}
			else if (ft_letter_is_up(str[i]))
			{
				if (i != 0 && ft_is_alphanum(str[i - 1]))
					str[i] += 32;
			}
		}
		i++;
	}
	return (str);
}

/*#include <stdio.h>

int main(void)
{
	char cap[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("cap : %s\n", cap);
	ft_strcapitalize(cap);
	printf("cap : %s", cap);
	return (0);
}*/
