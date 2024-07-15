/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:05:31 by bama              #+#    #+#             */
/*   Updated: 2024/07/15 22:15:18 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	alloc_all_var(char **dead, int **total_eat, sem_t **mutex_te,
			sem_t **mutex_d)
{
	*dead = (char *)malloc(sizeof(char));
	if (!*dead)
		exit(0);
	*total_eat = (int *)malloc(sizeof(int));
	if (!*total_eat)
		freexit(*dead);
	*mutex_te = (sem_t *)malloc(sizeof(sem_t));
	if (!*mutex_te)
		freexit2(*dead, *total_eat);
	*mutex_d = (sem_t *)malloc(sizeof(sem_t));
	if (!*mutex_d)
	{
		free(*dead);
		freexit2(*total_eat, *mutex_te);
	}
	**dead = 0;
	**total_eat = 0;
	sem_open(*mutex_te, NULL);
	sem_open(*mutex_d, NULL);
}

void	launch_routine(t_philo philo[MAX_PHILO], int *pid)
{
	*pid = fork();
	if (*pid == 0)
		routine(philo);
}
