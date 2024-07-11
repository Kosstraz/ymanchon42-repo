/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:34:08 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/11 22:11:02 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo, struct timeval v1, struct timeval begint, int i)
{
	struct timeval	think;

	printf("%d Philosopher %d is thinking\n",
		get_msinter(begint, philo->start_time), i + 1);
	pthread_mutex_lock(&philo->d.mutexes[i]);
	pthread_mutex_lock(&philo->d.mutexes[i + 1]);
	gettimeofday(&think, NULL);
	if (get_mseconds(think) - get_mseconds(v1) > philo->args.dtime
		|| philo->args.n == 1)
		kill_philosopher(philo, begint);
}

void	*routine(t_philo philo[MAX_PHILO])
{
	struct timeval	s;
	t_time			cancel;
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
		//if (*(philo->dead))
		//	exit(0);
		printf("%d Philosopher %d is eating\n", time, i + 1);
		usleep(philo->args.etime * 1000);
		gettimeofday(&s, NULL);
		//if (*(philo->dead))
		//	exit(0);
		gettimeofday(&cancel.s, NULL);
		pthread_mutex_unlock(&philo->d.mutexes[i]);
		pthread_mutex_unlock(&philo->d.mutexes[i + 1]);
		printf("%d Philosopher %d is sleeping\n", time, i + 1);
		gettimeofday(&cancel.e, NULL);
		pusleep(philo, s, begint, 0);//get_msinter(cancel.e, cancel.s));
	}
	return (NULL);
}

void	init_struct_philo(t_philo philo[MAX_PHILO],
		t_fork mutexes[MAX_PHILO + 1], t_args args)
{
	struct timeval	start_time;
	char			*dead;
	int				i;

	i = 0;
	init_mutex(mutexes, args.n);
	dead = (char *)malloc(sizeof(char));
	if (!dead)
		exit(0);
	*dead = 0;
	gettimeofday(&start_time, NULL);
	while (i < args.n)
	{
		philo[i].dead = dead;
		philo[i].index = i;
		philo[i].args = args;
		philo[i].start_time = start_time;
		philo[i].d.mutexes = mutexes;
		i++;
	}
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
		//philo[i].dead = dead;
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
		pthread_mutex_destroy(&philo[i].d.mutexes[i]);
		i++;
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
