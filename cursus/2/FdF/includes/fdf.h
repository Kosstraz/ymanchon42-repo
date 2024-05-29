/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:48:13 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/29 18:54:09 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef WINDOW_T
#  define WINDOW_T "FdF de l'enfer !!"
# endif

# define PT_OFFSET 100

# define NULL_POINT INT_MIN
# define BAD_MALLOC "Erreur d'allocation avec malloc. Fin du programme.\n"
# define INVALID_FILE "Le fichier n'a pas pu être lu :( \
veuillez saisir un fichier valide!\n"
# define NO_FDFFILE "L'argument passé en paramètre est invalide, \
assurez-vous d'insérer un fichier au format .fdf\n"
# define MANY_FILE "Le programme ne prend en compte qu'un seul argument\n"
# define NO_FILE "Veuillez passer un fichier en format .fdf \
en paramètre de programme.\n"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_vec2
{
	int	x;
	int	y;
}	t_vec2;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
}	t_mlx;

////////////////// Gestion des erreurs
/*  FDF_ERRORS  */
//////////////////

// !!! Pas sécurisé <=> Not safe !!!
// Affiche le message d'erreur sur la sortie 2 et exit avec le code erreur donné
int		printexit(const char *strerror, int errcode);

///////////////////// Parsing
/*   FDF_PARSING   */
/////////////////////

// Parse le format du fichier pour connaître sa validité
// Fichier en .fdf seulement
char	fdf_file_format(const char *file_path);
// Lit le fichier .fdf et parse la map
// @return Un tableau de points : (x, y, z)
t_point	*ft_read_fdfmap(const char *file_path, t_vec2 *map_size);

/////////////////// Fonctions utilitaires
/*   FDF_UTILS   */
///////////////////

void	init_point(t_point *point);
void	add_point(t_point *point, int x, int y, int z);
// @return 1 si tous les points sont egaux a 'val', sinon 0
char	if_point_eq(t_point point, int val);
void	show_points(t_point *points);

#endif