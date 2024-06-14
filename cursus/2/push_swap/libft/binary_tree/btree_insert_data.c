/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:36:54 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/13 17:13:31 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	btree_insert_data(t_btree **root, T_BTREE item,
			int (*cmpf)(T_BTREE, T_BTREE))
{
	int	cmp;

	if (!root || !*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	cmp = cmpf(item, (*root)->item);
	if (cmp < 0)
		btree_insert_data(&(*root)->left, item, cmpf);
	else if (cmp >= 0)
		btree_insert_data(&(*root)->right, item, cmpf);
}
