/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:58:13 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/08 12:53:34 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void);

void	ft_print_reverse_alphabet(void)
{
	int	i;

	i = ('z' + 1);
	while (--i >= 'a')
		write(1, &i, 1);
}

/*int main(void)
{
	ft_print_reverse_alphabet();
}*/
