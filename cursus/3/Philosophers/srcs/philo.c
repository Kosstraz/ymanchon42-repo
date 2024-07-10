/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:34:08 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/10 17:13:51 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo_struct(t_philo **philo, t_datas *data, int count)
{
	pthread_mutex_t	*mutexes;
	pthread_t		*threads;
	int				i;

	i = 0;
	mutexes = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * count);
	if (!mutexes)
		exit(0);
	threads = (pthread_t *)malloc(sizeof(pthread_t) * count);
	if (!threads)
		freexit(mutexes);
	*philo = (t_philo *)malloc(sizeof(t_philo) * count);
	if (!*philo)
		freexit2(mutexes, threads);
	data->mutexes = mutexes;
	data->threads = threads;
}

void	thinking(t_philo *philo, int i)
{
	while ((i == philo->args.n - 1 && philo->d.locked && philo[0].d.locked)
		|| (i != philo->args.n - 1 && philo->d.locked && philo[i + 1].d.locked))
		;
}

void	*routine(void *philo)
{
	/*struct timeval	tv;
	int				i;
	long			time;

	i = philo->index;
	while (1)
	{
		gettimeofday(&tv, NULL);
		time = tv.tv_usec - philo->start_time;
		thinking(&philo[i], i);
		lock_mutex(philo, i);
		usleep(philo->args.etime);
		unlock_mutex(philo, i);
		usleep(philo->args.stime);
		exit(0);
	}*/
	return (NULL);
}

void	philosophers(t_philo *philo, t_datas data, int count)
{
	struct timeval	tv;
	int				i;

	i = 0;
	gettimeofday(&tv, NULL);
	while (i < count)
	{
		philo[i].index = i;
		philo[i].d.locked = 0;
		philo[i].start_time = tv.tv_usec;
		philo[i].d.mutexes = data.mutexes;
		philo[i].d.threads = data.threads;
		i++;
	}
	i = 0;
	while (i < count)
	{
		pthread_mutex_init(&philo[i].d.mutexes[i], NULL);
		pthread_create(&philo[i].d.threads[i], NULL, routine, (void *)philo);
		i++;
	}/**/
	i = 0;
	while (i < count)
	{
		pthread_join(philo[i].d.threads, NULL);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_args	args;
	t_datas	data;
	t_philo	*philo;

	if (ac < 5)
		printf(INVALID_ARGS);
	else
	{
		if (!valid_args(ac - 1, &av[1]))
			return (printf(NEGATIVE_NUMBER), 0);
		take_args(&args, &av[1]);
		init_philo_struct(&philo, &data, ac - 1);
		philosophers(philo, data, ac);
	}
	return (0);
}
