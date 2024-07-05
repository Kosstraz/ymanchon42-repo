/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freemen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:05:31 by bama              #+#    #+#             */
/*   Updated: 2024/06/18 11:14:46 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

void	freemen(int ac, ...)
{
	va_list	args;

	va_start(args, ac);
	while (ac--)
		free(va_arg(args, void *));
	va_end(args);
}
