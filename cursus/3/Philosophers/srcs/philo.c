/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:34:08 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/16 18:19:49 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 0 vivant
// 1 mort
char	thinking(t_philo *philo, struct timeval last_eat)
{
	struct timeval	think;

	printfp(philo, PHILO_THINKING);
	if (check_death(philo))
		return (1);
	if (philo->args.n == 1)
		return (kill_philosopher(philo));
	if (take_her_forks(philo))
		return (1);
	gettimeofday(&think, NULL);
	if (ms(think) - ms(last_eat) > philo->args.dtime)
	{
		drop_forks(philo);
		return (kill_philosopher(philo));
	}
	return (check_death_with_fork(philo));
}

inline void	*routine(t_philo philo[MAX_PHILO])
{
	const int		eat_needed = philo->args.n * philo->args.time_musteat;
	struct timeval	last_eat;

	if (philo->index % 2 == 1)
		usleep(philo->args.etime * 1000);
	gettimeofday(&last_eat, NULL);
	while (1)
	{
		if (thinking(philo, last_eat))
			return (NULL);
		printfp(philo, PHILO_EATING);
		gettimeofday(&last_eat, NULL);
		if (useating(philo, last_eat))
			return (NULL);
		drop_forks(philo);
		check_must_eat(philo, eat_needed);
		if (check_death(philo))
			return (NULL);
		if (ussleeping(philo, last_eat))
			return (NULL);
	}
	return (NULL);
}

char	init_struct_philo(t_philo philo[MAX_PHILO],
		t_fork mutexes[MAX_PHILO + 1], t_args args)
{
	int				i;

	i = -1;
	init_mutex(mutexes, args.n);
	if (alloc_all_var(philo))
		return (1);
	pthread_mutex_init(philo[0].mutex_d, NULL);
	pthread_mutex_init(philo[0].mutex_te, NULL);
	pthread_mutex_init(philo[0].mutex_pf, NULL);
	gettimeofday(&philo[0].start_time, NULL);
	while (++i < args.n)
	{
		philo[i].mutex_te = philo[0].mutex_te;
		philo[i].mutex_d = philo[0].mutex_d;
		philo[i].mutex_pf = philo[0].mutex_pf;
		philo[i].total_eat = philo[0].total_eat;
		philo[i].dead = philo[0].dead;
		philo[i].index = i;
		philo[i].args = args;
		philo[i].start_time = philo[0].start_time;
		philo[i].d.mutexes = mutexes;
		pthread_create(&philo[i].d.threads, NULL, &routine_cast,
			(void *)&philo[i]);
	}
	return (0);
}

void	philosophers(t_philo philo[MAX_PHILO], t_args args)
{
	t_fork			mutexes[MAX_PHILO + 1];
	void			*thread_return;
	int				i;

	i = 0;
	if (init_struct_philo(philo, mutexes, args))
		return ;
	i = 0;
	while (i < args.n)
		pthread_join(philo[i++].d.threads, &thread_return);
	i = -1;
	while (++i < args.n)
		pthread_mutex_destroy(&philo[i].d.mutexes[i]);
	pthread_mutex_destroy(philo->mutex_d);
	pthread_mutex_destroy(philo->mutex_te);
	free(philo->mutex_d);
	free(philo->mutex_te);
	free(philo->mutex_pf);
	free(philo->total_eat);
	free(philo->dead);
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
