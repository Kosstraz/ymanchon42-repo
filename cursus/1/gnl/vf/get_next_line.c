#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

// @param buffer la chaine qui sera analysee
// @param bef ptr sur chaine qui contiendra tout avant 'c' ('c' compris)
// @param aft ptr sur chaine qui contiendra tout apres 'c' ('c' non compris)
void	subdivstr(const char *buffer, char **bef, char **aft, char c);
char	*subdivstr_aft(const char *buffer, char c);
char	*subdivstr_bef(const char *buffer, char c);

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlenc(const char *str, char c)
{
	size_t	i;

	if (!str)
		return (0);
	else if (c == '\0')
		return (ft_strlen(str));
	i = 0;
	while (str[i])
		if (str[i++] == c)
			return (i);
	return (i);
}

void	*freeN(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}

char	*ft_strdup(const char *s);

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	int		size1;
	int		size2;
	int		i;
	int		n;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
	if (!ret)
		return (NULL);
	i = 0;
	n = 0;
	while (s1[i])
		ret[n++] = s1[i++];
	i = 0;
	while (s2[i])
		ret[n++] = s2[i++];
	ret[n] = '\0';
	return (ret);
}

char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	alloc_size;
	size_t	i;

	alloc_size = ft_strlen(s);
	ret = (char *)malloc(sizeof(char) * (alloc_size + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (s[++i])
		ret[i] = s[i];
	ret[i] = '\0';
	return (ret);
}

void	subdivstr(const char *buffer, char **bef, char **aft, char c)
{
	char	*b;
	char	*a;

	b = subdivstr_bef(buffer, c);
	a = subdivstr_aft(buffer, c);
	if (bef)
		*bef = b;
	else
		freeN(&b);
	if (aft)
		*aft = a;
	else
		freeN(&a);
}

char	*subdivstr_aft(const char *buffer, char c)
{
	size_t	i;
	size_t	bef_size;
	size_t	aft_size;
	char	*ret;

	if (!buffer)
		return (NULL);
	bef_size = ft_strlenc(buffer, c);
	aft_size = ft_strlen(buffer) - bef_size;
	ret = (char *)malloc(sizeof(char) * (aft_size + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (buffer[bef_size])
		ret[i++] = buffer[bef_size++];
	ret[i] = '\0';
	return (ret);
}

char	*subdivstr_bef(const char *buffer, char c)
{
	size_t	i;
	size_t	bef_size;
	char	*ret;

	if (!buffer)
		return (NULL);
	bef_size = ft_strlenc(buffer, c);
	ret = (char *)malloc(sizeof(char) * (bef_size + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < bef_size)
	{
		ret[i] = buffer[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	thereis_nl(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		if (s[i++] == '\n')
			return (1);
	return (0);
}

char	*save_line(const char *buffer)
{
	char	*ret;

	ret = subdivstr_bef(buffer, '\n');
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*tmp;
	char		*ret;
	int			i;

	ret = NULL;
	if (read(fd, 0, 0) < 0 || fd < 0)
		return (freeN(&buffer));
	while (!thereis_nl(buffer))
	{
		ret = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!ret)
			return (freeN(&buffer));
		i = read(fd, ret, sizeof(char) * BUFFER_SIZE);
		ret[i] = '\0';
		if (!i && buffer)
		{
			freeN(&ret);
			ret = save_line(buffer);
			tmp = buffer;
			buffer = subdivstr_aft(buffer, '\n');
			freeN(&tmp);
			freeN(&buffer);
			return (ret);
		}
		else if (!i)
			return (freeN(&ret));
		tmp = buffer;
		buffer = ft_strjoin(buffer, ret);
		freeN(&tmp);
		freeN(&ret);
	}
	freeN(&ret);
	ret = save_line(buffer);
	tmp = buffer;
	buffer = subdivstr_aft(buffer, '\n');
	freeN(&tmp);
	return (ret);
}

#define TEST_COUNT 9

/*int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
	char *gnl = NULL;

	for (int i = 0; i++ < TEST_COUNT ;)
	{
		gnl = get_next_line(fd);
		printf("\e[31mGNL : %s\e[0m$\n", gnl);
		free(gnl);
	}

	close(fd);
	return (0);
}*/