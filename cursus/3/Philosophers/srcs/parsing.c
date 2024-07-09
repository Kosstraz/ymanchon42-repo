/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:21:05 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/09 20:08:53 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_philo_v(t_philo_args *philo_v, char **av)
{
	philo_v->n = ft_atoi(av[0]);
	philo_v->dtime = ft_atoi(av[1]);
	philo_v->etime = ft_atoi(av[2]);
	philo_v->stime = ft_atoi(av[3]);
	if (philo_v->n < 0 || philo_v->dtime < 0
		|| philo_v->etime < 0 || philo_v->stime < 0)
		return (0);
	return (1);
}

void	init_t_philo(t_philo *philo)
{
	philo->mutexes = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* philo->args.n);
	philo->threads = (pthread_t *)malloc(sizeof(pthread_t) * philo->args.n);
}
