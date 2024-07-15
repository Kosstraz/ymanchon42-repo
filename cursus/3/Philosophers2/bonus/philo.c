/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:34:08 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/15 19:06:25 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo, struct timeval last_eat)
{
	struct timeval	think;

	printfp(philo, PHILO_THINKING);
	check_death(philo);
	take_her_forks(philo);
	gettimeofday(&think, NULL);
	printf("\e[1m \e[31m TEMPS a penser : %d\n \e[0m", ms(think) - ms(last_eat));
	if (ms(think) - ms(last_eat) > philo->args.dtime
		|| philo->args.n == 1)
	{
		drop_forks(philo);
		printf("\e[1m \e[32m MORT EN PENSANT\n \e[0m");
		kill_philosopher(philo);
	}
	check_death_with_fork(philo);
}

inline void	*routine(t_philo philo[MAX_PHILO])
{
	const int		eat_needed = philo->args.n * philo->args.time_musteat;
	struct timeval	last_eat;

	gettimeofday(&last_eat, NULL);
	while (1)
	{
		thinking(philo, last_eat);
		printfp(philo, PHILO_EATING);
		gettimeofday(&last_eat, NULL);
		useating(philo, last_eat);
		drop_forks(philo);
		check_must_eat(philo, eat_needed);
		check_death(philo);
		ussleeping(philo, last_eat);
	}
	return (NULL);
}

void	launch_fork(t_philo philo[MAX_PHILO])
{
	if (fork() == 0)
		routine(philo);
}

void	init_struct_philo(t_philo philo[MAX_PHILO],
		t_fork mutexes[MAX_PHILO + 1], t_args args)
{
	pthread_mutex_t	*mutex_te;
	pthread_mutex_t	*mutex_d;
	pthread_mutex_t	*mutex_pf;
	char			*dead;
	int				*total_eat;
	int				i;

	i = -1;
	init_mutex(mutexes, args.n);
	alloc_all_var(&dead, &total_eat, &mutex_te, &mutex_d);
	mutex_pf = (t_fork *)malloc(sizeof(t_fork));
	if (!mutex_pf)
		return ;
	pthread_mutex_init(mutex_te, NULL);
	pthread_mutex_init(mutex_d, NULL);
	pthread_mutex_init(mutex_pf, NULL);
	gettimeofday(&philo[0].start_time, NULL);
	while (++i < args.n)
	{
		philo[i].mutex_te = mutex_te;
		philo[i].mutex_d = mutex_d;
		philo[i].mutex_pf = mutex_pf;
		philo[i].total_eat = total_eat;
		philo[i].dead = dead;
		philo[i].index = i;
		philo[i].args = args;
		philo[i].start_time = philo[0].start_time;
		philo[i].d.mutexes = mutexes;
		launch_fork(philo);
	}
}

void	philosophers(t_philo philo[MAX_PHILO], t_args args)
{
	t_fork			mutexes[MAX_PHILO + 1];
	int				i;

	init_struct_philo(philo, mutexes, args);
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
