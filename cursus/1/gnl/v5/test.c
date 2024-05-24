#include <stdlib.h>

void	freeN(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = (char *)0;
	}
}

int main(void)
{
	char	*ez = malloc(18);
	freeN(&ez);
	if (!ez)
		printf("NULL");
	return (0);
}