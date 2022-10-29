/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:22:27 by cgranja           #+#    #+#             */
/*   Updated: 2022/10/10 15:22:33 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx_text(t_admin *admin)
{
	admin->mlx->mlx_ptr = NULL;
	admin->mlx->mlx_win = NULL;
	admin->mlx->imgame = NULL;
	admin->text->TE = NULL;
	admin->text->TW = NULL;
	admin->text->TS = NULL;
	admin->text->TN = NULL;
}

void	init_map(t_admin *admin)
{
	admin->map->other = 0;
	admin->map->error = 0;
	admin->map->sizeline = 0;
	admin->map->nbline = 0;
	admin->map->px = -1;
	admin->map->py = -1;
	admin->map->reduc = 1;
}

void	init_player(t_admin *admin)
{
	admin->player->key_r = 0;
	admin->player->key_l = 0;
	admin->player->key_w = 0;
	admin->player->key_s = 0;
	admin->player->move = 0;
	admin->player->key_fr = 0;
	admin->player->key_fl = 0;
	admin->player->x = 0;
	admin->player->y = 0;
	admin->player->pa = 0;
	admin->player->pdx = cos(admin->player->pa) * 5;
	admin->player->pdy = sin(admin->player->pa) * 5;
}

void	init_rays(t_admin *admin)
{
	admin->rays->dof = 0;
	admin->rays->map_dof = 0;
	admin->rays->mp = 0;
	admin->rays->mx = 0;
	admin->rays->my = 0;
	admin->rays->r = 0;
	admin->rays->rx = 0;
	admin->rays->ry = 0;
	admin->rays->ra = 0;
	admin->rays->xo = 0;
	admin->rays->yo = 0;
}

void	init_struct(t_admin *admin)
{
	init_mlx_text(admin);
	init_map(admin);
	init_rays(admin);
	init_player(admin);
}
