/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:36:48 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/16 18:03:09 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 0 vivant
// 1 mort
inline char	check_death(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_d);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->mutex_d);
		return (1);
	}
	pthread_mutex_unlock(philo->mutex_d);
	return (0);
}

// 0 vivant
// 1 mort
inline char	check_death_with_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_d);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->mutex_d);
		drop_forks(philo);
		return (1);
	}
	pthread_mutex_unlock(philo->mutex_d);
	return (0);
}

char	kill_philosopher(t_philo *philo)
{
	printfp(philo, PHILO_DIED);
	pthread_mutex_lock(philo->mutex_d);
	*philo->dead = 1;
	pthread_mutex_unlock(philo->mutex_d);
	return (1);
}

inline char	useating(t_philo *philo, struct timeval last_eat)
{
	struct timeval	s;
	struct timeval	e;

	gettimeofday(&s, NULL);
	e = s;
	while (ms(e) - ms(last_eat) < philo->args.dtime)
	{
		check_death_with_fork(philo);
		gettimeofday(&e, NULL);
		if (ms(e) - ms(s) >= philo->args.etime)
			return (0);
	}
	return (kill_philosopher(philo));
}

// 0 vivant
// 1 mort
inline char	ussleeping(t_philo *philo, struct timeval last_eat)
{
	struct timeval	e;
	struct timeval	s;

	printfp(philo, PHILO_SLEEPING);
	gettimeofday(&s, NULL);
	e = s;
	while (ms(e) - ms(last_eat) < philo->args.dtime)
	{
		check_death(philo);
		gettimeofday(&e, NULL);
		if (ms(e) - ms(s) >= philo->args.stime)
			return (0);
	}
	return (kill_philosopher(philo));
}
