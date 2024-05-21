/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:19:56 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/16 17:25:04 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	int	fd = open("test.txt", O_RDONLY);
	
	printf("\e[33mgnl : %s$\e[0m\n", get_next_line(fd));
	printf("\e[33mgnl : %s$\e[0m\n", get_next_line(fd));
	printf("\e[33mgnl : %s$\e[0m\n", get_next_line(fd));
	printf("\e[33mgnl : %s$\e[0m\n", get_next_line(fd));
	printf("\e[33mgnl : %s$\e[0m\n", get_next_line(fd));
	printf("\e[33mgnl : %s$\e[0m\n", get_next_line(fd));
	printf("\e[33mgnl : %s$\e[0m\n", get_next_line(fd));
	printf("\e[33mgnl : %s$\e[0m\n", get_next_line(fd));

	close(fd);
	return (0);
}
