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

void	fix_fisheye(t_admin *admin)
{
	float	ca;

	ca = admin->player->pa - admin->rays->ra + PI;
	if (ca < 0)
		ca += 2 * PI;
	else if (ca > 2 * PI)
		ca -= 2 * PI;
	admin->rays->distF = fabs(admin->rays->distF * cos(ca));
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
			my_mlx_pixel_put(admin->mlx, i, j, CYAN_PIXEL);
		}
		j--;
		i = 0;
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
	lineh = ((PIX * mlx->imgame->height) / (admin->rays->distF));
	baseline = (mlx->imgame->height / 2) - (lineh / 2);
	stopline = lineh + baseline;
	case_off = baseline;
	if (baseline < 0)
		baseline = 0;
	if (admin->player->text == 'S' || admin->player->text == 'N')
	{
		admin->text->tx = (admin->rays->rx / PIX) - (int)((admin->rays->rx / PIX));
		if (admin->rays->ra < PI)
			admin->text->tx = 1 - admin->text->tx;
	}
	else
	{
		admin->text->tx = (admin->rays->ry / PIX) - (int)((admin->rays->ry / PIX));
		if (admin->rays->ra > (PI / 2) && admin->rays->ra < (3 * (PI / 2)))
			admin->text->tx = 1 - admin->text->tx;
	}
	while (baseline < stopline && baseline < mlx->imgame->height)
	{
		admin->text->ty = (baseline - case_off) / lineh;
		color = find_color(admin->text, admin->player->text);
		my_mlx_pixel_put(mlx, admin->rays->r, baseline, color);
		baseline++;
	}
}

void	choise_text(t_admin *admin, t_rays *rays)
{
	if (rays->distV < rays->distH)
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

void	drawline(t_admin *admin)
{
	double	x;

	x = 0;
	admin->rays->distF = 0;
	if (admin->rays->distV < admin->rays->distH)
	{
		admin->rays->rx = admin->rays->vx;
		admin->rays->ry = admin->rays->vy;
		admin->rays->distF = admin->rays->distV;
	}
	else if (admin->rays->distH <= admin->rays->distV)
	{
		admin->rays->rx = admin->rays->hx;
		admin->rays->ry = admin->rays->hy;
		admin->rays->distF = admin->rays->distH;
	}
	choise_text(admin, admin->rays);
}
