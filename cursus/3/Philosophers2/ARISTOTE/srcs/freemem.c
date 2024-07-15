#include "Aristote.h"

void	freemem(void **ptr2)
{
	for (int i = 0 ; ptr2[i] ; i++)
		free(ptr2[i]);
	free(ptr2);
}