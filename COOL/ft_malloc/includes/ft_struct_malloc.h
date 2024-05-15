#ifndef FT_STRUCT_MALLOC_H
#define FT_STRUCT_MALLOC_H

#include <stdlib.h>

typedef struct	s_allocstate
{
	size_t				addr_start;
	size_t				addr_end;
	size_t				msize;
	struct s_allocstate	*next;
}	t_allocstate;

#endif