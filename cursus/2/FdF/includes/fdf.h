/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:48:13 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/29 00:32:01 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

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
# include "ft_printf.h"
# include "libft.h"

typedef struct s_vec3
{
	int	x;
	int	y;
	int	z;
}	t_vec3;

////////////////// Gestion des erreurs
/*  FDF_ERRORS  */
//////////////////

// !!! Pas sécurisé <=> Not safe !!!
// Affiche le message d'erreur sur la sortie 2 et exit avec le code erreur donné
int		ft_printexit(const char *strerror, int errcode);
// Free en cascade un double tableau
void	freefall(void **ptr2, int count);

///////////////////// Parsing
/*   FDF_PARSING   */
/////////////////////

// Parse le format du fichier pour connaître sa validité
char	fdf_file_format(const char *file_path);
// Lit le fichier .fdf et parse la map
// @return Le double tableau des coordonnées : [y][x]
int	**ft_read_fdfmap(const char *file_path, t_vec3 *map_size);

/////////////////// Fonctions utilitaires
/*   FDF_UTILS   */
///////////////////

// Initialise un vec3 donné, x=0 & y=0
void	init_vec3(t_vec3 *vec3);

#endif