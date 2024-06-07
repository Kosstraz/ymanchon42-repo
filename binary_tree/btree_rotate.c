/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:01:51 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/07 12:49:38 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	btree_right_inverse(t_btree **root, int level_max)
{
	unsigned long long	p_root;
	unsigned long long	p_right;

	p_root = (unsigned long long)(*root);
	p_right = (unsigned long long)((*root)->right);
	p_root ^= p_right;
	p_right ^= p_root;
	p_root ^= p_right;
	*root = (void *)p_root;
	(*root)->right = (void *)p_right;
}

void	btree_left_inverse(t_btree **root, int level_max)
{
	unsigned long long	p_root;
	unsigned long long	p_left;

	p_root = (unsigned long long)(*root);
	p_left = (unsigned long long)((*root)->left);
	p_root ^= p_left;
	p_left ^= p_root;
	p_root ^= p_left;
	*root = (void *)p_root;
	(*root)->left = (void *)p_left;
}

int	main(void)
{
	void	*ez1 = malloc(1);
	void	*ez2 = malloc(1);
	void	*ez3 = malloc(1);
	void	*ez3bis = malloc(1);
	void	*ez4 = malloc(1);
	void	*ez5 = malloc(1);
	void	*ez6 = malloc(1);
	void	*ez4_ref = ez1;

	t_btree	*node;
	node = btree_create_node(ez1);
	
	node->left = btree_create_node(ez1);
	node->left->left = btree_create_node(ez2);
	node->left->right = btree_create_node(ez3);
	
	node->right = btree_create_node(ez3bis);
	node->right->left = btree_create_node(ez4);
	node->right->right = btree_create_node(ez5);

	int	norage;
	btree_left_size(&node, &norage);
	printf("%d\n", norage);
	return (0);
}

void	btree_rotate(t_btree **root)
{
	/*int	lr;
	int	level_max;
	t_btree	*tmp;

	tmp = *root;
	btree_size(&tmp, &lr);
	if (lr < 0)
		btree_left_inverse(root, level_max);
	else if (lr > 0)
		btree_right_inverse(root, level_max);
	if (lr != 0
		|| (lr < -BTREE_ROTATION_THRESOLD && lr > BTREE_ROTATION_THRESOLD))
		btree_rotate(root);*/
}