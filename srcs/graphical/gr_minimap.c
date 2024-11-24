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

void	drawMap2D(t_mlx *mlx, t_map *map)
{
	int	x;

	x = 0;
	while (x < 64)
	{
		if (map->map[x] == 1)
		{
			if (get_coord(x, map) == 0)
				color_cube(mlx, map, WHITE_PIXEL);
		}
		else if (map->map[x] == 0)
		{
			if (get_coord(x, map) == 0)
				color_cube(mlx, map, GRAY_PIXEL);
		}
		x++;
	}
}
