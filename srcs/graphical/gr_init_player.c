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


void init_player_position(t_map *map, t_player *player)
{
	int	p;

	p = 0;

	while (p < PIX)
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
}