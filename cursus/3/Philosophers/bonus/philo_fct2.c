/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fct2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:36:48 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/16 18:23:04 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

inline char	take_her_forks(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		take_one_fork(philo, philo->index + 1);
		if (check_death(philo))
		{
			sem_post(philo->d.sems[philo->index + 1]);
			return (1);
		}
		take_one_fork(philo, philo->index);
	}
	else
	{
		take_one_fork(philo, philo->index);
		if (check_death(philo))
		{
			sem_post(philo->d.sems[philo->index]);
			return (1);
		}
		take_one_fork(philo, philo->index + 1);
	}
	return (0);
}

inline void	take_one_fork(t_philo *philo, int mut_i)
{
	sem_wait(philo->d.sems[mut_i]);
	printfp(philo, PHILO_TAKENFORK);
}

inline void	drop_forks(t_philo *philo)
{
	if (philo->index % 2 == 1)
	{
		sem_post(philo->d.sems[philo->index]);
		sem_post(philo->d.sems[philo->index + 1]);
	}
	else
	{
		sem_post(philo->d.sems[philo->index + 1]);
		sem_post(philo->d.sems[philo->index]);
	}
}

inline void	check_must_eat(t_philo *philo, const int eat_needed)
{
	if (philo->args.time_musteat > 0)
	{
		sem_wait(philo->sem_te);
		if (++(*philo->total_eat) == eat_needed)
		{
			sem_wait(philo->sem_d);
			*philo->dead = 1;
			sem_post(philo->sem_d);
		}
		sem_post(philo->sem_te);
	}
}

inline void	printfp(t_philo *philo, char *msg)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%d %d %s\n", get_msinter(tv, philo->start_time),
		philo->index + 1, msg);
}
