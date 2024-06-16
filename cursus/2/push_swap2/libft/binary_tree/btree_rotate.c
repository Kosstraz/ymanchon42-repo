/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:01:51 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/13 14:30:49 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include "../libft.h"
#include <stdio.h>

int	cmpptr(void *a, void *b)
{
	long	r;

	r = (long long)a - (long long)b;
	return ((int)r);
}

static void	btree_swap(t_btree **a, t_btree **b)
{
	t_btree	*tmp;

	if ((!b || !*b) || (!a || !*a))
		return ;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	btree_rotate(t_btree **root, int lr)
{
	int		lsize;
	int		rsize;
	int		b;
	t_btree	*tmp;

	lsize = btree_left_size(*root);
	rsize = btree_right_size(*root);
	b = (root && *root);
	printf("left size = %d\n", lsize);
	printf("right size = %d\n\n", rsize);
	if (lsize < rsize)
	{
		if (b && (*root)->right && lr < 0)
		{
			tmp = *root;
			*root = (*root)->right;
		}
	}
	else if (lsize > rsize)
	{
		if (b && (*root)->right && lr >= 0)
			btree_swap(root, &((*root)->left));
	}
}

/*int	main(void)
{
	int	*ez0 = malloc(1);
	int	*ez1 = malloc(1);
	int	*ez2 = malloc(1);
	int	*ez3 = malloc(1);
	int	*ez3bis = malloc(1);
	int	*ez4 = malloc(1);
	int	*ez5 = malloc(1);
	int	*ez6 = malloc(1);
	int	*ez1_ref = ez1;

	t_btree	*node;
	*ez0 = -1;
	*ez1 = 1;
	*ez2 = 2;
	*ez3 = 3;
	*ez3bis = 30;
	*ez4 = 4;
	*ez5 = 5;
	*ez6 = 6;
	node = btree_create_node(ez1);
	//btree_insert_data(&node, ez1, cmpptr);
	btree_insert_data(&node, ez0, cmpptr);
	btree_insert_data(&node, ez3, cmpptr);
	btree_insert_data(&node, ez3bis, cmpptr);
	btree_insert_data(&node, ez4, cmpptr);
	//btree_insert_data(&node, ez5, cmpptr);
	//btree_insert_data(&node, ez6, cmpptr);
	//btree_insert_data(&node, ez1_ref, cmpptr);

	btree_rotate(&node, -1);
	if (node)
		printf("%d\n", *node->item);
	else
		printf("NULL\n");

	if (node->left)
		printf("%d\n", *node->left->item);
	else
		printf("NULL\n");

	if (node->right)
		printf("%d\n", *node->right->item);
	else
		printf("NULL\n");

	if (node->right->left)
		printf("%d\n", *node->right->left->item);
	else
		printf("NULL\n");

	if (node->right->right)
		printf("%d\n", *node->right->right->item);
	else
		printf("NULL\n");
	return (0);
}
*/