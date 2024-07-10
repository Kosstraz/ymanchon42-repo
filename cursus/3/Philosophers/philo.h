/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:10:22 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/10 17:02:33 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define INVALID_ARGS "\e[31mNombre incorrecte d'argument :\
 (tout argument supplementaire sera ignore)\e[0m\n\
./philo [\e[33mnumber of philo\e[0m] [\e[33mdie time\e[0m]\
 [\e[33meat time\e[0m] [\e[33msleep time\e[0m]\n\e[0m"

# define NEGATIVE_NUMBER "\e[31mVeuillez saisir un nombre positif !\n\e[0m"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_args
{
	int	n;
	int	dtime;
	int	etime;
	int	stime;
}	t_args;

typedef struct s_datas
{
	char			locked;
	pthread_mutex_t	*mutexes;
	pthread_t		*threads;
}	t_datas;

typedef struct s_philo
{
	t_datas			d;
	t_args			args;
	long			start_time;
	int				index;
}	t_philo;

int		ft_atoi(const char *str);
char	valid_args(int ac, char **av);
void	take_args(t_args *args, char **av);
void	freexit(void *ptr);
void	freexit2(void *ptr1, void *ptr2);
void	lock_mutex(t_philo *philo, int i);
void	unlock_mutex(t_philo *philo, int i);

#endif