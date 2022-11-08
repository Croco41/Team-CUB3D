/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_close_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:03:22 by ebarguil          #+#    #+#             */
/*   Updated: 2022/11/02 20:04:39 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_verify_close(t_map *map, int x, int y)
{
	int	yy;
	int	xx;

	yy = y - 1;
	xx = x - 1;
	while (yy != y + 2)
	{
		if (yy < 0 || yy > map->nbline)
			return (false);
		while (xx != x + 2)
		{
			if (xx < 0 || xx > map->sizeline || map->om[yy][xx] == ' ')
				return (false);
			xx++;
		}
		yy++;
	}
	return (true);
}

bool	ft_verify_close_map(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (map->om[++y])
	{
		x = -1;
		while (map->om[y][++x])
			if (ft_strchr(map->om[y][x], "0NSEW"))
				if (!ft_verify_close(map, x, y))
					return (false);
	}
	return (true);
}
