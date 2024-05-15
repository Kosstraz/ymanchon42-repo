#include "../includes/ft_allocstate_handle.h"
#include <stdio.h>
#include <sys/mman.h>

static void	ft_allocadd(t_allocstate **lst, t_allocstate *new)
{
	new->next = (*lst);
	(*lst) = new;
}

static t_allocstate	*ft_allocnew(size_t addr_start, size_t addr_end, size_t msize)
{
	t_allocstate	*ret;

	ret = mmap(NULL, sizeof(t_allocstate), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (ret == MAP_FAILED)
		return (NULL);
	ret->addr_start	= addr_start;
	ret->addr_end	= addr_end;
	ret->msize		= msize;
	ret->next		= NULL;
	return (ret);
}

void	ft_allocaddnew(size_t addr_start, size_t addr_end, size_t msize, t_allocstate **where)
{
	t_allocstate	*ret;

	ret = ft_allocnew(addr_start, addr_end, msize);
	if (!ret)
	{
		perror("ft_allocaddnew::memory_map_failed :(\n");
		return ;
	}
	ft_allocadd(where, ret);
}

void	ft_allocremove(t_allocstate *node, t_allocstate **remhere)
{
	t_allocstate	*svg;
	
	if (!remhere || !(*remhere))
	{
		perror("ft_allocremove::bad memory_unmap :(\n");
		return ;
	}
	svg = *remhere;
	if (*remhere == node)
	{
		*remhere = (*remhere)->next;
		if (munmap(node, sizeof(t_allocstate)) == -1)
			perror("ft_allocremove::bad memory_unmap :(\n");
		node = NULL;
		return ;
	}
	while (*remhere)
	{
		if ((*remhere)->next == node)
		{
			(*remhere)->next = (*remhere)->next->next;
			if (munmap(node, sizeof(t_allocstate)) == -1)
				perror("ft_allocremove::bad memory_unmap :(\n");
			node = NULL;
			break ;
		}
		(*remhere) = (*remhere)->next;
	}
	*remhere = svg;
}

t_allocstate	*ft_find_allocp(size_t ptr, t_allocstate *findin)
{
	while (findin)
	{
		if (findin->addr_start == ptr)
			return (findin);
		findin = findin->next;
	}
	return (NULL);
}