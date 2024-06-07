/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:36:54 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/06 20:52:42 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	t_btree	*ez;
	t_btree	*tmp;

	if (!root || !*root)
	{
		ez = btree_create_node(item);
		if (ez && !root)
			root = &ez;
		else if (ez && root)
			*root = ez;
		return ;
	}
	if (cmpf(item, (*root)->left->item) < 0) // item < root->item GAUCHE
		btree_insert_data((*root)->left, item, cmpf);
	else if (cmpf(item, (*root)->right->item) >= 0) // item >= root->item DROITE
		btree_insert_data((*root)->right, item, cmpf);
}
