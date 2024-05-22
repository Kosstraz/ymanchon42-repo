#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
	char	*buffer = ft_strdup("dsagdfgfd\nj sjsksf d\nd snk");
	char	*ret = NULL;
	
	
	ret = split_substr_until(&buffer);
	printf("ret : \e[31m%s\e[0m\nbuffer : \e[32m%s\e[0m\n\n\n", ret, buffer);
	free(ret);

	ret = split_substr_until(&buffer);
	printf("ret : \e[31m%s\e[0m\nbuffer : \e[32m%s\e[0m\n\n\n", ret, buffer);
	free(ret);

	ret = split_substr_until(&buffer);
	printf("ret : \e[31m%s\e[0m\nbuffer : \e[32m%s\e[0m\n\n\n", ret, buffer);
	free(ret);

	ret = split_substr_until(&buffer);
	printf("ret : \e[31m%s\e[0m\nbuffer : \e[32m%s\e[0m\n\n\n", ret, buffer);
	free(ret);

	ret = split_substr_until(&buffer);
	printf("ret : \e[31m%s\e[0m\nbuffer : \e[32m%s\e[0m\n\n\n", ret, buffer);
	free(ret);

	ret = split_substr_until(&buffer);
	printf("ret : \e[31m%s\e[0m\nbuffer : \e[32m%s\e[0m\n\n\n", ret, buffer);
	free(ret);
	close(fd);
	/*int fd = open("text.txt", O_RDONLY);
	char	*gnl;

	gnl = get_next_line(fd);
	printf("\e[31mGNL :\e[0m $\e[31m%s\e[0m$\n", gnl);
	free(gnl);
	
	gnl = get_next_line(fd);
	printf("\e[31mGNL :\e[0m $\e[31m%s\e[0m$\n", gnl);
	free(gnl);

	gnl = get_next_line(fd);
	printf("\e[31mGNL :\e[0m $\e[31m%s\e[0m$\n", gnl);
	free(gnl);

	gnl = get_next_line(fd);
	printf("\e[31mGNL :\e[0m $\e[31m%s\e[0m$\n", gnl);
	free(gnl);

	gnl = get_next_line(fd);
	printf("\e[31mGNL :\e[0m $\e[31m%s\e[0m$\n", gnl);
	free(gnl);

	gnl = get_next_line(fd);
	printf("\e[31mGNL :\e[0m $\e[31m%s\e[0m$\n", gnl);
	free(gnl);

	gnl = get_next_line(fd);
	printf("\e[31mGNL :\e[0m $\e[31m%s\e[0m$\n", gnl);
	free(gnl);

	gnl = get_next_line(fd);
	printf("\e[31mGNL :\e[0m $\e[31m%s\e[0m$\n", gnl);
	free(gnl);

	gnl = get_next_line(fd);
	printf("\e[31mGNL :\e[0m $\e[31m%s\e[0m$\n", gnl);
	//free(gnl);

	gnl = get_next_line(fd);
	printf("\e[31mGNL :\e[0m $\e[31m%s\e[0m$\n", gnl);

	gnl = get_next_line(fd);
	printf("\e[31mGNL :\e[0m $\e[31m%s\e[0m$\n", gnl);
	*/

	/*char	*ez = ft_strdup("dsbdgf\ndh\ngfdhdsafkjs gfgndfk\ngdf");

	ez = takesubstr_until(ez);
	printf("%s\n\n", ez);
	ez = remsubstr_until(ez);
	printf("%s\n\n\n", ez);
	ez = remsubstr_until(ez);
	printf("%s\n\n\n", ez);
	ez = remsubstr_until(ez);
	printf("%s\n\n\n", ez);
	ez = remsubstr_until(ez);
	printf("%s\n\n\n", ez);

	free(ez);*/
	close(fd);
	return (0);
}