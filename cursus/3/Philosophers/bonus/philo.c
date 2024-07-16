/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:34:08 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/16 19:01:44 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

char	init_struct_philo(t_philo philo[MAX_PHILO], sem_t *sems[MAX_PHILO + 1])
{
	sem_t	*sem_te;
	sem_t	*sem_d;
	sem_t	*sem_pf;
	int		i;

	i = -1;
	init_sem(sems, philo[0].args.n, &sem_te, &sem_d);
	init_sem_for_printf(&sem_pf);
	if (alloc_all_var(philo))
		return (1);
	gettimeofday(&philo[0].start_time, NULL);
	while (++i < philo[0].args.n)
	{
		philo[i].sem_te = sem_te;
		philo[i].sem_d = sem_d;
		philo[i].sem_pf = sem_pf;
		philo[i].total_eat = philo[0].total_eat;
		philo[i].dead = philo[0].dead;
		philo[i].index = i;
		philo[i].args = philo[0].args;
		philo[i].start_time = philo[0].start_time;
		philo[i].d.sems = sems;
	}
	return (0);
}

void	philosophers(t_philo philo[MAX_PHILO], t_args args)
{
	sem_t		*sems[MAX_PHILO + 1];
	const char	*sems_name;
	int			pids[MAX_PHILO];
	int			i;

	philo[0].args = args;
	if (init_struct_philo(philo, sems))
		return ;
	memset(pids, 0, MAX_PHILO);
	i = -1;
	while (++i < args.n)
		launch_routine(&philo[i], &pids[i]);
	i = 0;
	while (i < args.n)
		waitpid(pids[i++], NULL, 0);
	i = -1;
	while (++i < args.n)
	{
		sems_name = create_name(i);
		sem_close(sems[i]);
		sem_unlink(sems_name);
		free((void *)sems_name);
	}
	close_sem_te_d(philo->sem_te, philo->sem_d, philo->sem_pf, philo);
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
