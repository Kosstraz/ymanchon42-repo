/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:58:29 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/06 21:43:56 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

t_btree	*btree_infix_node(t_btree *root)
{
	if (!root)
		return (NULL);
	while (root->left)
		root = root->left;
	return (root);
}

void	*btree_search_item_recu(t_btree *root, void *data_ref, void **nullable, int (*cmpf)(void *, void *))
{
	if (!root)
		return (*nullable);
	btree_search_item_recu(root->left, data_ref, nullable, cmpf);
	if (cmpf(data_ref, root->item) == 0)
	{
		*nullable = data_ref;
		return (*nullable);
	}
	btree_search_item_recu(root->right, data_ref, nullable, cmpf);
	return (*nullable);
}

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
{
	void	*ret;
	return (btree_search_item_recu(root, data_ref, &ret, cmpf));
}