/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:11:03 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/09 20:13:35 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	main_routine(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	while (1)
	{
		printf("%d Philosophers is thinking.\n", tv.tv_usec - philo->start_time);
		// if (mutex dispo)
		//{
			printf("%d Philosophers is eating.\n", tv.tv_usec - philo->start_time);
			usleep(philo->args.etime);
		//}
		printf("%d Philosophers is sleeping.\n", tv.tv_usec - philo->start_time);
		usleep(philo->args.stime);
	}
}

static void	philosophers(t_philo *philo)
{
	int	i;
	struct timeval	tv;

	i = 0;
	gettimeofday(&tv, NULL);
	philo->start_time = tv.tv_usec;
	while (i < philo->args.n)
	{
		pthread_mutex_init(&philo->mutexes[i], NULL);
		pthread_mutex_lock(&philo->mutexes[i]);
		pthread_create(&philo->threads[i], NULL, &main_routine, philo);
		if (i < philo->args.n - 1)
			pthread_detach(&philo->threads[i]);
		i++;
	}
	pthread_join(philo->threads[i - 1], NULL);
}

int	main(int ac, char **av)
{
	t_philo	philo;

	if (ac < 5)
		printf(INVALID_ARGS);
	else
	{
		if (!set_philo_v(&philo.args, &av[1]))
			printf_exit(NEGATIVE_NUMBER);
		init_t_philo(&philo);
		philosophers(&philo);
		//free(philo.mutexes);
		//free(philo.threads);
	}
	return (0);
}
