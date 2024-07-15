/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:34:08 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/14 23:45:21 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo, struct timeval last_eat, struct timeval begint, int i)
{
	struct timeval	think;

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
	check_death_with_forks(philo);
	gettimeofday(&think, NULL);
	if (ms(think) - ms(last_eat) > philo->args.dtime
		|| philo->args.n == 1)
	{
		drop_forks(philo);
		kill_philosopher(philo, begint);
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

void	*routine(t_philo philo[MAX_PHILO]);

inline  void	*routine(t_philo philo[MAX_PHILO])
{
	struct timeval	last_eat;
	struct timeval	begint;
	const int		eat_needed = philo->args.n * philo->args.time_musteat;
	int				i;

	i = philo->index;
	gettimeofday(&begint, NULL);
	gettimeofday(&last_eat, NULL);
	while (1)
	{
		thinking(philo, last_eat, begint, i);
		gettimeofday(&last_eat, NULL);
		useating(philo, last_eat, begint);
		check_must_eat(philo, eat_needed);
		check_death(philo);
		drop_forks(philo);
		ussleeping(philo, last_eat, begint);
	}
	return (NULL);
}

void	*routine_cast(void * philo)
{
	return (routine((t_philo *)philo));
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
		pthread_create(&philo[i].d.threads, NULL, &routine_cast, (void *)&philo[i]);
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
