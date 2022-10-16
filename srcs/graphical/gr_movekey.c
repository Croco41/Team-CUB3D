/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_movekey.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:55:49 by cgranja           #+#    #+#             */
/*   Updated: 2022/10/11 14:55:51 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//fonctions pour tourner(orientation du player) avec les touches a et d

void	turn_right(t_player *player)
{
	player->pa += 0.1;
	if (player->pa > 2 * PI)
		player->pa -= 2 * PI;
	player->pdx = cos(player->pa) * 5;
	player->pdy = sin(player->pa) * 5;
}

void	turn_left(t_player *player)
{
	player->pa -= 0.1;
	if (player->pa < 0)
		player->pa += 2 * PI;
	player->pdx = cos(player->pa) * 5;
	player->pdy = sin(player->pa) * 5;
}

//Fonctions pour avancer avec les touches w et s

void	move_up(t_map *map, t_player *player)
{
	int	next_x;
	int	next_y;

	next_x = ((player->px + player->pdx) / map->mapS);
	next_y = ((player->py + player->pdy) / map->mapS);
//printf(GREEN"ICIW119 [pdx] %f | [pdy] %f "RESET"\n", admin->player->pdx, admin->player->pdy);
	if (map->map[get_int(next_x, (player->py / map->mapS), map)] == 0)
		player->px += player->pdx;
	if (map->map[get_int((player->px / map->mapS), next_y, map)] == 0)
		player->py += player->pdy;
}

void	move_down(t_map *map, t_player *player)
{
	int	next_x;
	int	next_y;

	next_x = ((player->px - player->pdx) / map->mapS);
	next_y = ((player->py - player->pdy) / map->mapS);
	if (map->map[get_int(next_x, (player->py / map->mapS), map)] == 0)
		player->px -= player->pdx;
	if (map->map[get_int((player->px / map->mapS), next_y, map)] == 0)
		player->py -= player->pdy;
}
