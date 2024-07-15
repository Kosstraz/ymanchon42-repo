/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:36:48 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/14 23:45:32 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

inline void check_death(t_philo *philo)
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

inline void check_death_with_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_d);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->mutex_d);
		drop_forks(philo);
		pthread_detach(philo->d.threads);
		exit(0);
	}
	pthread_mutex_unlock(philo->mutex_d);
}

inline void taken_fork(t_philo *philo, struct timeval begint, int mut_i)
{
	pthread_mutex_lock(&philo->d.mutexes[mut_i]);
	gettimeofday(&begint, NULL);
	printf(PHILO_TAKENFORK, get_msinter(begint, philo->start_time),
		   philo->index + 1);
}

void kill_philosopher(t_philo *philo, struct timeval begint)
{
	gettimeofday(&begint, NULL);
	pthread_mutex_lock(philo->mutex_d);
	*philo->dead = 1;
	pthread_mutex_unlock(philo->mutex_d);
	printf(PHILO_DIED, get_msinter(begint, philo->start_time),
		   philo->index + 1);
	exit(0);
}

inline void useating(t_philo *philo, struct timeval last_eat, struct timeval begint)
{
	struct timeval e;

	gettimeofday(&begint, NULL);
	printf(PHILO_EATING, get_msinter(begint, philo->start_time), philo->index + 1);
	gettimeofday(&e, NULL);
	while (ms(e) - ms(last_eat) < philo->args.dtime)
	{
		check_death_with_fork(philo);
		gettimeofday(&e, NULL);
		if (ms(e) - ms(last_eat) >= philo->args.etime)
			return;
	}
	kill_philosopher(philo, begint);
}

inline void ussleeping(t_philo *philo, struct timeval last_eat, struct timeval begint)
{
	struct timeval e;

	gettimeofday(&begint, NULL);
	printf(PHILO_SLEEPING, get_msinter(begint, philo->start_time), philo->index + 1);
	gettimeofday(&e, NULL);
	while (ms(e) - ms(last_eat) < philo->args.dtime)
	{
		check_death(philo);
		gettimeofday(&e, NULL);
		if (ms(e) - ms(last_eat) >= philo->args.stime)
			return;
	}
	kill_philosopher(philo, begint);
}
