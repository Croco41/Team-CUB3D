/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_3drays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:44:56 by cgranja           #+#    #+#             */
/*   Updated: 2022/10/10 17:45:00 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Rays_distancecheck:
//order = 0 -> on frappe une horizontale (un mur)
//order = 1 -> une verticale
//rays->dof += 1; // next line
void	rays_distcheck(t_player *player, t_rays *rays, t_map *map, int order)
{
	while (rays->dof < rays->map_dof)
	{
		rays->mx = (int)(rays->rx) >> 6;
		rays->my = (int)(rays->ry) >> 6;
		rays->mp = rays->my * map->sizeline + rays->mx;
		if (rays->mp > 0 && rays->mp < map->mapsur && map->map[rays->mp] == 1)
		{
			get_dist_hv(player, rays, order);
			rays->dof = rays->map_dof;
		}
		else
		{
			rays->rx += rays->xo;
			rays->ry += rays->yo;
			rays->dof += 1;
		}
	}
	rays->dof = 0;
}

//rays->ra > PI => looking down
//rays->ra < PI => looking up
//rays->ra == 0 || rays->ra == PI => looking straight left or right
//s'assurer qu'on soit en float et decalage de 6 bits
void	rays_horizontalcheck(t_player *player, t_rays *rays)
{
	double	atan;

	rays->hx = player->px;
	rays->hy = player->py;
	atan = -1 / (tan(rays->ra));
	if (rays->ra > PI)
	{
		rays->ry = (((int)(player->py) >> 6) << 6) - 0.0001;
		rays->rx = (player->py - rays->ry) * atan + player->px;
		rays->yo = -64;
		rays->xo = -rays->yo * atan;
	}
	else if (rays->ra < PI)
	{
		rays->ry = (((int)(player->py) >> 6) << 6) + 64;
		rays->rx = (player->py - rays->ry) * atan + player->px;
		rays->yo = 64;
		rays->xo = -rays->yo * atan;
	}
	else if (rays->ra == 0 || rays->ra == PI)
	{
		rays->rx = player->px;
		rays->ry = player->py;
		rays->dof = rays->map_dof;
	}
}

//rays->ra > PI / 2 && rays->ra < (3 * PI)/2 => looking left
//rays->ra < PI / 2 || rays->ra > (3 * PI)/2 => looking right
//rays->ra == PI / 2 || rays->ra == (3 * PI)/2 => looking up or down
//s'assurer qu'on soit en float et decalage de 6 bits 
void	rays_verticalcheck(t_player *player, t_rays *rays)
{
	double	ntan;

	ntan = -(tan(rays->ra));
	if (rays->ra > PI / 2 && rays->ra < (3 * PI) / 2)
	{
		rays->rx = (((int)(player->px) >> 6) << 6) - 0.0001;
		rays->ry = (player->px - rays->rx) * ntan + player->py;
		rays->xo = -64;
		rays->yo = -rays->xo * ntan;
	}
	else if (rays->ra < PI / 2 || rays->ra > (3 * PI) / 2)
	{
		rays->rx = (((int)(player->px) >> 6) << 6) + 64;
		rays->ry = (player->px - rays->rx) * ntan + player->py;
		rays->xo = 64;
		rays->yo = -rays->xo * ntan;
	}
	else if (rays->ra == PI / 2 || rays->ra == (3 * PI) / 2)
	{
		rays->rx = player->px;
		rays->ry = player->py;
		rays->dof = rays->map_dof;
	}
}

void	drawrays3d_angle(t_rays *rays)
{
	if (rays->ra < 0)
		rays->ra += 2 * PI;
	if (rays->ra > 2 * PI)
		rays->ra -= 2 * PI;
}

void	drawrays3d(t_admin *admin, t_player *player, t_rays *rays, t_map *map)
{
	rays->ra = player->pa - DR * 30;
	drawrays3d_angle(rays);
	admin->rays->r = 0;
	while (rays->r < (W_WIDTH))
	{
		rays->disth = 1000000.0;
		rays->distv = 1000000.0;
		rays->hx = player->px;
		rays->hy = player->py;
		rays->vx = player->px;
		rays->vy = player->py;
		rays_horizontalcheck(player, rays);
		rays_distcheck(player, rays, map, 0);
		rays_verticalcheck(player, rays);
		rays_distcheck(player, rays, map, 1);
		choosedistfinal(admin);
		draw_wall(admin, admin->mlx);
		rays->ra += DR * ((60 / 1500.0));
		drawrays3d_angle(rays);
		rays->r++;
	}
}
