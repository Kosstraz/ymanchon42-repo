/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 22:39:10 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/31 18:37:00 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_parse_color(t_point *point, const char *line, size_t *i)
{
	char	hexa[7];
	char	*converted;
	size_t	j;
	int		color;

	color = *i;
	j = 0;
	while (line[*i] && line[*i] == ',')
		(*i)++;
	if (line[*i] == '0')
		(*i)++;
	if (line[*i] == 'x')
		(*i)++;
	while (line[*i] && (line[*i] == '0' || line[*i] == 'F'))
		hexa[j++] = line[(*i)++];
	hexa[j] = '\0';
	if ((size_t)color != *i)
	{
		converted = ft_convert_base(hexa, "0123456789ABCDEF", "0123456789");
		color = ft_atoi(converted);
		free(converted);
		point->color = color;
		return ;
	}
	point->color = WHITE;
}

