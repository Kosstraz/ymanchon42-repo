/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:05:31 by bama              #+#    #+#             */
/*   Updated: 2024/07/10 17:03:50 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_mutex(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->d.mutexes[i]);
	philo->d.locked = 1;
}

void	unlock_mutex(t_philo *philo, int i)
{
	pthread_mutex_unlock(&philo->d.mutexes[i]);
	philo->d.locked = 0;
}

void	freexit(void *ptr)
{
	free(ptr);
	exit(0);
}

void	freexit2(void *ptr1, void *ptr2)
{
	free(ptr1);
	free(ptr2);
	exit(0);
}
