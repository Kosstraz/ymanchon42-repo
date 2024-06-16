/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:09:36 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/13 11:59:01 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include "binary_tree/btree.h"

# ifndef GNL_BUFFER_SIZE
#  define GNL_BUFFER_SIZE 64
# endif

/* //////////////////////////// */
// 								//
//			FT_PRINTF			//
//								//
/* //////////////////////////// */

int		ft_printf(const char *msg, ...);

/* //////////////////////////// */
// 								//
//				GNL				//
//								//
/* //////////////////////////// */

char	*get_next_line(int fd);

///////////////
/*  PARSING  */
///////////////

// @param s La chaîne dans laquelle itérer
// @param start La position où l'on commence à incrémenter
// dans 's' en tant que pointeur, sa valeur sera modifiée
// @return La valeur initiale de start est renvoyée
size_t	ft_isspace(const char *s, size_t *start);
// @param s La chaîne dans laquelle itérer
// @param size La taille de 's'. Si 'size' == 0 -> 'size' = ft_strlen('s')
// @return La position où un caractère < à 7 et > à 13 est trouvé
ssize_t	ft_rev_isspace(const char *s, ssize_t size);
// @param s La chaîne dans laquelle itérer
// @param start La position où l'on commence à decrémenter
// @return La position où un caractère < à 7 et > à 13 est trouvé
ssize_t	ft_rev_isspaceptr(const char *s, ssize_t start);

/////////////
/*  BONUS  */
/////////////

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//////////////
/* PARTIE I */
//////////////

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *str, const char c);
char	*ft_strrchr(const char *str, const char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t type_size);
char	*ft_strdup(const char *str);

///////////////
/* PARTIE II */
///////////////

char	*ft_substr(const char *s, unsigned int start, size_t n);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	**ft_split(const char *s, char sep);
char	*ft_itoa(int n);
char	*ft_strmapi(const char *str, char (*f)(unsigned int, char));
void	ft_striteri(char *str, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(const char *str, int fd);
void	ft_putendl_fd(const char *str, int fd);
void	ft_putnbr_fd(int n, int fd);

//////////////
/*	OTHERS	*/
//////////////

void	ft_swap_addr(void **a, void **b);
size_t	ft_count_words(const char *s, char sep);
int		ft_intlen(int n);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

#endif
