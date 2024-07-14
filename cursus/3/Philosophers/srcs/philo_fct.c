/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:36:48 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/14 18:40:34 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

inline void	check_death(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_d);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->mutex_d);
		pthread_detach(philo->d.threads);
		exit(0);
	}
	pthread_mutex_unlock(philo->mutex_d);
}

inline void	taken_fork(t_philo *philo, struct timeval begint, int mut_i)
{
	gettimeofday(&begint, NULL);
	printf(PHILO_TAKENFORK, get_msinter(begint, philo->start_time),
			philo->index + 1);
	pthread_mutex_lock(&philo->d.mutexes[mut_i]);
}

void	kill_philosopher(t_philo *philo, struct timeval begint)
{
	int	i;

	i = 0;
	gettimeofday(&begint, NULL);
	pthread_mutex_lock(philo->mutex_d);
	*philo->dead = 1;
	pthread_mutex_unlock(philo->mutex_d);
	printf(PHILO_DIED, get_msinter(begint, philo->start_time),
		philo->index + 1);
	exit(0);
}

inline void	useating(t_philo *philo, struct timeval s, struct timeval begint)
{
	struct timeval	e;

	gettimeofday(&begint, NULL);
	printf(PHILO_EATING, get_msinter(begint, philo->start_time), philo->index + 1);
	gettimeofday(&e, NULL);
	while (ms(e) - ms(s) < philo->args.dtime)
	{
		check_death(philo);
		gettimeofday(&e, NULL);
		if (ms(e) - ms(s) >= philo->args.etime)
			return ;
	}
	kill_philosopher(philo, begint);
}

inline void	ussleeping(t_philo *philo, struct timeval s, struct timeval begint)
{
	struct timeval	e;

	gettimeofday(&begint, NULL);
	printf(PHILO_SLEEPING, get_msinter(begint, philo->start_time), philo->index + 1);
	gettimeofday(&e, NULL);
	while (ms(e) - ms(s) < philo->args.dtime)
	{
		check_death(philo);
		gettimeofday(&e, NULL);
		if (ms(e) - ms(s) >= philo->args.stime)
			return ;
	}
	kill_philosopher(philo, begint);
}
