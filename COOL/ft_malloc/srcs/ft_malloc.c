#include "../ft_malloc.h"
#include "../includes/ft_allocstate_handle.h"
#include "../includes/ft_struct_malloc.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/resource.h>

static t_allocstate	*alloc_infos;

void	ft_free(void *ptr)
{
	//size_t			alloc_size;			UNUSED
	t_allocstate	*to_free;

	to_free = ft_find_allocp((size_t)ptr, alloc_infos);
	if (!to_free)
	{
		perror("ft_free::invalid_pointer :(\n");
		return ;
	}
	if (munmap(ptr, to_free->msize) == -1)
		perror("ft_free::failed :(");
	ft_allocremove(to_free, &alloc_infos);
	to_free = NULL;
}

void	*ft_malloc(size_t size)
{
	struct rlimit	rlim;
	getrlimit(RLIMIT_DATA, &rlim);
	if (size <= 0 || size >= rlim.rlim_max)
		return (NULL);
	
	void	*ret;
	void	*ret_end;
	size_t	ret_size;
	
	ret_size = size;
	ret = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (!ret)
		return (NULL);
	ret_end = ret;
	while (size-- > 0)
		ret_end++;
	
	ft_allocaddnew((size_t)ret, (size_t)ret_end, ret_size, &alloc_infos);
	return (ret);
}

void	*ft_realloc(void *ptr, size_t size)
{
	//size_t			alloc_size;				UNUSED
	t_allocstate	*to_realloc;
	size_t			to_realloc_start_lu;
	void			*to_realloc_start;
	void			*ret;

	to_realloc = ft_find_allocp((size_t)ptr, alloc_infos);
	to_realloc_start	= (void *)to_realloc->addr_start;
	to_realloc_start_lu	= to_realloc->addr_start;
	while (to_realloc_start_lu != to_realloc->addr_end)
		to_realloc_start_lu++;
	ret = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

		/// FLEMME
	(void)to_realloc_start;
	return (ret);
}

void	ft_show_alloc_mem()
{
	if (!alloc_infos)
	{
		perror("No ft_malloc'ation yet :=)\n");
		return ;
	}

	t_allocstate	*svg;
	svg = alloc_infos;
	while (svg)
	{
		printf("%p - %p : %lu bytes (octets)\n", (void *)svg->addr_start, (void *)svg->addr_end, svg->msize);
		svg = svg->next;
	}
}