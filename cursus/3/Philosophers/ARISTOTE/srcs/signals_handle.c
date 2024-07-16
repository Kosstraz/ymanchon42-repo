#include "Aristote.h"

void	seghandle_(int signum)
{
	(void)signum;
	printf("%s%s%s%ss\n", BOLD, FORE_RED, SEGFAULT_ALERT, DEFAULT);
	exit(0);
}
