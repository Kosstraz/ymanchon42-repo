/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:09:36 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/26 20:41:12 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# ifndef BONUS_PART
#  define BONUS_PART 0
# endif

# define LFORMAT "cspiudxX%"
# define __FLAG_ "# +"

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/* /////////////////////////
////		BONUS		////
////////////////////////  */

typedef struct s_flags_info
{
	int	diez;
	int	space;
	int	plus;
}	t_flags_info;

char	is_valid(const char *s);
char	is_flag(char c);
char	is_lformat(char c);
void	add_flag(t_flags_info *finfo, char flag);
int		ft_printf_parse_bonus(const char *msg, int *i, va_list *args);
int		ft_printf_handle_bonus(char c, t_flags_info finfo, va_list *args);

/* /////////////////////////////
////		MANDATORY		////
///////////////////////////// */

int		ft_strlen(const char *str);
int		ft_putstr(const char *str);
int		ft_puthexa(char *hexa);
int		ft_putchar(char c);
int		ft_putnbr(int n, int len);
int		ft_putunbr(unsigned int n, int len);
void	ft_swapchr(char **str, unsigned long size);
char	*ft_toupper(char *s);
char	*ft_ith(int n, char c);
char	*ft_adth(const void *ptr, const char *base);

#endif
