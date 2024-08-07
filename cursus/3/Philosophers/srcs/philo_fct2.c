/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fct2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:36:48 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/16 18:22:31 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

inline char	take_her_forks(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		take_one_fork(philo, philo->index + 1);
		if (check_death(philo))
		{
			pthread_mutex_unlock(&philo->d.mutexes[philo->index + 1]);
			return (1);
		}
		take_one_fork(philo, philo->index);
	}
	else
	{
		take_one_fork(philo, philo->index);
		if (check_death(philo))
		{
			pthread_mutex_unlock(&philo->d.mutexes[philo->index]);
			return (1);
		}
		take_one_fork(philo, philo->index + 1);
	}
	return (0);
}

inline void	take_one_fork(t_philo *philo, int mut_i)
{
	pthread_mutex_lock(&philo->d.mutexes[mut_i]);
	printfp(philo, PHILO_TAKENFORK);
}

inline void	drop_forks(t_philo *philo)
{
	if (philo->index % 2 == 1)
	{
		pthread_mutex_unlock(&philo->d.mutexes[philo->index]);
		pthread_mutex_unlock(&philo->d.mutexes[philo->index + 1]);
	}
	else
	{
		pthread_mutex_unlock(&philo->d.mutexes[philo->index + 1]);
		pthread_mutex_unlock(&philo->d.mutexes[philo->index]);
	}
}

inline void	check_must_eat(t_philo *philo, const int eat_needed)
{
	if (philo->args.time_musteat > 0)
	{
		pthread_mutex_lock(philo->mutex_te);
		if (++(*philo->total_eat) == eat_needed)
		{
			pthread_mutex_lock(philo->mutex_d);
			*philo->dead = 1;
			pthread_mutex_unlock(philo->mutex_d);
		}
		pthread_mutex_unlock(philo->mutex_te);
	}
}

inline void	printfp(t_philo *philo, char *msg)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	pthread_mutex_lock(philo->mutex_pf);
	printf("%d %d %s\n", get_msinter(tv, philo->start_time),
		philo->index + 1, msg);
	pthread_mutex_unlock(philo->mutex_pf);
}
