/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:05:31 by bama              #+#    #+#             */
/*   Updated: 2024/07/16 19:03:56 by ymanchon         ###   ########.fr       */
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

void	init_sem(sem_t *sems[MAX_PHILO + 1], int count, sem_t **sem_te,
		sem_t **sem_d)
{
	const char	*sems_name;
	int			i;

	i = 0;
	while (i < count)
	{
		sems_name = create_name(i);
		sem_unlink(sems_name);
		sems[i] = 0;
		sems[i] = sem_open(sems_name, O_CREAT, 0777, 1);
		free((void *)sems_name);
		i++;
	}
	sems[i] = sems[0];
	sem_unlink(SEM_FOR_DEATH);
	sem_unlink(SEM_FOR_NB_OF_EATS);
	*sem_d = 0;
	*sem_te = 0;
	*sem_d = sem_open(SEM_FOR_DEATH, O_CREAT, 0777, 1);
	*sem_te = sem_open(SEM_FOR_NB_OF_EATS, O_CREAT, 0777, 1);
}
