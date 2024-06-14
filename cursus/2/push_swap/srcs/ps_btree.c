/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_btree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:02:40 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/14 14:24:00 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_btree_free_suffix(t_btree *root, void (*freef)(void *))
{
	if (root)
	{
		ps_btree_free_suffix(root->left, freef);
		ps_btree_free_suffix(root->right, freef);
		freef(root);
	}
}

void	ps_btree_infix(t_pbtree **root, int *i)
{
	if (root && *root)
	{
		ps_btree_infix(&(*root)->left, i);
		(*root)->item->i = (*i)++;
		ps_btree_infix(&(*root)->right, i);
	}
}

t_pbtree	*ps_btree_create_node(t_items *item)
{
	t_pbtree	*ret;

	ret = (t_pbtree *)malloc(sizeof(t_pbtree));
	if (!ret)
		return (NULL);
	ret->left = NULL;
	ret->right = NULL;
	ret->item = item;
	return (ret);
}

void	ps_btree_insert_data(t_pbtree **root, t_items *item,
			int (*cmpf)(int, int))
{
	int	cmp;

	if (!root || !*root)
	{
		*root = ps_btree_create_node(item);
		return ;
	}
	cmp = cmpf(item->data, (*root)->item->data);
	if (cmp < 0)
		ps_btree_insert_data(&(*root)->left, item, cmpf);
	else if (cmp >= 0)
		ps_btree_insert_data(&(*root)->right, item, cmpf);
}

void	ps_add_to_btree(t_stack *a)
{
	t_pbtree	*root;
	int			i;
	int			j;

	root = NULL;
	i = 0;
	while (i < a->len)
		ps_btree_insert_data(&root, &a->s[i++], btree_cmp);
	j = 0;
	ps_btree_infix(&root, &j);
	ps_btree_free_suffix(root, free);
}
