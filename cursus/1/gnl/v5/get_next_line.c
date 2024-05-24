#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFER_SIZE 5

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

void	freeN(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*ft_strdup(const char *s);

// free 's2'
char	*ft_strjoin_free(const char *s1, char *s2)
{
	char	*ret;
	int		size1;
	int		size2;
	int		i;
	int		n;

	if (!s2)
		return (ft_strdup(s1));
	//if (!s1)
	//{
		//freeN(&s2);
		//return (ft_strdup(s2));
	//}
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
	freeN(&s2);
	return (ret);
}

char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
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
	bef_size = ft_strlenc(buffer, '\n');
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
	bef_size = ft_strlenc(buffer, '\n');
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

char	*save_line(char **buffer)
{
	char	*a;
	char	*ret;

	subdivstr(*buffer, &ret, &a, '\n');
	*buffer = a;
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*ret;
	int		i;

	ret = NULL;
	/*while (!thereis_nl(buffer))
	{
		ret = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!ret)
			return (NULL);
		ret[0] = '\0';
		i = read(fd, ret, sizeof(char) * BUFFER_SIZE);
		if (!i)
			break ;
		else if (i < 0)
		{
			freeN(&ret);
			freeN(&buffer);
			return (NULL);
		}
		ret[i] = '\0';
		buffer = ft_strjoin_free(ret, buffer);
		freeN(&ret);
	}
	freeN(&ret);
	ret = save_line(&buffer);*/
	//while (!thereis_nl(buffer))
	//{
		ret = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!ret)
			return (NULL);
		i = read(fd, ret, sizeof(char) * BUFFER_SIZE);
		ret[i] = '\0';
		buffer = ft_strjoin_free(ret, buffer);
		//freeN(&ret);
	//}
	freeN(&ret);
	ret = save_line(&buffer);
	return (ret);
}

#define TEST_COUNT 1

int	main(void)
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
	/*char	*test = ft_strdup("fni\nds hfgds\n\n\nmmd,sg\nf");
	char	*bef;
	char	*aft;

	subdivstr(test, &bef, &aft, '\n');
	printf("bef : %s$\n", bef);
	printf("aft : %s$\n", aft);

	freeN(bef);
	freeN(aft);
	freeN(test);*/
	return (0);
}