/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_applyptr_prefix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:27:43 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/13 17:41:07 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	btree_applyptr_prefix(t_btree **root, void (*applyf)(T_BTREE))
{
	if (root && *root)
	{
		applyf(&(*root)->item);
		btree_applyptr_prefix((*root)->left, applyf);
		btree_applyptr_prefix((*root)->right, applyf);
	}
}
