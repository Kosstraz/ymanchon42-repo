/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:34:08 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/10 23:21:15 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo, int i)
{
	while ((i == philo->args.n - 1 && (philo[i].d.locked || philo[0].d.locked))
		|| (i != philo->args.n - 1 && (philo[i].d.locked || philo[i + 1].d.locked)))
		;
}

void	kill_philosopher(t_philo *philo, long time, int i)
{
	printf("%ld Philosopher %d is dead\n", time, i);
	pthread_mutex_lock(&philo[i].d.mutexes);
	i = -1;
	while (++i < philo->args.n)
		pthread_detach(philo[i].d.threads[i]);
	exit(0);
}

void	*routine(t_philo philo[MAX_PHILO])
{
	struct timeval	s;
	struct timeval	e;
	suseconds_t		time;
	int				i;

	i = 0;
	while (i < MAX_PHILO && philo[i].launched)
		i++;
	pthread_mutex_lock(&philo[i].d.mutexes);
	philo[i].launched = 1;
	while (1)
	{
		/**/gettimeofday(&s, NULL);
		time = s.tv_usec - philo->start_time;
		printf("%ld Philosopher %d is thinking\n", time, i + 1);
		usleep(philo->args.dtime);
		if ((i == philo->args.n - 1 && (philo[i].d.locked || philo[0].d.locked))
		|| (i != philo->args.n - 1 && (philo[i].d.locked || philo[i + 1].d.locked)))
			kill_philosopher(philo, time, i + 1);
		philo[i].d.locked = 1;
		printf("%ld Philosopher %d is eating\n", time, i + 1);
		usleep(philo->args.etime);
		philo[i].d.locked = 0;
		printf("%ld Philosopher %d is sleeping\n", time, i + 1);
		usleep(philo->args.stime);
	}
	return (NULL);
}

void	philosophers(t_philo philo[MAX_PHILO], t_args args)
{
	struct timeval	tv;
	int				i;

	i = 0;
	gettimeofday(&tv, NULL);
	while (i < args.n)
	{
		philo[i].index = i;
		philo[i].args = args;
		philo[i].d.locked = 0;
		philo[i].start_time = tv.tv_usec;
		philo[i].launched = 0;
		pthread_mutex_init(&philo[i].d.mutexes, NULL);
		i++;
	}
	i = -1;
	while (++i < args.n)
		pthread_create(&philo[i].d.threads[i], NULL, routine, philo);
	i = -1;
	while (++i < args.n)
		pthread_join(philo[i].d.threads[i], NULL);
	i = 0;
	while (i < args.n)
		pthread_mutex_destroy(&philo[i++].d.mutexes);
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
