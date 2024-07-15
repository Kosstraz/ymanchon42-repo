/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:34:08 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/15 22:17:32 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	thinking(t_philo *philo, struct timeval last_eat)
{
	struct timeval	think;

	printfp(philo, PHILO_THINKING);
	check_death(philo);
	take_her_forks(philo);
	gettimeofday(&think, NULL);
	if (ms(think) - ms(last_eat) > philo->args.dtime
		|| philo->args.n == 1)
	{
		drop_forks(philo);
		kill_philosopher(philo);
	}
	check_death_with_fork(philo);
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

void	init_struct_philo(t_philo philo[MAX_PHILO], sem_t sems[MAX_PHILO + 1],
		const char sems_name[MAX_PHILO], int pids[MAX_PHILO])
{
	sem_t	*sem_te;
	sem_t	*sem_d;
	char	*dead;
	int		*total_eat;
	int		i;

	i = -1;
	init_sem(&sems, philo[0].args.n);
	alloc_all_var(&dead, &total_eat, &sem_te, &sem_d);
	sem_open(sem_te, NULL);
	sem_open(sem_d, NULL);
	gettimeofday(&philo[0].start_time, NULL);
	while (++i < philo[0].args.n)
	{
		philo[i].sem_te = sem_te;
		philo[i].sem_d = sem_d;
		philo[i].total_eat = total_eat;
		philo[i].dead = dead;
		philo[i].index = i;
		philo[i].args = philo[0].args;
		philo[i].start_time = philo[0].start_time;
		philo[i].d.sems = sems;
		launch_routine(philo, &pids[i]);
	}
}

void	philosophers(t_philo philo[MAX_PHILO], t_args args)
{
	sem_t		mutexes[MAX_PHILO + 1];
	const char	sems[MAX_PHILO];
	int			pids[MAX_PHILO];
	int			i;

	philo[0].args = args;
	init_struct_philo(philo, mutexes, sems, pids);
	i = 0;
	while (i < args.n)
		waitpid(pids[i++], NULL, 0);
	i = -1;
	while (++i < args.n)
		sem_unlink(&philo[i].d.mutexes[i]);
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
