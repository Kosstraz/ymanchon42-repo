/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:10:22 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/14 18:47:10 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define INVALID_ARGS "\e[31mNombre incorrecte d'argument :\
 (tout argument supplementaire sera ignore)\e[0m\n\
./philo [\e[33mnumber of philo\e[0m] [\e[33mdie time\e[0m]\
 [\e[33meat time\e[0m] [\e[33msleep time\e[0m]\
 {\e[33mnumber of times each philosopher must eat\e[0m}\e[0m\n"

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
	int	time_musteat;
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
	pthread_mutex_t	*mutex_te;
	pthread_mutex_t	*mutex_d;
	int				*total_eat;
	char			*dead;
}	t_philo;

void	alloc_all_var(char **dead, int **total_eat, pthread_mutex_t **mutex_te,
			pthread_mutex_t **mutex_d);
void	check_death(t_philo *philo);
void	taken_fork(t_philo *philo, struct timeval begint, int mut_i);
int		ft_atoi(const char *str);
char	valid_args(int ac, char **av);
void	take_args(t_args *args, char **av, int ac);
void	freexit(void *ptr);
void	freexit2(void *ptr1, void *ptr2);
void	drop_forks(t_philo *philo);
	// initialisation des mutexes contextuellement a la
//structure du programme
void	init_mutex(t_fork mutexes[MAX_PHILO + 1], int count);
	// converton struct timeval en millisecondes
int		ms(struct timeval tv);
int		get_msinter(struct timeval s, struct timeval e);
	// usleep personnalise (eating)
void	useating(t_philo *philo, struct timeval s, struct timeval begint);
	// usleep personnalise (sleeping)
void	ussleeping(t_philo *philo, struct timeval s, struct timeval begint);
	// Tue le philosophe
void	kill_philosopher(t_philo *philo, struct timeval tv);

#endif