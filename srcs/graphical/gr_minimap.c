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

void	color_cube(t_mlx *mlx, t_map *map, int color)
{
	int	i;
	int	j;

	map->px *= map->mapS;
	map->py *= map->mapS;
	i = map->mapS - 1;
	j = 0;
	while (j < map->mapS - 1)
	{
		while (i > 0)
		{
			my_mlx_pixel_put(mlx, map->px + i, map->py + j, color);
			i--;
		}
		i = map->mapS - 1;
		j++;
	}
}

void	color_cube_bonus(t_mlx *mlx, t_map *map, int color)
{
	int	i;
	int	j;
	int px;
	int py;

	px = map->px * PIX / map->reduc;
	py = map->py * PIX / map->reduc;
	i = px;
	j = py;
	while (j < py + map->mapS / map->reduc)
	{
		while (i < px + map->mapS / map->reduc)
		{
			if (i == (px + map->mapS / map->reduc) - 1 || (j == (py + map->mapS / map->reduc) -1))
				my_mlx_pixel_put(mlx, i, j, BLACK_PIXEL);
			else
				my_mlx_pixel_put(mlx, i, j, color);
			i += 2;
		}
		i = px;
		j += 2;
	}
}

void	drawMap2D(t_mlx *mlx, t_map *map)
{
	int	x;

	x = 0;
	while (x < PIX)
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
		x++;
	}
}
