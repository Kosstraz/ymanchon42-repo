/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:54:36 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/13 14:40:59 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

/* //////////////////////////// */
// 								//
//				UTILS			//
//								//
/* //////////////////////////// */

void	*free_n(char **ptr);
char	thereis_nl(const char *s);
size_t	ft_strlenc(const char *str, char c);
char	*ft_strdup_gnl(const char *s);
// @param s1 sera free a la fin de la fonction
char	*ft_strjoin_free(char *s1, const char *s2);

/* //////////////////////////// */
// 								//
//				GNL				//
//								//
/* //////////////////////////// */

char	*get_next_line(int fd);

#endif
