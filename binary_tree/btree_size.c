/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:45:12 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/07 12:50:55 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	btree_left_size(t_btree *root, int *count)
{
	if (root)
	{
		btree_left_size(root->left, count);
		(*count)++;
		btree_left_size(root->right, count);
	}
}

void	btree_right_size(t_btree *root, int *count)
{
	if (root)
	{
		(*count)++;
		btree_right_size((root->right), count);
	}
}

void	btree_size(t_btree *root, int *size)
{
	*size = 0;
	if (root)
	{
		*size = 1;
		btree_left_size(root, size);
	}
}