/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:09:36 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/16 15:57:31 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

int		ft_strlen(const char *str);
void	ft_putstr(const char *str);
void	ft_puthexa(char *hexa);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putunbr(unsigned int n);
void	ft_swapchr(char **str, unsigned long size);
char	*ft_ith(int n, const char *base);
char	*ft_addth(const void *ptr, const char *base);

#endif
