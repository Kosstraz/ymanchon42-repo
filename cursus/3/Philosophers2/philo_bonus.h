/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:10:22 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/15 22:16:02 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# define INVALID_ARGS "\e[31mNombre incorrecte d'argument :\
 (tout argument supplementaire sera ignore)\e[0m\n\
./philo [\e[33mnumber of philo\e[0m] [\e[33mdie time\e[0m]\
 [\e[33meat time\e[0m] [\e[33msleep time\e[0m]\
 {\e[33mnumber of times each philosopher must eat\e[0m}\e[0m\n"

# define NEGATIVE_NUMBER "\e[31mVeuillez saisir un nombre positif !\n\e[0m"

# define MAX_PHILO 200

# define PHILO_TAKENFORK "has taken a fork\n"
# define PHILO_EATING "is eating\n"
# define PHILO_SLEEPING "is sleeping\n"
# define PHILO_THINKING "is thinking\n"
# define PHILO_DIED "died\n"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <sys/time.h>

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
	sem_t	*sems;
}	t_table;

typedef struct s_philo
{
	struct timeval	start_time;
	t_table			d;
	t_args			args;
	int				index;
	sem_t			*sem_te;
	sem_t			*sem_d;
	int				*total_eat;
	char			*dead;
}	t_philo;

void	take_her_forks(t_philo *philo);
void	printfp(t_philo *philo, char *msg);
void	*routine(t_philo philo[MAX_PHILO]);
void	launch_routine(t_philo philo[MAX_PHILO], int **pid);
void	check_must_eat(t_philo *philo, const int eat_needed);
void	check_death_with_fork(t_philo *philo);
void	alloc_all_var(char **dead, int **total_eat, sem_t **mutex_te,
			sem_t **mutex_d);
void	check_death(t_philo *philo);
void	take_one_fork(t_philo *philo, int mut_i);
int		ft_atoi(const char *str);
char	valid_args(int ac, char **av);
void	take_args(t_args *args, char **av, int ac);
void	freexit(void *ptr);
void	freexit2(void *ptr1, void *ptr2);
void	drop_forks(t_philo *philo);
void	init_sem(sem_t *sems[MAX_PHILO + 1], int count);
	// converton struct timeval en millisecondes
int		ms(struct timeval tv);
int		get_msinter(struct timeval s, struct timeval e);
	// usleep personnalise (eating)
void	useating(t_philo *philo, struct timeval s);
	// usleep personnalise (sleeping)
void	ussleeping(t_philo *philo, struct timeval s);
	// Tue le philosophe
void	kill_philosopher(t_philo *philo);

#endif