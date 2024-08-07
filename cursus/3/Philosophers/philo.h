/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:10:22 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/16 18:23:32 by ymanchon         ###   ########.fr       */
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

# define MAX_PHILO 201

# define PHILO_TAKENFORK "has taken a fork"
# define PHILO_EATING "is eating"
# define PHILO_SLEEPING "is sleeping"
# define PHILO_THINKING "is thinking"
# define PHILO_DIED "died"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/wait.h>
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
	pthread_mutex_t	*mutex_pf;
	int				*total_eat;
	char			*dead;
}	t_philo;

char	take_her_forks(t_philo *philo);
void	printfp(t_philo *philo, char *msg);
void	*routine(t_philo philo[MAX_PHILO]);
void	*routine_cast(void *philo);
void	check_must_eat(t_philo *philo, const int eat_needed);
// 0 vivant
// 1 mort
char	check_death_with_fork(t_philo *philo);
char	alloc_all_var(t_philo philo[MAX_PHILO]);
// 0 vivant
// 1 mort
char	check_death(t_philo *philo);
void	take_one_fork(t_philo *philo, int mut_i);
int		ft_atoi(const char *str);
char	valid_args(int ac, char **av);
void	take_args(t_args *args, char **av, int ac);
void	drop_forks(t_philo *philo);
	// initialisation des mutexes contextuellement a la
//structure du programme
void	init_mutex(t_fork mutexes[MAX_PHILO + 1], int count);
	// converton struct timeval en millisecondes
int		ms(struct timeval tv);
int		get_msinter(struct timeval s, struct timeval e);
// 0 vivant
// 1 mort
char	useating(t_philo *philo, struct timeval s);
// 0 vivant
// 1 mort
char	ussleeping(t_philo *philo, struct timeval s);
// Tue le philosophe
char	kill_philosopher(t_philo *philo);

#endif