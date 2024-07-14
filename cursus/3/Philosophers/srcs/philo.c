/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:34:08 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/14 18:50:05 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo, struct timeval last_eat, struct timeval begint, int i)
{
	struct timeval	think;

	check_death(philo);
	gettimeofday(&begint, NULL);
	printf(PHILO_THINKING, get_msinter(begint, philo->start_time), i + 1);
	if (i % 2 == 0)
	{
		taken_fork(philo, begint, i);
		taken_fork(philo, begint, i + 1);
	}
	else
	{
		taken_fork(philo, begint, i + 1);
		taken_fork(philo, begint, i);
	}
	check_death(philo);
	gettimeofday(&think, NULL);
	if (ms(think) - ms(last_eat) > philo->args.dtime
		|| philo->args.n == 1)
	{
		drop_forks(philo);
		kill_philosopher(philo, begint);
	}
}

void	*routine(t_philo philo[MAX_PHILO])
{
	struct timeval	s;
	struct timeval	begint;
	int				i;

	i = philo->index;
	gettimeofday(&s, NULL);
	begint = s;
	while (1)
	{
		thinking(philo, s, begint, i);
		useating(philo, s, begint);
		pthread_mutex_lock(philo->mutex_te);
		pthread_mutex_lock(philo->mutex_d);
		if (philo->args.time_musteat > 0)
			if (++(*philo->total_eat) == philo->args.n * philo->args.time_musteat)
				*philo->dead = 1;
		pthread_mutex_unlock(philo->mutex_d);
		pthread_mutex_unlock(philo->mutex_te);
		check_death(philo);
		gettimeofday(&s, NULL);
			// DROP forks
		pthread_mutex_unlock(&philo->d.mutexes[i]);
		pthread_mutex_unlock(&philo->d.mutexes[i + 1]);
			// sleeping
		ussleeping(philo, s, begint);
	}
	return (NULL);
}

void	init_struct_philo(t_philo philo[MAX_PHILO],
		t_fork mutexes[MAX_PHILO + 1], t_args args)
{
	pthread_mutex_t	*mutex_te;
	pthread_mutex_t	*mutex_d;
	char			*dead;
	int				*total_eat;
	int				i;

	i = 0;
	init_mutex(mutexes, args.n);
	alloc_all_var(&dead, &total_eat, &mutex_te, &mutex_d);
	pthread_mutex_init(mutex_te, NULL);
	pthread_mutex_init(mutex_d, NULL);
	gettimeofday(&philo[0].start_time, NULL);
	while (i < args.n)
	{
		philo[i].mutex_te = mutex_te;
		philo[i].mutex_d = mutex_d;
		philo[i].total_eat = total_eat;
		philo[i].dead = dead;
		philo[i].index = i;
		philo[i].args = args;
		philo[i].start_time = philo[0].start_time;
		philo[i].d.mutexes = mutexes;
		i++;
	}
}

void	philosophers(t_philo philo[MAX_PHILO], t_args args)
{
	t_fork			mutexes[MAX_PHILO + 1];
	int				i;

	init_struct_philo(philo, mutexes, args);
	i = -1;
	while (++i < args.n)
		pthread_create(&philo[i].d.threads, NULL, routine, &philo[i]);
	i = 0;
	while (i < args.n)
		pthread_join(philo[i++].d.threads, NULL);
	i = -1;
	while (++i < args.n)
		pthread_mutex_destroy(&philo[i].d.mutexes[i]);
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
		take_args(&args, &av[1], ac - 1);
		if (args.time_musteat != 0)
			philosophers(philo, args);
	}
	return (0);
}
