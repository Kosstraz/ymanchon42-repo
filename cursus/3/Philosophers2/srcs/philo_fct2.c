/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fct2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:36:48 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/14 18:34:26 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

inline void	drop_forks(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_unlock(&philo->d.mutexes[philo->index]);
		pthread_mutex_unlock(&philo->d.mutexes[philo->index + 1]);
	}
	else
	{
		pthread_mutex_unlock(&philo->d.mutexes[philo->index + 1]);
		pthread_mutex_unlock(&philo->d.mutexes[philo->index]);
	}
}
