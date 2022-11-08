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

int	pushaway_player(int pdxy)
{
	if (pdxy < 0)
		return (-15);
	return (15);
}

//Fonctions pour avancer avec les touches w et s
void	move_up(t_map *map, t_player *player)
{
	int		next_x;
	int		next_y;
	int		x;
	int		y;
	char	*p;

	p = "NSEW";
	x = pushaway_player(player->pdx);
	y = pushaway_player(player->pdy);
	next_x = ((player->px + player->pdx + x) / PIX);
	next_y = ((player->py + player->pdy + y) / PIX);
	if (map->map[get_int(next_x, (player->py / PIX), map)] == 0
		|| ft_strchr(map->map[get_int(next_x, (player->py / PIX), map)], p))
		player->px += player->pdx * SPEED;
	if (map->map[get_int((player->px / PIX), next_y, map)] == 0
		|| ft_strchr(map->map[get_int((player->px / PIX), next_y, map)], p))
		player->py += player->pdy * SPEED;
}

void	move_down(t_map *map, t_player *player)
{
	int		next_x;
	int		next_y;
	int		x;
	int		y;
	char	*p;

	p = "NSEW";
	x = pushaway_player(player->pdx);
	y = pushaway_player(player->pdy);
	next_x = ((player->px - player->pdx - x) / PIX);
	next_y = ((player->py - player->pdy - y) / PIX);
	if (map->map[get_int(next_x, (player->py / PIX), map)] == 0
		|| ft_strchr(map->map[get_int(next_x, (player->py / PIX), map)], p))
		player->px -= player->pdx * SPEED;
	if (map->map[get_int((player->px / PIX), next_y, map)] == 0
		|| ft_strchr(map->map[get_int((player->px / PIX), next_y, map)], p))
		player->py -= player->pdy * SPEED;
}

void	move_right(t_map *map, t_player *player)
{
	int		next_x;
	int		next_y;
	int		x;
	int		y;
	char	*p;

	p = "NSEW";
	x = pushaway_player(player->pdx);
	y = pushaway_player(player->pdy);
	next_x = ((player->px - player->pdy - y) / PIX);
	next_y = ((player->py + player->pdx + x) / PIX);
	if (map->map[get_int(next_x, (player->py / PIX), map)] == 0
		|| ft_strchr(map->map[get_int(next_x, (player->py / PIX), map)], p))
		player->px -= player->pdy * SPEED;
	if (map->map[get_int((player->px / PIX), next_y, map)] == 0
		|| ft_strchr(map->map[get_int((player->px / PIX), next_y, map)], p))
		player->py += player->pdx * SPEED;
}

void	move_left(t_map *map, t_player *player)
{
	int		next_x;
	int		next_y;
	int		x;
	int		y;
	char	*p;

	p = "NSEW";
	x = pushaway_player(player->pdx);
	y = pushaway_player(player->pdy);
	next_x = ((player->px + player->pdy + y) / PIX);
	next_y = ((player->py - player->pdx - x) / PIX);
	if (map->map[get_int(next_x, (player->py / PIX), map)] == 0
		|| ft_strchr(map->map[get_int(next_x, (player->py / PIX), map)], p))
		player->px += player->pdy * SPEED;
	if (map->map[get_int((player->px / PIX), next_y, map)] == 0
		|| ft_strchr(map->map[get_int((player->px / PIX), next_y, map)], p))
		player->py -= player->pdx * SPEED;
}
