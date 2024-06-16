/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:45:12 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/13 11:44:59 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

static void	btree_size_recu(t_btree *root, int *count)
{
	if (root)
	{
		btree_size_recu(root->left, count);
		(*count)++;
		btree_size_recu(root->right, count);
	}
}

int	btree_left_size(t_btree *root)
{
	int	bsize;

	bsize = 0;
	btree_size_recu(root->left, &bsize);
	return (bsize);
}

int	btree_right_size(t_btree *root)
{
	int	bsize;

	bsize = 0;
	btree_size_recu(root->right, &bsize);
	return (bsize);
}

int	btree_size(t_btree *root)
{
	int	bsize;

	bsize = 0;
	btree_size_recu(root, &bsize);
	return (bsize);
}
