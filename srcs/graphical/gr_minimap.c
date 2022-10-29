/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:49:39 by cgranja           #+#    #+#             */
/*   Updated: 2022/10/10 17:49:44 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//COLOR_CUBE_BONUS: ici on colorie chaque cube avec la couleur donee 
//dans drawmap2d, avec une ligne de separation en  black pixel entre les cases
void	color_cube_bonus(t_mlx *mlx, t_map *map, int color)
{
	int	i;
	int	j;
	int	px;
	int	py;

	px = map->px * PIX / map->reduc;
	py = map->py * PIX / map->reduc;
	i = px;
	j = py;
	while (j < py + map->mapS / map->reduc)
	{
		while (i < px + map->mapS / map->reduc)
		{
			if (i == (px + map->mapS / map->reduc) - 1
				|| (j == (py + map->mapS / map->reduc) - 1))
				my_mlx_pixel_put(mlx, i, j, BLACK_PIXEL);
			else
				my_mlx_pixel_put(mlx, i, j, color);
			i += 2;
		}
		i = px;
		j += 2;
	}
}

//DRAWMAP2D: Bonus pour minimap, ici on identifie les murs (=1) en Gray,
// le sol(=0) en White et le player(N ou S ou E ou W)
void	drawmap2d(t_mlx *mlx, t_map *map)
{
	int	x;

	x = 0;
	while (x < map->mapS)
	{
		if (map->map[x] == 1)
		{
			if (get_coord(x, map) == 0)
				color_cube_bonus(mlx, map, WHITE_PIXEL);
		}
		else if (map->map[x] == 0)
		{
			if (get_coord(x, map) == 0)
				color_cube_bonus(mlx, map, GRAY_PIXEL);
		}
		else if (ft_strchr(map->map[x], "NSEW"))
		{
			if (get_coord(x, map) == 0)
				color_cube_bonus(mlx, map, GRAY_PL_PIXEL);
		}
		x++;
	}
}
