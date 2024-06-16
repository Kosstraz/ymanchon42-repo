/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:34:56 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/13 17:36:47 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	btree_apply_suffix(t_btree *root, void (*applyf)(T_BTREE))
{
	if (root)
	{
		btree_apply_suffix(root->left, applyf);
		btree_apply_suffix(root->right, applyf);
		applyf(root->item);
	}
}
