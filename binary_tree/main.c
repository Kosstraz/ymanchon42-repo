/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:25:23 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/06 21:53:53 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include <stdio.h>

int	ptrcmp(void *p1, void *p2)
{
	if (p1 < p2)
		return (-1);
	else if (p1 > p2)
		return (1);
	return (0);
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

	/*ez4_ref = btree_search_item(node, ez4_ref, &ptrcmp);
	printf("p4 == %p\nre == %p\n", ez1, ez4_ref);
	printf("ptrcmp == %d\n", ptrcmp(ez1, ez4_ref));
	printf("p4 == %p\nre == %p\n", ez1, ez4_ref);*/
	return (0);
}