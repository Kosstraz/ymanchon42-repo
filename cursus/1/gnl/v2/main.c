#include "get_next_line.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
	char	*ret = NULL;
	
	ret = get_next_line(fd);
	printf("\e[31mGNL : %s\e[0m\n", ret);
	free(ret);

	ret = get_next_line(fd);
	printf("\e[31mGNL : %s\e[0m\n", ret);
	free(ret);

	ret = get_next_line(fd);
	printf("\e[31mGNL : %s\e[0m\n", ret);
	free(ret);

	ret = get_next_line(fd);
	printf("\e[31mGNL : %s\e[0m\n", ret);
	free(ret);

	ret = get_next_line(fd);
	printf("\e[31mGNL : %s\e[0m\n", ret);
	free(ret);

	ret = get_next_line(fd);
	printf("\e[31mGNL : %s\e[0m\n", ret);
	free(ret);

	ret = get_next_line(fd);
	printf("\e[31mGNL : %s\e[0m\n", ret);
	free(ret);

	close(fd);
	return (0);
}