/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:17:01 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/22 19:41:38 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

char	*ft_strdup(const char *str);
char	*save_line(char **s);
char	*takesubstr_until(const char *s);
char	*remsubstr_until(char *s);
char	*get_next_line(int fd);

#endif