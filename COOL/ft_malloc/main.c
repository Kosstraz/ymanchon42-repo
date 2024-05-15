#include "ft_malloc.h"
#include <stdio.h>
#include <sys/resource.h>

int	main(void)
{
	int	*ez1 = (int *)ft_malloc(54);
	int	*ez2 = (int *)ft_malloc(43123);
	int	*ez3 = (int *)ft_malloc(543);
	int	*ez4 = (int *)ft_malloc(1);
	int	*ez5 = (int *)ft_malloc(52);
	int	*ez6 = (int *)ft_malloc(0);
	int	*ez7 = (int *)ft_malloc(10235431);

	ft_show_alloc_mem();

	ft_free(ez7);
	ft_free(ez3);
	ft_free(ez2);
	ft_free(ez6);
	ft_free(ez1);
	ft_free(ez4);
	ft_free(ez5);

	ft_show_alloc_mem();
	return (0);
}
