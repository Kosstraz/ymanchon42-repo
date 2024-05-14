/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:54:45 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/13 16:10:58 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char			*res;
	unsigned int	size;
	unsigned int	i;

	if (!str)
		return (NULL);
	i = -1;
	size = ft_strlen(str);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	res[size] = '\0';
	while (++i < size)
		res[i] = str[i];
	return (res);
}

/*int main()
{
	char	*ez = "dadwa dsa defs";
	printf("%s\n%s\n", strdup(ez), ft_strdup(ez));
}*/
