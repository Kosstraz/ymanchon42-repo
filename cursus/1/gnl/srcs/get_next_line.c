/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:17:48 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/16 17:41:30 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../get_next_line.h"

#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*passed;
	char		*ret;
	ssize_t		r;
	ssize_t		log;

	if (fd < 0)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!ret)
		return (NULL);
	r = 1;
	while (r > 0 && r <= BUFFER_SIZE)
	{
		log = read(fd, ret, sizeof(char));
		r += log;
		if (log == -1)
			return (NULL);
	}	
	free(ret);
	return (NULL);
}
