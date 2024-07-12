/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:05:31 by bama              #+#    #+#             */
/*   Updated: 2024/07/12 17:57:57 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct_philo(t_philo philo[MAX_PHILO],
		t_fork mutexes[MAX_PHILO + 1], t_args args)
{
	struct timeval	start_time;
	char			*dead;
	int				i;

	i = 0;
	init_mutex(mutexes, args.n);
	dead = (char *)malloc(sizeof(char));
	if (!dead)
		exit(0);
	*dead = 0;
	gettimeofday(&start_time, NULL);
	while (i < args.n)
	{
		philo[i].dead = dead;
		philo[i].index = i;
		philo[i].args = args;
		philo[i].start_time = start_time;
		philo[i].d.mutexes = mutexes;
		i++;
	}
}

int	get_mseconds(struct timeval tv)
{
	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}

int	get_msinter(struct timeval s, struct timeval e)
{
	return (get_mseconds(s) - get_mseconds(e));
}

void	init_mutex(t_fork mutexes[MAX_PHILO + 1], int count)
{
	int	i;

	i = 0;
	while (i < count)
		pthread_mutex_init(&mutexes[i++], NULL);
	mutexes[i] = mutexes[0];
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
