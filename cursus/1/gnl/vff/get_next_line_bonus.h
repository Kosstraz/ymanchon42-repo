/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:54:36 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/26 18:51:41 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

# define FD_MAX 1024

# include <stdlib.h>

/* //////////////////////////// */
// 								//
//				UTILS			//
//								//
/* //////////////////////////// */

void	*free_n(char **ptr);
char	thereis_nl(const char *s);
size_t	ft_strlenc(const char *str, char c);
char	*ft_strdup(const char *s);
// @param s1 sera free a la fin de la fonction
char	*ft_strjoin(char *s1, const char *s2);

/* //////////////////////////// */
// 								//
//				GNL				//
//								//
/* //////////////////////////// */

char	*get_next_line(int fd);

#endif