/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:10:22 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/12 18:11:36 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define INVALID_ARGS "\e[31mNombre incorrecte d'argument :\
 (tout argument supplementaire sera ignore)\e[0m\n\
./philo [\e[33mnumber of philo\e[0m] [\e[33mdie time\e[0m]\
 [\e[33meat time\e[0m] [\e[33msleep time\e[0m]\n\e[0m"

# define NEGATIVE_NUMBER "\e[31mVeuillez saisir un nombre positif !\n\e[0m"

# define MAX_PHILO 200

# define PHILO_TAKENFORK "%d Philosopher %d has taken a fork\n"
# define PHILO_EATING "%d Philosopher %d is eating\n"
# define PHILO_SLEEPING "%d Philosopher %d is sleeping\n"
# define PHILO_THINKING "%d Philosopher %d is thinking\n"
# define PHILO_DIED "%d Philosopher %d died\n"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef pthread_mutex_t	t_fork;

typedef struct s_args
{
	int	n;
	int	dtime;
	int	etime;
	int	stime;
}	t_args;

typedef struct s_time
{
	struct timeval	s;
	struct timeval	e;
}	t_time;

typedef struct s_table
{
	t_fork		*mutexes;
	pthread_t	threads;
}	t_table;

typedef struct s_philo
{
	struct timeval	start_time;
	t_table			d;
	t_args			args;
	int				index;
	char			*dead;
}	t_philo;

int		ft_atoi(const char *str);
char	valid_args(int ac, char **av);
void	take_args(t_args *args, char **av);
void	freexit(void *ptr);
void	freexit2(void *ptr1, void *ptr2);
	// initialisation des mutexes contextuellement a la
//structure du programme
void	init_mutex(t_fork mutexes[MAX_PHILO + 1], int count);
	// converton struct timeval en millisecondes
int		get_mseconds(struct timeval tv);
int		get_msinter(struct timeval s, struct timeval e);
void	take_fork(t_philo *philo, struct timeval begint, int mut_i);
	// usleep personnalise
void	pusleep(t_philo *philo, struct timeval s, struct timeval begint);
	// Tue le philosophe
void	kill_philosopher(t_philo *philo, struct timeval tv);
void	init_struct_philo(t_philo philo[MAX_PHILO],
			t_fork mutexes[MAX_PHILO + 1], t_args args);

#endif