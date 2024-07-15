/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:36:48 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/15 22:15:18 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

inline void	check_death(t_philo *philo)
{
	sem_wait(philo->mutex_d);
	if (*philo->dead == 1)
	{
		sem_post(philo->mutex_d);
		pthread_detach(philo->d.threads);
		exit(0);
	}
	sem_post(philo->mutex_d);
}

inline void	check_death_with_fork(t_philo *philo)
{
	sem_wait(philo->mutex_d);
	if (*philo->dead == 1)
	{
		sem_post(philo->mutex_d);
		drop_forks(philo);
		pthread_detach(philo->d.threads);
		exit(0);
	}
	sem_post(philo->mutex_d);
}

void	kill_philosopher(t_philo *philo)
{
	printfp(philo, PHILO_DIED);
	sem_wait(philo->mutex_d);
	*philo->dead = 1;
	sem_post(philo->mutex_d);
	exit(0);
}

inline void	useating(t_philo *philo, struct timeval last_eat)
{
	struct timeval	s;
	struct timeval	e;

	printfp(philo, PHILO_EATING);
	gettimeofday(&s, NULL);
	e = s;
	while (ms(e) - ms(last_eat) < philo->args.dtime)
	{
		check_death_with_fork(philo);
		gettimeofday(&e, NULL);
		if (ms(e) - ms(s) >= philo->args.etime)
			return ;
	}
	kill_philosopher(philo);
}

inline void	ussleeping(t_philo *philo, struct timeval last_eat)
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
			return ;
	}
	kill_philosopher(philo);
}
