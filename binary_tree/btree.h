/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:22:47 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/07 12:46:57 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_H
# define BTREE_H

# define BTREE_ROTATION_THRESOLD 1

# include <stdlib.h>

/*typedef struct s_rbbtree
{
	void			*item;
	char			color;
	struct s_rbtree	*left;
	struct s_rbtree	*right;
}	t_rbbtree;*/

typedef struct s_btree
{
	int			*item;
	struct s_btree	*left;
	struct s_btree	*right;
}	t_btree;

// Creer un noeud
t_btree	*btree_create_node(int *item);
// Applique une fonction sur tous les items de l'arbre
// Le parcours de gauche à droite
void	btree_apply_prefix(t_btree *root, void (*applyf)(void *));
// Applique une fonction sur tous les items de l'arbre
// Le parcours par le dessous
void	btree_apply_infix(t_btree *root, void (*applyf)(void *));
// Applique une fonction sur tous les items de l'arbre
// Le parcours de droite à gauche
void	btree_apply_suffix(t_btree *root, void (*applyf)(void *));
// Insert une donnée dans l'arbre binaire à partir de la racine donnée
// Il sera trié de telle sorte à ce que les éléments les plus à gauches soit inférieurs à ceux le plus à droite
void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));
// Recherche les éléments de manière infixe
void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));
// La taille gauche de l'arbre
void	btree_left_size(t_btree *root, int *count);
// La taille droite de l'arbre
void	btree_right_size(t_btree *root, int *count);
// La taille de l'arbre
void	btree_size(t_btree *root, int *size);
// Fait une rotation des éléments, permettant notamment de trier l'arbre
void	btree_rotate(t_btree **root);
// Pour le debug essentiellement
void	btree_show_tree(t_btree *root);

#endif