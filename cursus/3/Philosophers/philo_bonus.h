/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:10:22 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/16 19:03:59 by ymanchon         ###   ########.fr       */
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

# define MAX_PHILO 201

# define PHILO_TAKENFORK "has taken a fork"
# define PHILO_EATING "is eating"
# define PHILO_SLEEPING "is sleeping"
# define PHILO_THINKING "is thinking"
# define PHILO_DIED "died"

# define SEM_N "/2sem_philo_bonus_"
# define SEM_FOR_DEATH "/sem_philo_bonus_for_death2"
# define SEM_FOR_NB_OF_EATS "/sem_philo_bonus_for_nb_of_eats2"
# define SEM_FOR_PRINTF "/sem_philo_printf2"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
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
	sem_t	**sems;
}	t_table;

typedef struct s_philo
{
	struct timeval	start_time;
	t_table			d;
	t_args			args;
	int				index;
	sem_t			*sem_te;
	sem_t			*sem_d;
	sem_t			*sem_pf;
	int				*total_eat;
	char			*dead;
}	t_philo;

void		init_sem_for_printf(sem_t **sem_pf);
void		close_sem_te_d(sem_t *sems_te, sem_t *sem_d, sem_t *sem_pf,
				t_philo philo[MAX_PHILO]);
const char	*create_name(int i);
char		*ft_strdup(const char *str);
char		*ft_strjoin_free(char *s1, const char *s2);
char		*ft_itoa(int n);
char		take_her_forks(t_philo *philo);
void		printfp(t_philo *philo, char *msg);
void		*routine(t_philo philo[MAX_PHILO]);
void		launch_routine(t_philo *philo, int *pid);
void		check_must_eat(t_philo *philo, const int eat_needed);
char		check_death_with_fork(t_philo *philo);
char		alloc_all_var(t_philo philo[MAX_PHILO]);
char		check_death(t_philo *philo);
void		take_one_fork(t_philo *philo, int mut_i);
int			ft_atoi(const char *str);
char		valid_args(int ac, char **av);
void		take_args(t_args *args, char **av, int ac);
void		drop_forks(t_philo *philo);
void		init_sem(sem_t *sems[MAX_PHILO + 1], int count, sem_t **sem_te,
				sem_t **sem_d);
	// converton struct timeval en millisecondes
int			ms(struct timeval tv);
int			get_msinter(struct timeval s, struct timeval e);
	// usleep personnalise (eating)
char		useating(t_philo *philo, struct timeval s);
	// usleep personnalise (sleeping)
char		ussleeping(t_philo *philo, struct timeval s);
	// Tue le philosophe
char		kill_philosopher(t_philo *philo);

#endif