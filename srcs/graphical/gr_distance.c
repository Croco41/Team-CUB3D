/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_distance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:44:00 by cgranja           #+#    #+#             */
/*   Updated: 2022/10/29 22:44:17 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_dist(double px, double py, double hvx, double hvy)
{
	return (sqrt((hvx - px) * (hvx - px) + (hvy - py) * (hvy - py)));
}

void	get_dist_hv(t_player *player, t_rays *rays, int order)
{
	if (order == 0)
	{
		rays->hx = rays->rx;
		rays->hy = rays->ry;
		rays->disth = get_dist(player->px, player->py, rays->hx, rays->hy);
	}
	else if (order == 1)
	{
		rays->vx = rays->rx;
		rays->vy = rays->ry;
		rays->distv = get_dist(player->px, player->py, rays->vx, rays->vy);
	}
	rays->dof = rays->map_dof;
}

void	choosedistfinal(t_admin *admin)
{
	double	x;

	x = 0;
	admin->rays->distfin = 0;
	if (admin->rays->distv < admin->rays->disth)
	{
		admin->rays->rx = admin->rays->vx;
		admin->rays->ry = admin->rays->vy;
		admin->rays->distfin = admin->rays->distv;
	}
	else if (admin->rays->disth <= admin->rays->distv)
	{
		admin->rays->rx = admin->rays->hx;
		admin->rays->ry = admin->rays->hy;
		admin->rays->distfin = admin->rays->disth;
	}
	choose_text(admin, admin->rays);
}
