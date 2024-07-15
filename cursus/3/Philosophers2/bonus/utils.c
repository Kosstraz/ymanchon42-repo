/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:05:31 by bama              #+#    #+#             */
/*   Updated: 2024/07/15 22:15:18 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

inline int	ms(struct timeval tv)
{
	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}

inline int	get_msinter(struct timeval s, struct timeval e)
{
	return (ms(s) - ms(e));
}

void	init_sem(sem_t *sems[MAX_PHILO + 1], int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		sems[i] = sem_open(&sems[i], 0);
		i++;
	}
	sems[i] = sems[0];
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
