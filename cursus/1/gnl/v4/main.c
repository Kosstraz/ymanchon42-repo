#include "get_next_line.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define TEST_COUNT 10
#define FILE_TO_TEST "text.txt"

int	main(void)
{
	int fd = open(FILE_TO_TEST, O_RDONLY);
	char	*ret = NULL;
	
	for (int i = 0 ; i++ < TEST_COUNT ;)
	{
		ret = get_next_line(fd);
		printf("\e[31mGNL : %s\e[0m\n", ret);
		free(ret);
	}

	close(fd);
	return (0);
}