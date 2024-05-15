#ifndef FT_MALLOC_H
#define FT_MALLOC_H

#include <stdlib.h>

#define TINY		100
#define SMALL		5000
#define LARGE		100000

#define	MAX_ALLOC	100

void	ft_free(void *ptr);
void	*ft_malloc(size_t size);
void	*ft_realloc(void *ptr, size_t size);
void	ft_show_alloc_mem();

#endif