/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:18:11 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/16 17:31:27 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# define BUFFER_SIZE 1

typedef struct s_gnl_data
{
	char	*data;
	ssize_t	seek;
}	t_gnl_data;

char	*ft_strjoin_at(const char *s1, const char *s2, size_t at);
char	*ft_strdup(const char *src, size_t len);
char	*save_line(char *saver, const char *gd, size_t at);
char	*get_next_line(int fd);

#endif
