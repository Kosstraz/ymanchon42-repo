/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:10:22 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/09 20:12:34 by ymanchon         ###   ########.fr       */
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

/*
	PTHREAD_CREATE -->
Creer un thread avec ses attributs.

	PTHREAD_DETACH -->
Marque le thread mis en parametre comme detache, il ne pourra plus etre join.
Mais en cas d'arret du thread, ses ressources seront restituees a la machine.

	PTHREAD_EXIT -->
Le thread appelant est exit.

	PTHREAD_JOIN -->
Attends un thread.

	PTHREAD_MUTEX_INIT -->
Initialize un mutex avec ses attributs. Juste apres sont initialisation le mutex sera unlock.

	PTHREAD_MUTEX_LOCK -->
Verouille un mutex avec attribut.

	PTHREAD_MUTEX_UNLOCK -->
Deverouille un mutex.

	PTHREAD_DESTROY -->
Detruit un mutex, verifiez qu'il soit bien unlock avant.
*/

typedef struct s_philo_args
{
	int	n;
	int	dtime;
	int	etime;
	int	stime;
}	t_philo_args;

typedef struct s_philo
{
	pthread_t		*threads;
	pthread_mutex_t	*mutexes;
	t_philo_args	args;
	long			start_time;
}	t_philo;

int		set_philo_v(t_philo_args *philo_v, char **av);
int		ft_atoi(const char *str);
void	printf_exit(char *msg);

#endif