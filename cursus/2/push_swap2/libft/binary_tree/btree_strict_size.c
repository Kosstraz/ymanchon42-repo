/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_strict_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:31:53 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/13 11:33:26 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

int	btree_strictleft_size(t_btree *tree)
{
	int	i;

	i = -1;
	while (tree)
	{
		tree = tree->left;
		i++;
	}
	return (i);
}

int	btree_strictright_size(t_btree *tree)
{
	int	i;

	i = -1;
	while (tree)
	{
		tree = tree->right;
		i++;
	}
	return (i);
}
