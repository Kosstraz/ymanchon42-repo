/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 22:32:58 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/29 00:23:36 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_printexit(const char *strerror, int errcode)
{
	ft_putstr_fd(strerror, 2);
	exit(errcode);
}

void	freefall(void **ptr2, int count)
{
	while (count >= 0)
		free(ptr2[count--]);
	free(ptr2);
}