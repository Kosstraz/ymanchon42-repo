/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:05:31 by bama              #+#    #+#             */
/*   Updated: 2024/07/11 21:43:32 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
