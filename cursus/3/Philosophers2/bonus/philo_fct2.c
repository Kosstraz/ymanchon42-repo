/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fct2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:36:48 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/15 22:15:18 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

inline void	take_her_forks(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		take_one_fork(philo, philo->index + 1);
		check_death(philo);
		take_one_fork(philo, philo->index);
	}
	else
	{
		take_one_fork(philo, philo->index);
		check_death(philo);
		take_one_fork(philo, philo->index + 1);
	}
}

inline void	take_one_fork(t_philo *philo, int mut_i)
{
	sem_wait(&philo->d.mutexes[mut_i]);
	printfp(philo, PHILO_TAKENFORK);
}

inline void	drop_forks(t_philo *philo)
{
	if (philo->index % 2 == 1)
	{
		sem_post(&philo->d.mutexes[philo->index]);
		sem_post(&philo->d.mutexes[philo->index + 1]);
	}
	else
	{
		sem_post(&philo->d.mutexes[philo->index + 1]);
		sem_post(&philo->d.mutexes[philo->index]);
	}
}

inline void	check_must_eat(t_philo *philo, const int eat_needed)
{
	if (philo->args.time_musteat > 0)
	{
		sem_wait(philo->mutex_te);
		if (++(*philo->total_eat) == eat_needed)
		{
			sem_wait(philo->mutex_d);
			*philo->dead = 1;
			sem_post(philo->mutex_d);
		}
		sem_post(philo->mutex_te);
	}
}

inline void	printfp(t_philo *philo, char *msg)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%d %d %s\n", get_msinter(tv, philo->start_time),
		philo->index + 1, msg);
}
