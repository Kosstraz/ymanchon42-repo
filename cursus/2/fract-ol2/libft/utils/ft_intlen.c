/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:32:27 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/13 17:14:26 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_intlen(int n)
{
	int	ret;

	ret = 0;
	if (n <= 0)
	{
		n = -n;
		ret++;
	}
	while (n > 0)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}
