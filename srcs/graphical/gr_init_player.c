/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:59:34 by cgranja           #+#    #+#             */
/*   Updated: 2022/10/28 14:00:02 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player_position(t_map *map, t_player *player, t_rays *rays)
{
	int	p;

	p = 0;
	if (map->sizeline > map->nbline)
		rays->map_dof = map->sizeline;
	else
		rays->map_dof = map->nbline;
	while (p < map->mapS)
	{
		if (ft_strchr(map->map[p], "NSEW"))
		{
			get_coord(p, map);
			player->px = map->px * PIX + (PIX / 2);
			player->py = map->py * PIX + (PIX / 2);
			if (map->map[p] == 'N')
				player->pa = (3 * PI) / 2;
			else if (map->map[p] == 'S')
				player->pa = PI / 2;
			else if (map->map[p] == 'E')
				player->pa = 0;
			else if (map->map[p] == 'W')
				player->pa = PI;
		}
		p++;
	}
	player->pdx = cos(player->pa) * 5;
	player->pdy = sin(player->pa) * 5;
}
