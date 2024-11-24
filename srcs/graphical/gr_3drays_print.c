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

double	get_dist(double px, double py, double hvx, double hvy)
{
	//return (sqrt((hx - px) * (hx - px) + (hy - py) * (hy - py)));
	return (sqrt((hvx - px) * (hvx - px) + (hvy - py) * (hvy - py)));
}

void	fix_fisheye(t_admin *admin, double dist)
{
	double ca;

	ca = admin->player->pa  - admin->rays->ra + PI;
	if (ca < 0)
		ca += 2*PI;
	else if (ca > 2*PI)
		ca -= 2*PI;
	admin->rays->distF = dist * cos(ca);
}

void draw_floor(t_admin *admin)
{
	int	i; 
	int	j;

	j = W_HEIGHT / 2;
	i = W_WIDTH / 2 + 1;
	while (j > 0)
	{
		while (i < W_WIDTH)
		{
			my_mlx_pixel_put(admin->mlx, i, j, CYAN_PIXEL);
			i++;
		}
		j--;
		i = W_WIDTH / 2 + 1;;
	}
}

void 	draw_Wall(t_admin *admin, t_map *map, t_mlx *mlx, double dist)
{
	int lineH;
	int baseline;
	int stopline;
	//float text;
	
	if (dist < 1)
		dist = 1;
	fix_fisheye(admin, dist);
	//printf(YELLOW" dist = %f "RESET"\n", dist);
	lineH = ((map->mapS * mlx->imgame->height) / ((int)dist));
	//printf(GREEN" dist = %f | lineH = %d "RESET"\n", dist, lineH);
	//printf(GREEN" dist = %f | lineH = %d | mlx->height = %d "RESET"\n", dist, lineH, mlx->height);
	// if (lineH > mlx->imgame->height)
	// 	lineH = mlx->imgame->height;
	baseline = (mlx->imgame->height / 2) - (lineH / 2);
	//stopline = (mlx->imgame->height / 2) + (lineH / 2);
	if (baseline < 0)
		baseline = 0;
	stopline = lineH + baseline;
	//printf(RED"baseline = %d | stopline = %d | lineH = %d | mlx->height = %d "RESET"\n", baseline, stopline, lineH, mlx->height);
	// printf(RED" mlx->imgame->height = %d "RESET"\n", mlx->imgame->height);
	// printf(YELLOW" dist = %f | lineH = %d "RESET"\n", dist, lineH);
	while (baseline < stopline && baseline < W_HEIGHT)
	{
				if (admin->rays->distV < admin->rays->distH)
				{
					my_mlx_pixel_put(mlx, admin->rays->r + 512, baseline, FGREEN_PIXEL);
					//printf(GREEN" dist = %f | lineH = %d "RESET"\n", dist, lineH);
				}
				else
				{
					my_mlx_pixel_put(mlx, admin->rays->r + 512, baseline, GREEN_PIXEL);
					//printf(YELLOW" dist = %f | lineH = %d "RESET"\n", dist, lineH);			
				}
			//my_mlx_pixel_put(mlx, dist, admin->player->py, GREEN_PIXEL);
				 //my_mlx_pixel_put(mlx, admin->rays->r + x + 530, baseline/2, GREEN_PIXEL);
			//printf("pixelput \n");
			baseline++;
	}
}

void	choise_Text(t_admin *admin, t_rays *rays)
{
	if (rays->distV < rays->distH)
	{
		if (rays->ra <= (PI / 2) || rays->ra > (3 * (PI / 2)))
		{
			rays->color = CYAN_PIXEL;
			admin->player->text = 'W'; // West texture			
		}
		if (rays->ra > (PI / 2) && rays->ra <= (3 * (PI / 2)))
		{
			rays->color = YELLOW_PIXEL;
			admin->player->text = 'E'; // East texture
		}
	}
	else
	{
		if (rays->ra >= 0 && rays->ra < PI)
		{
			rays->color = WHITE_PIXEL;
			admin->player->text = 'S'; // South texture			
		}
		if (rays->ra >= PI && rays->ra < (2 * PI))
		{
			rays->color = GREEN_PIXEL;
			admin->player->text = 'N'; // North texture
		}
	}
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
	admin->rays->distF = dist;
	choise_Text(admin, admin->rays);
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
			// if (admin->rays->distV < admin->rays->distH)
			// 	my_mlx_pixel_put(mlx, finalx, finaly, FGREEN_PIXEL);
			// else
				my_mlx_pixel_put(mlx, finalx, finaly, admin->rays->color);
		}	
		x++;
	}
}
