/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <cgranja@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:34:21 by ebarguil          #+#    #+#             */
/*   Updated: 2022/11/07 19:33:43 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_check_char(char **map, int y, int p)
{
	int	x;
	int	m;

	while (map[++y])
	{
		x = -1;
		m = 0;
		while (map[y][++x])
		{
			if (!ft_strchr(map[y][x], "01NSEW "))
				return (false);
			if (ft_strchr(map[y][x], "01NSEW"))
				m++;
			if (ft_strchr(map[y][x], "NSEW"))
				p++;
		}
		if (!m)
			return (false);
	}
	if (p != 1)
		return (false);
	return (true);
}

/*

	y = -1;
	i = -1;
	while (map->om[++y])
	{
		printf(BBLUE"[");
		x = -1;
		while (map->om[y][++x])
			printf("%d", map->map[++i]);
		printf("]"RESET"\n");
	}

*/

int	ft_save_map(t_map *map)
{
	int	x;
	int	y;
	int	i;

	if (!ft_check_char(map->om, -1, 0))
		return (1);
	if (ft_retouch(map))
		return (1);
	if (!ft_verify_close_map(map))
		return (1);
	map->map = malloc(sizeof(int) * (map->sizeline * map->nbline));
	if (!map->map)
		return (ft_error_int("Exception malloc (ft_save_map)", 1));
	y = -1;
	i = -1;
	while (map->om[++y])
	{
		x = -1;
		while (map->om[y][++x])
			map->map[++i] = ft_atoi_c(map->om[y][x]);
	}
	map->map_ok = true;
	return (0);
}
