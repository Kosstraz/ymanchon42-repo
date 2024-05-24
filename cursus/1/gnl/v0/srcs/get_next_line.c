/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:17:48 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/16 17:41:30 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../get_next_line.h"

#include <stdio.h>

static void	new_gnl_data(t_gnl_data **gnl_data)
{
	t_gnl_data	*ret;
	ret = (t_gnl_data *)malloc(sizeof(t_gnl_data));
	*gnl_data = ret;
	if (!ret)
		return ;
	ret->data = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(ret->data))
		return ;
	ret->data[0] = '\0';
	ret->seek = 0;
}

static ssize_t	thereis_newline(char *data, ssize_t *seek)
{
	char	nextchar;

	while (data[*seek])
	{
		nextchar = data[*seek];
		if (nextchar == '\n')
			return ((*seek)++);
		(*seek)++;
	}
	(*seek) = 0;
	return (-1);
}

char	*ft_strdup(const char *src, size_t len)
{
	char	*ret;
	size_t	i;

	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static size_t	ft_strlennwat(const char *s, size_t at)
{
	size_t	i;

	i = at;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char	*save_line(char *buffer, const char *gddata, size_t at)
{
	char	*joined;

	joined = ft_strjoin_at(buffer, gddata, at);
	return (joined);
}

char	*ft_strjoin_at(const char *s1, const char *s2, size_t at)
{
	char	*ret;
	int		size1;
	int		size2;
	int		i;
	int		n;

	size1 = ft_strlen(s1);
	size2 = ft_strlennwat(s2, at);
	ret = (char *)malloc(size1 + size2 + 1);
	if (!ret)
		return ((char *)0);
	i = 0;
	n = 0;
	while (s1[i])
		ret[n++] = s1[i++];
	i = at;
	while (s2[i] && s2[i] != '\n')
		ret[n++] = s2[i++];
	ret[n] = '\0';
	return (ret);
}

char	*get_next_line(int fd)
{
	static t_gnl_data	*gd;
	static char			*ret;
	ssize_t				log;

	if (fd < 0)
		return (NULL);
	if (!gd)
	{
		new_gnl_data(&gd);
		if (!gd || !(gd->data))
			return (NULL);
	}
	if (!ret)
		ret = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!ret)
		return (NULL);
	ret[BUFFER_SIZE] = '\0';
	if (gd->seek != 0)
	{
		ret = save_line(ret, gd->data, gd->seek);
		gd->seek = BUFFER_SIZE;
	}
	while (thereis_newline(gd->data, &(gd->seek)) < 0)
	{
		log = read(fd, gd->data, sizeof(char) * BUFFER_SIZE);
		if (log == -1)
		{
			free(gd->data);
			free(ret);
			return (NULL);
		}
		gd->data[log] = '\0';
		ret = save_line(ret, gd->data, gd->seek);
	}
	return (ret);
}
