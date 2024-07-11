/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:34:08 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/11 16:49:59 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo, t_time *t, struct timeval begint, int i)
{
	printf("%d Philosopher %d is thinking\n",
		get_mseconds(t->s) - get_mseconds(begint), i + 1);
	gettimeofday(&t->s, NULL);
	pthread_mutex_lock(&philo->d.mutexes[i]);
	pthread_mutex_lock(&philo->d.mutexes[i + 1]);
	gettimeofday(&t->e, NULL);
	if (t->e.tv_usec - t->s.tv_usec > philo->args.dtime || philo->args.n == 1)
		kill_philosopher(philo, t->s, begint);
}

void	*routine(t_philo philo[MAX_PHILO])
{
	t_time			t;
	struct timeval	begint;
	int				time;
	int				i;

	i = philo->index;
	begint = philo->start_time;
	while (1)
	{
		gettimeofday(&t.s, NULL);
		time = get_mseconds(t.s) - get_mseconds(begint);
		thinking(philo, &t, begint, i);
		printf("%d Philosopher %d is eating\n", time, i + 1);
		usleep(philo->args.etime);
		pthread_mutex_unlock(&philo->d.mutexes[i]);
		pthread_mutex_unlock(&philo->d.mutexes[i + 1]);
		printf("%d Philosopher %d is sleeping\n", time, i + 1);
		pusleep(philo, t.s.tv_usec);
	}
	return (NULL);
}

void	philosophers(t_philo philo[MAX_PHILO], t_args args)
{
	t_fork			mutexes[MAX_PHILO + 1];
	struct timeval	tv;
	int				i;

	i = 0;
	gettimeofday(&tv, NULL);
	init_mutex(mutexes, args.n);
	while (i < args.n)
	{
		philo[i].index = i;
		philo[i].args = args;
		philo[i].start_time = tv;
		philo[i].d.mutexes = mutexes;
		i++;
	}
	i = -1;
	while (++i < args.n)
		pthread_create(&philo[i].d.threads, NULL, routine, &philo[i]);
	i = 0;
	while (i < args.n)
		pthread_join(philo[i++].d.threads, NULL);
	i = 0;
	while (i < args.n)
		pthread_mutex_destroy(&mutexes[i++]);
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
