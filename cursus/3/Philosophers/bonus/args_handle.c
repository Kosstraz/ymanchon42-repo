/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:38:09 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/15 22:15:18 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

char	valid_args(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < 4)
		if (ft_atoi(av[i++]) <= 0)
			return (0);
	if (ac >= 5)
		if (ft_atoi(av[i++]) < 0)
			return (0);
	return (1);
}

void	take_args(t_args *args, char **av, int ac)
{
	args->n = ft_atoi(av[0]);
	args->dtime = ft_atoi(av[1]);
	args->etime = ft_atoi(av[2]);
	args->stime = ft_atoi(av[3]);
	if (ac >= 5)
		args->time_musteat = ft_atoi(av[4]);
	else
		args->time_musteat = -1;
}
