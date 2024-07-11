/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:36:48 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/11 16:54:43 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	kill_philosopher(t_philo *philo, struct timeval s,
	struct timeval begint)
{
	int	i;

	i = 0;
	printf("%d Philosopher %d is dead\n", get_mseconds(s)
		- get_mseconds(begint), philo->index + 1);
	while (i < philo->args.n)
		pthread_detach(philo[i++ - philo->index].d.threads);
	exit(0);
}

void	pusleep(t_philo *philo, int startt)
{
	struct timeval	s;
	struct timeval	e;

	gettimeofday(&s, NULL);
	e = s;
	while (get_mseconds(e) - get_mseconds(s) <= philo->args.dtime)
	{
		gettimeofday(&e, NULL);
		if (get_mseconds(e) - get_mseconds(s) > philo->args.stime)
			return ;
	}
	//pthread_mutex_lock(&philo->d.mutexes[philo->index]);
	kill_philosopher(philo, e, philo->start_time);
}
