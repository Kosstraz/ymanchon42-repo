/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:38:09 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/10 14:46:27 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	valid_args(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
		if (ft_atoi(av[i++]) < 0)
			return (0);
	return (1);
}

void	take_args(t_args *args, char **av)
{
	args->n = ft_atoi(av[0]);
	args->dtime = ft_atoi(av[1]);
	args->etime = ft_atoi(av[2]);
	args->stime = ft_atoi(av[3]);
}
