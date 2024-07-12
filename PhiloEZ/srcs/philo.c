/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:34:08 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/12 18:12:13 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo, struct timeval last_eat,
		struct timeval begint, int i)
{
	struct timeval	think;

	printf(PHILO_THINKING, get_msinter(begint, philo->start_time), i + 1);
	if (i % 2 == 0)
	{
		take_fork(philo, begint, i);
		gettimeofday(&think, NULL);
		if (get_mseconds(think) - get_mseconds(last_eat) > philo->args.dtime
			|| philo->args.n == 1)
			kill_philosopher(philo, begint);
		take_fork(philo, begint, i + 1);
	}
	else
	{
		take_fork(philo, begint, i + 1);
		gettimeofday(&think, NULL);
		if (get_mseconds(think) - get_mseconds(last_eat) > philo->args.dtime
			|| philo->args.n == 1)
			kill_philosopher(philo, begint);
		take_fork(philo, begint, i);
	}
	gettimeofday(&think, NULL);
	if (get_mseconds(think) - get_mseconds(last_eat) > philo->args.dtime
		|| philo->args.n == 1)
		kill_philosopher(philo, begint);
}

void	*routine(t_philo philo[MAX_PHILO])
{
	struct timeval	s;
	struct timeval	begint;
	int				time;
	int				i;

	i = philo->index;
	gettimeofday(&s, NULL);
	while (1)
	{
		gettimeofday(&begint, NULL);
		time = get_msinter(begint, philo->start_time);
		thinking(philo, s, begint, i);
		printf(PHILO_EATING, time, i + 1);
		usleep(philo->args.etime * 1000);
		gettimeofday(&s, NULL);
		pthread_mutex_unlock(&philo->d.mutexes[i]);
		pthread_mutex_unlock(&philo->d.mutexes[i + 1]);
		printf(PHILO_SLEEPING, time, i + 1);
		pusleep(philo, s, begint);
	}
	return (NULL);
}

void	philosophers(t_philo philo[MAX_PHILO], t_args args)
{
	t_fork			mutexes[MAX_PHILO + 1];
	struct timeval	start_time;
	int				i = 0;

	//init_struct_philo(philo, mutexes, args);
	init_mutex(mutexes, args.n);
	gettimeofday(&start_time, NULL);
	while (i < args.n)
	{
		philo[i].index = i;
		philo[i].args = args;
		philo[i].start_time = start_time;
		philo[i].d.mutexes = mutexes;
		i++;
	}
	i = -1;
	while (++i < args.n)
		pthread_create(&philo[i].d.threads, NULL, routine, &philo[i]);
	i = 0;
	while (i < args.n)
	{
		pthread_join(philo[i].d.threads, NULL);
		i++;
	}
	i = 0;
	while (i < args.n)
	{
		pthread_mutex_destroy(&philo[i].d.mutexes[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_args	args;
	t_philo	philo[MAX_PHILO];

	if (ac < 5)
		printf(INVALID_ARGS);
	else
	{
		if (!valid_args(ac - 1, &av[1]))
			return (printf(NEGATIVE_NUMBER), 0);
		take_args(&args, &av[1]);
		philosophers(philo, args);
	}
	return (0);
}
