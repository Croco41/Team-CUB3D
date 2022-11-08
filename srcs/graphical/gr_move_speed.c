/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_move_speed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:11:27 by cgranja           #+#    #+#             */
/*   Updated: 2022/10/26 15:11:32 by cgranja          ###   ########.fr       */
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
