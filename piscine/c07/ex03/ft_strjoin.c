/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:36:22 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/25 11:58:34 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>



/*int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strslen(char **strs, int count)
{
	int	i;
	int	tot;

	tot = 0;
	i = 0;
	while (i < count)
		tot += ft_strlen(strs[i++]);
	return (tot);
}

void	ft_stradd(char **origin, char *add, int at, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		(*origin)[at + i] = add[i];
}

char	*ft_strjoin(int count, char **strs, char *sep)
{
	char	*ret;
	int		ssep;
	int		s;
	int		i;
	int		j;

	ssep = ft_strlen(sep);
	ret = malloc((ft_strslen(strs, count) + (ssep * (count - 1)) + 1));
	s = 0;
	i = 0;
	while (i < count)
	{
			j = 0;
			while (strs[i][j])
				ret[s++] = strs[i][j++];
			if (i < count - 1)
			{
				ft_stradd(&ret, sep, s, ssep);
				s += ssep;
			}
	}
	ret[s] = '\0';
	return (ret);
}*/



#include <stdio.h>
int	main(int argc, char **argv)
{
	char *strs[4] = {"kdjwejh", "ezez", "bonjour", "Carla t'es trop moche :)"};
	char *ez;
	ez = ft_strjoin(argc, argv, ", " );
	printf("%s", ez);
}
