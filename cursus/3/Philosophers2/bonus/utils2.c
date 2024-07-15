/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:05:31 by bama              #+#    #+#             */
/*   Updated: 2024/07/15 15:15:41 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	alloc_all_var(char **dead, int **total_eat, pthread_mutex_t **mutex_te,
			pthread_mutex_t **mutex_d)
{
	*dead = (char *)malloc(sizeof(char));
	if (!*dead)
		exit(0);
	*total_eat = (int *)malloc(sizeof(int));
	if (!*total_eat)
		freexit(*dead);
	*mutex_te = (t_fork *)malloc(sizeof(t_fork));
	if (!*mutex_te)
		freexit2(*dead, *total_eat);
	*mutex_d = (t_fork *)malloc(sizeof(t_fork));
	if (!*mutex_d)
	{
		free(*dead);
		freexit2(*total_eat, *mutex_te);
	}
	**dead = 0;
	**total_eat = 0;
	pthread_mutex_init(*mutex_te, NULL);
	pthread_mutex_init(*mutex_d, NULL);
}

void	*routine_cast(void *philo)
{
	return (routine((t_philo *)philo));
}
