/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:48:32 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/24 19:20:46 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

void	*freen(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}

size_t	ft_strlennl(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (i + 1);
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}


char	*ft_strdup(const char *str)
{
	char			*ret;
	unsigned long	alloc_size;
	unsigned long	i;

	if (!str)
		return (NULL);
	alloc_size = ft_strlen(str);
	ret = (char *)malloc(sizeof(char) * (alloc_size + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (str[++i])
		ret[i] = str[i];
	ret[i] = '\0';
	return (ret);
}

// Free le premier parametre passe : 's1'
char	*ft_strjoin_free(char *s1, const char *s2)
{
	char	*ret;
	size_t	size1;
	size_t	size2;
	size_t	i;
	size_t	n;

	if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
	if (!ret)
		return ((char *)0);
	i = 0;
	n = 0;
	while (s1[i])
		ret[n++] = s1[i++];
	i = 0;
	while (s2[i])
		ret[n++] = s2[i++];
	ret[n] = '\0';
	freen((void **)&s1);
	return (ret);
}

// Retourne le début de la chaîne jusqu'à le retour à la ligne
// Le param 's' se modifiera et effacera la première ligne qu'il contient
char	*save_line(char **s)
{
	char	*ret;

	if (!s || !*s)
		return (NULL);
	ret = takesubstr_until(*s);
	*s = remsubstr_until(*s);
	return (ret);
}

// Renvoie une chaine de tous les caracteres avant le caractere 'c'
// 'c' compris
char	*takesubstr_until(const char *s)
{
	char	*ret;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	size = ft_strlennl(s);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

// Renvoie une chaine de tous les caracteres apres le caractere 'c'
// 'c' non compris
char	*remsubstr_until(char *s)
{
	char	*ret;
	size_t	sizeuntil;
	size_t	size;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	sizeuntil = ft_strlennl(s);
	size = ft_strlen(s);
	len = size - sizeuntil;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (sizeuntil < size)
		ret[i++] = s[sizeuntil++];
	ret[i] = '\0';
	freen((void **)&s);
	return (ret);
}

char	thereisnl(const char *s)
{
	size_t	i;

	if (!s || !s[0])
		return (0);
	i = 0;
	while (s[i])
		if (s[i++] == '\n')
			return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*ret;
	ssize_t	i;

	if (fd < 0 || read(fd, 0, 0))
		return (freen((void **)&buffer));
	ret = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!ret)
		return (NULL);
	ret[0] = '\0';
	i = 0;
	while (!thereisnl(buffer))
	{
		i = read(fd, ret, BUFFER_SIZE);
		if (!i && buffer) // && ret[0]
		{
			if (ret[0])			//
			{
				freen((void **)&buffer);
				return (ret);	//
			}
			freen((void **)&ret);
			ret = ft_strdup(buffer);
			return (ret);
		}
		else if (!i)
		{
			freen((void **)&buffer);
			return (freen((void **)&ret));
		}
		ret[i] = '\0';
		buffer = ft_strjoin_free(buffer, ret);
	}
	freen((void **)&ret);
	ret = save_line(&buffer);
	return (ret);
}
