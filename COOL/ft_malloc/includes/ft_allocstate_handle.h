#ifndef FT_ALLOCSTATE_HANDLE_H
#define FT_ALLOCSTATE_HANDLE_H

#include "ft_struct_malloc.h"

void			ft_allocaddnew(size_t addr_start, size_t addr_end, size_t msize, t_allocstate **where);
void			ft_allocremove(t_allocstate *node, t_allocstate **remhere);
t_allocstate	*ft_find_allocp(size_t ptr, t_allocstate *findin);

#endif