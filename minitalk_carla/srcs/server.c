/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cachetra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:08:37 by cachetra          #+#    #+#             */
/*   Updated: 2024/07/09 19:08:37 by cachetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/minitalk.h"

int	mess_len = 0;

static void	mt_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	mt_putpid(pid_t pid)
{
	if (pid > 9)
		mt_putpid(pid / 10);
	mt_putchar_fd(pid % 10 + '0', STDOUT_FILENO);
}

static void	mt_receive_message(int signum)
{
	static int	i = 0;
	static char	*mess = NULL;

	if (i++ < 32)
	{
		//printf("%d\n", signum);
		mess_len = mess_len << 1 | (signum == SIGUSR1);
		//printf("ez %d\n", mess_len);
		return ;
	}
	if (!mess)
	{
		mess = (char *)malloc(sizeof(char) * (mess_len + 1));
		if (!mess)
			exit(0) ;
		mess[mess_len] = '\0';
		i = -1;	
	}
	if (++i / 8 < mess_len)
		mess[i / 8] = mess[i / 8] * 10 + (signum == SIGUSR1);
	else
	{
		write(STDOUT_FILENO, mess, mess_len);
		free(mess);
		mess = NULL;
		i = 0;
		mess_len = 0;
	}
}

#include <stdio.h>

int	main(void)
{
	pid_t	pid;

	signal(SIGUSR1, &mt_receive_message);
	signal(SIGUSR2, &mt_receive_message);
	pid = getpid();
	mt_putpid(pid);
	mt_putchar_fd('\n', STDOUT_FILENO);
	while (1)
		;
	//{
	//}
	return (0);
}

/*
◦ write
◦ ft_printf et tout équivalent que VOUS avez codé
◦ signal
◦ sigemptyset
◦ sigaddset
◦ sigaction
◦ kill
◦ getpid
◦ malloc
◦ free
◦ pause
◦ sleep
◦ usleep
◦ exit

*/
