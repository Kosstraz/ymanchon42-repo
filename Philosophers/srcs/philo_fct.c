/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:36:48 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/13 19:48:33 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

inline void	taken_fork(t_philo *philo, struct timeval begint, int mut_i)
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

inline void	pusleep(t_philo *philo, struct timeval s, struct timeval begint)
{
	const int		stime = ms(s);
	struct timeval	e;

	gettimeofday(&e, NULL);
	while (ms(e) - stime <= philo->args.dtime)
	{
		gettimeofday(&e, NULL);
		if (ms(e) - ms(s) > philo->args.stime)
			return ;
	}
	kill_philosopher(philo, begint);
}
