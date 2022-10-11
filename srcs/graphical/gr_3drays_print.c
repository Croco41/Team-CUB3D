/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_3drays_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:47:30 by cgranja           #+#    #+#             */
/*   Updated: 2022/10/10 17:47:33 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_dist(double px, double py, double hx, double hy)
{
	return (sqrt((hx - px) * (hx - px) + (hy - py) * (hy - py)));
}

void	drawLine(t_admin *admin, t_mlx *mlx)
{
//printf(GREEN"player->px = %d | player->py = %d | adresse player= %p"RESET"\n", admin->player->px, admin->player->py, admin->player );
	double	x;
	double	dist;
	double	finalx;
	double	finaly;

	x = 0;
	if (admin->rays->distV < admin->rays->distH)
	{
		admin->rays->rx = admin->rays->vx;
		admin->rays->ry = admin->rays->vy;
	}
	else if (admin->rays->distH < admin->rays->distV)
	{
		admin->rays->rx = admin->rays->hx;
		admin->rays->ry = admin->rays->hy;
	}
	dist = sqrt((admin->rays->rx - admin->player->px) * (admin->rays->rx - admin->player->px) + (admin->rays->ry - admin->player->py) * (admin->rays->ry - admin->player->py));
	while (x < 100)
	{
		// dist = admin->player->px + (cos(admin->rays->ra) * x * (admin->rays->rx /100));
		finalx = admin->player->px + (cos(admin->rays->ra) * x * (dist / 100));
		finaly = admin->player->py + (sin(admin->rays->ra) * x * (dist / 100));
		//my_mlx_pixel_put(mlx, admin->player->px + admin->player->pdx*x , admin->player->py + admin->player->pdy*x, GREEN_PIXEL);
		// my_mlx_pixel_put(mlx, admin->player->px + admin->rays->rx*x , admin->player->py + admin->rays->ry*x, GREEN_PIXEL);
		if (admin->player->px < admin->map->sizeline * 64 && admin->player->py < admin->map->nbline * 64)
		{
			//my_mlx_pixel_put(mlx, dist, admin->player->py, GREEN_PIXEL);
			my_mlx_pixel_put(mlx, finalx, finaly, GREEN_PIXEL);
		}	
		x++;
	}
}
