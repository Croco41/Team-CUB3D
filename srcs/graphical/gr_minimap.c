/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <cgranja@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:49:39 by cgranja           #+#    #+#             */
/*   Updated: 2022/11/07 21:32:51 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	size_minimap(t_map *map)
{
	int	sizel;
	int	sizeh;

	sizel = W_WIDTH * 5 / 100;
	sizeh = W_HEIGHT * 5 / 100;
	if (sizel < sizeh)
		map->reduc = (sizel * 100) / (map->sizeline * PIX);
	else
		map->reduc = (sizeh * 100) / (map->nbline * PIX);
	if (map->reduc % 2 == 1)
		map->reduc += 1;
	map->reduc = 30;
}

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
	while (j < py + PIX / map->reduc)
	{
		while (i < px + PIX / map->reduc)
		{
			if (i == (px + PIX / map->reduc) - 1
				|| (j == (py + PIX / map->reduc) - 1))
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
	while (x < map->mapsur)
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
