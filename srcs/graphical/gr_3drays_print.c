/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_3drays_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <cgranja@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:47:30 by cgranja           #+#    #+#             */
/*   Updated: 2022/11/07 21:49:51 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fix_fisheye(t_admin *admin)
{
	float	ca;

	ca = admin->player->pa - admin->rays->ra + PI;
	if (ca < 0)
		ca += 2 * PI;
	else if (ca > 2 * PI)
		ca -= 2 * PI;
	admin->rays->distfin = fabs(admin->rays->distfin * cos(ca));
}

void	draw_floor(t_admin *admin)
{
	int	i;
	int	j;

	j = admin->mlx->imgame->height / 2;
	i = 0;
	while (j > 0)
	{
		while (++i < admin->mlx->imgame->width)
		{
			my_mlx_pixel_put(admin->mlx, i, j, admin->map->cel);
		}
		j--;
		i = 0;
	}
}

void	draw_good_wall(t_admin *admin, t_rays *rays)
{
	if (admin->player->text == 'S' || admin->player->text == 'N')
	{
		admin->map->tx = (rays->rx / PIX) - (int)((rays->rx / PIX));
		if (rays->ra < PI)
			admin->map->tx = 1 - admin->map->tx;
	}
	else
	{
		admin->map->tx = (rays->ry / PIX) - (int)((rays->ry / PIX));
		if (rays->ra > (PI / 2) && rays->ra < (3 * (PI / 2)))
			admin->map->tx = 1 - admin->map->tx;
	}
}

void	draw_wall(t_admin *admin, t_mlx *mlx)
{
	int		lineh;
	int		baseline;
	int		stopline;
	int		color;
	float	case_off;

	fix_fisheye(admin);
	lineh = ((PIX * mlx->imgame->height) / (admin->rays->distfin));
	baseline = (mlx->imgame->height / 2) - (lineh / 2);
	stopline = lineh + baseline;
	case_off = baseline;
	if (baseline < 0)
		baseline = 0;
	draw_good_wall(admin, admin->rays);
	while (baseline < stopline && baseline < mlx->imgame->height)
	{
		admin->map->ty = (baseline - case_off) / lineh;
		color = find_color(admin->map, admin->player->text);
		my_mlx_pixel_put(mlx, admin->rays->r, baseline, color);
		baseline++;
	}
}

void	choose_text(t_admin *admin, t_rays *rays)
{
	if (rays->distv < rays->disth)
	{
		if (rays->ra <= (PI / 2) || rays->ra > (3 * (PI / 2)))
			admin->player->text = 'E';
		if (rays->ra > (PI / 2) && rays->ra <= (3 * (PI / 2)))
			admin->player->text = 'W';
	}
	else
	{
		if (rays->ra >= 0 && rays->ra < PI)
			admin->player->text = 'S';
		if (rays->ra >= PI && rays->ra < (2 * PI))
			admin->player->text = 'N';
	}
}

// void	choosedistfinal(t_admin *admin)
// {
// 	double	x;

// 	x = 0;
// 	admin->rays->distfin = 0;
// 	if (admin->rays->distv < admin->rays->disth)
// 	{
// 		admin->rays->rx = admin->rays->vx;
// 		admin->rays->ry = admin->rays->vy;
// 		admin->rays->distfin = admin->rays->distv;
// 	}
// 	else if (admin->rays->disth <= admin->rays->distv)
// 	{
// 		admin->rays->rx = admin->rays->hx;
// 		admin->rays->ry = admin->rays->hy;
// 		admin->rays->distfin = admin->rays->disth;
// 	}
// 	choose_text(admin, admin->rays);
// }
