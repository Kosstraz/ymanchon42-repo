/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:36:48 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/12 18:11:51 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

inline void	take_fork(t_philo *philo, struct timeval begint, int mut_i)
{
	printf(PHILO_TAKENFORK, get_msinter(begint, philo->start_time),
		philo->index + 1);
	pthread_mutex_lock(&philo->d.mutexes[mut_i]);
}

void	kill_philosopher(t_philo *philo, struct timeval tv)
{
	int	i;

	i = 0;
	printf(PHILO_DIED, get_msinter(tv, philo->start_time),
		philo->index + 1);
	exit(0);
}

void	pusleep(t_philo *philo, struct timeval s, struct timeval begint)
{
	const int		stime = get_mseconds(s);
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
