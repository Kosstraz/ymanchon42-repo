/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:38:33 by bama              #+#    #+#             */
/*   Updated: 2024/06/18 16:40:01 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dfree(void **ptr2)
{
	int	i;

	i = 0;
	while (ptr2[i])
		free(ptr2[i++]);
	free(ptr2);
}