/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:05:31 by bama              #+#    #+#             */
/*   Updated: 2024/07/16 19:01:36 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

char	alloc_all_var(t_philo philo[MAX_PHILO])
{
	philo[0].dead = (char *)malloc(sizeof(char));
	if (!philo[0].dead)
		return (1);
	philo[0].total_eat = (int *)malloc(sizeof(int));
	if (!philo[0].total_eat)
		return (free(philo[0].dead), 1);
	*philo[0].dead = 0;
	*philo[0].total_eat = 0;
	return (0);
}

void	launch_routine(t_philo *philo, int *pid)
{
	if (*pid == 0)
		routine(philo);
}

const char	*create_name(int i)
{
	char		*itoa;
	const char	*name;

	name = ft_strdup(SEM_N);
	itoa = ft_itoa(i);
	name = ft_strjoin_free((char *)name, itoa);
	free(itoa);
	return (name);
}

void	close_sem_te_d(sem_t *sem_te, sem_t *sem_d, sem_t *sem_pf,
		t_philo philo[MAX_PHILO])
{
	sem_close(sem_te);
	sem_close(sem_d);
	sem_close(sem_pf);
	sem_unlink(SEM_FOR_DEATH);
	sem_unlink(SEM_FOR_NB_OF_EATS);
	sem_unlink(SEM_FOR_PRINTF);
	free(philo->dead);
	free(philo->total_eat);
}

void	init_sem_for_printf(sem_t **sem_pf)
{
	sem_unlink(SEM_FOR_PRINTF);
	*sem_pf = 0;
	*sem_pf = sem_open(SEM_FOR_PRINTF, O_CREAT, 0777, 1);
}
