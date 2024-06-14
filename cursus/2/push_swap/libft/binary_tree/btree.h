/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:22:47 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/13 18:02:18 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_H
# define BTREE_H

# ifndef T_BTREE
#  define T_BTREE int	
# endif

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
	T_BTREE			item;
	struct s_btree	*left;
	struct s_btree	*right;
}	t_btree;

// Ne fonctionne pas avec les str (-> ft_strcmp)
// Ne fonctionne pas avec les flottants (-> ft_fpcmp)
int		btree_cmp(T_BTREE a, T_BTREE b);
// Creer un noeud
t_btree	*btree_create_node(T_BTREE item);
// Applique une fonction sur tous les items de l'arbre
// Le parcours de gauche à droite
void	btree_apply_prefix(t_btree *root, void (*applyf)(T_BTREE));
// Applique une fonction sur tous les items de l'arbre
// Le parcours par le dessous
void	btree_apply_infix(t_btree *root, void (*applyf)(T_BTREE));
// Applique une fonction sur tous les items de l'arbre
// Le parcours de droite à gauche
void	btree_apply_suffix(t_btree *root, void (*applyf)(T_BTREE));
void	btree_applyptr_prefix(t_btree **root, void (*applyf)(T_BTREE));
void	btree_applyptr_infix(t_btree **root, void (*applyf)(T_BTREE));
void	btree_applyptr_suffix(t_btree **root, void (*applyf)(T_BTREE));
// Insert une donnée dans l'arbre binaire à partir de la racine donnée
/* Il sera trié de telle sorte à ce que les éléments les plus à gauches soit
inférieurs à ceux le plus à droite */
void	btree_insert_data(t_btree **root, T_BTREE item,
			int (*cmpf)(T_BTREE, T_BTREE));
// Recherche les éléments de manière infixe
T_BTREE	btree_search_item(t_btree *root, const T_BTREE data_ref,
			int (*cmpf)(T_BTREE, T_BTREE));
// La taille de l'arbre, cote gauche, strictement
int		btree_strictleft_size(t_btree *tree);
// La taille de l'arbre, cote droit, strictement
int		btree_strictright_size(t_btree *tree);
// La taille gauche de l'arbre
int		btree_left_size(t_btree *root);
// La taille droite de l'arbre
int		btree_right_size(t_btree *root);
// La taille de l'arbre
int		btree_size(t_btree *root);
// Fait une rotation des éléments, permettant notamment de trier l'arbre
void	btree_rotate(t_btree **root, int lr);

#endif