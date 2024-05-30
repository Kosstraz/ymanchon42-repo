/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:48:13 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/30 19:15:52 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef WTITLE
#  define WTITLE "FdF de l'enfer !!"
# endif

# ifndef WRES_X
#  define WRES_X 999
# endif

# ifndef WRES_Y
#  define WRES_Y 999
# endif

# define MAPOFFSET 15

# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define WHITE 0x00FFFFFF

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
# include "mlx_int.h"
# include "libft.h"
# include "mlx.h"

// je t'aime <3
typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

// je t'aime <3
typedef struct s_vec2
{
	int	x;
	int	y;
}	t_vec2;

// je t'aime <3
typedef struct s_data
{
	void	*mlx;
	void	*window;
	int		point_count;
	t_point	*map;
	t_vec2	map_size;
}	t_data;

////////////////// Gestion des erreurs
/*  FDF_ERRORS  */
//////////////////

// je t'aime <3
// !!! Pas sécurisé <=> Not safe !!!
// Affiche le message d'erreur sur la sortie 2 et exit avec le code erreur donné
int		printexit(const char *strerror, int errcode);

///////////////// Gestion des hooks
/*  FDF_HOOKS  */
/////////////////

int		close_event(t_data *datas);
int		mlx_set_all_hooks(t_data *datas);

///////////////////// Parsing
/*   FDF_PARSING   */
/////////////////////

// je t'aime <3
// Parse le format du fichier pour connaître sa validité
// Fichier en .fdf seulement
char	fdf_file_format(const char *file_path);
// Lit le fichier .fdf et parse la map
// @return Un tableau de points : (x, y, z)
t_point	*ft_read_fdfmap(const char *file_path, t_data *datas);

/////////////////////// Rendu graphique
/*   FDF_RENDERING   */
///////////////////////

int		fdf_draw_map(t_data *datas);

/////////////////// Fonctions utilitaires
/*   FDF_UTILS   */
///////////////////
// je t'aime <3
void	init_point(t_point *point);
// je t'aime <3
void	add_point(t_point *point, int x, int y, int z);
// je t'aime <3
// @return 1 si tous les points sont egaux a 'val', sinon 0
char	if_point_eq(t_point point, int val);
// je t'aime <3
void	show_points(t_point *points);

#endif