/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:05:31 by bama              #+#    #+#             */
/*   Updated: 2024/07/16 18:19:30 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	alloc_all_var(t_philo philo[MAX_PHILO])
{
	philo[0].dead = (char *)malloc(sizeof(char));
	if (!philo[0].dead)
		return (1);
	philo[0].total_eat = (int *)malloc(sizeof(int));
	if (!philo[0].total_eat)
		return (free(philo[0].dead), 1);
	philo[0].mutex_te = (t_fork *)malloc(sizeof(t_fork));
	if (!philo[0].mutex_te)
		return (free(philo[0].dead), free(philo[0].total_eat), 1);
	philo[0].mutex_d = (t_fork *)malloc(sizeof(t_fork));
	if (!philo[0].mutex_d)
	{
		free(philo[0].mutex_te);
		return (free(philo[0].dead), free(philo[0].total_eat), 1);
	}
	philo[0].mutex_pf = (t_fork *)malloc(sizeof(t_fork));
	if (!philo[0].mutex_pf)
	{
		free(philo[0].mutex_te);
		free(philo[0].mutex_d);
		return (free(philo[0].dead), free(philo[0].total_eat), 1);
	}
	*philo[0].dead = 0;
	*philo[0].total_eat = 0;
	return (0);
}

//alloc_all_var2(pthread_mutex_t **mutex_pf)

void	*routine_cast(void *philo)
{
	return (routine((t_philo *)philo));
}
