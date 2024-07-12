/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:36:48 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/11 22:07:29 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	kill_philosopher(t_philo *philo, struct timeval tv)
{
	int	i;

	i = 0;
	printf("%d Philosopher %d is dead\n", get_msinter(tv, philo->start_time),
		philo->index + 1);
	//*(philo->dead) = 1;
	exit(0);
}

void	pusleep(t_philo *philo, struct timeval s, struct timeval begint, int cancelt)
{
	const int		stime = get_mseconds(s) - cancelt;
	struct timeval	e;

	e = s;
	while (get_mseconds(e) - stime <= philo->args.dtime)
	{
		gettimeofday(&e, NULL);
		if (get_mseconds(e) - get_mseconds(s) > philo->args.stime)
			return ;
	}
	kill_philosopher(philo, begint);
}
