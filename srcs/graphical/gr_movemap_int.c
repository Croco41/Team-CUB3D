/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_movemap_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:51:37 by cgranja           #+#    #+#             */
/*   Updated: 2022/10/10 17:51:39 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//petite fonction pour se deplacer dans le tableau d'int (1 et 0) representant
//la map. Ici on rentre un x et un y comme si on etait en double tab, renvoie
// le bon int 
int	get_int(int x, int y, t_map *map)
{
	if (y == 0)
		return (x);
	else if (y > 0 && y < map->nbline && x < map->sizeline)
	{
		return ((y * map->sizeline) + x);
	}
	else
	{
		printf("Erreur de coordonnees");
		return (-1);
	}
}

//Ici grace au int donne les coordonnees et 
//les enregistre dans px, py(posiion player)
int	get_coord(int x, t_map *map)
{
	if (x < 0 || x > map->mapS)
	{
		map->px = -1;
		map->py = -1;
		printf("Erreur de coordonnees");
		return (-1);
	}
	else if (x < map->sizeline)
	{
		map->px = x;
		map->py = 0;
	}
	else if (x >= map->sizeline && x < map->mapS)
	{
		map->py = x / map->sizeline;
		map->px = x - (map->py * map->sizeline);
	}
	return (0);
}
