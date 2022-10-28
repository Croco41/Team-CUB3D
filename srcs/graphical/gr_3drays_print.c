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
	i = 0;
	while (j > 0)
	{
		while (i < W_WIDTH)
		{
			my_mlx_pixel_put(admin->mlx, i, j, CYAN_PIXEL);
			i++;
		}
		j--;
		i = 0;
	}
}

//printf(GREEN" dist = %f | lineH = %d "RESET"\n", dist, lineH);
	//printf(GREEN" dist = %f | lineH = %d | mlx->height = %d "RESET"\n", dist, lineH, mlx->height);
	// if (lineH > mlx->imgame->height)
	// 	lineH = mlx->imgame->height;

		//printf(RED"baseline = %d | stopline = %d | lineH = %d | mlx->height = %d "RESET"\n", baseline, stopline, lineH, mlx->height);
	// printf(RED" mlx->imgame->height = %d "RESET"\n", mlx->imgame->height);
	// printf(YELLOW" dist = %f | lineH = %d "RESET"\n", dist, lineH);

	//my_mlx_pixel_put(mlx, dist, admin->player->py, GREEN_PIXEL);
				 //my_mlx_pixel_put(mlx, admin->rays->r + x + 530, baseline/2, GREEN_PIXEL);
			//printf("pixelput \n");

// void 	draw_Wall(t_admin *admin, t_map *map, t_mlx *mlx, double dist)
// {
// 	int lineH;
// 	int baseline;
// 	int stopline;
// 	float case_step;
// 	float case_off;
// 	float ty;
// 	float tx;
// 	int c;
	
// 	if (dist < 1)
// 		dist = 1;
// 	fix_fisheye(admin, dist);
// 	lineH = ((map->mapS * mlx->imgame->height) / ((int)dist));
// 	baseline = (mlx->imgame->height / 2) - (lineH / 2);
// 	//stopline = (mlx->imgame->height / 2) + (lineH / 2);
// 	if (baseline < 0)
// 		baseline = 0;
// 	stopline = lineH + baseline;
// 	case_step = TEXT_H / (float)lineH;
// 	case_off = 0;
// 	if (lineH > mlx->imgame->height)
// 	{
// 		case_off = (lineH - mlx->imgame->height) / 2;
// 		lineH = mlx->imgame->height;	
// 	}
// 	ty = case_off * case_step;
// 	if (admin->player->text == 'S' || admin->player->text == 'N')
// 	{
// 		tx = (int)(admin->rays->rx) % TEXT_W;
// 		if (admin->rays->ra < PI)
// 			tx = (TEXT_W - 1) - tx;
// 	}
// 	else
// 	{
// 		tx = (int)(admin->rays->ry) % TEXT_H;
// 		if (admin->rays->ra > (PI / 2) && admin->rays->ra < (3 * (PI / 2)))
// 			tx = (TEXT_H - 1) - tx;
// 	}
// 	admin->text->tx = tx;
// 	while (baseline < stopline && baseline < W_HEIGHT)
// 	{
// 		if (admin->player->text == 'W')
// 			c = admin->text->text_W[(int)(ty) * 32 + (int)(tx)];
// 		else if (admin->player->text == 'E')
// 			c = admin->text->text_E[(int)(ty) * 32 + (int)(tx)];
// 		else if (admin->player->text == 'S')
// 			c = admin->text->text_S[(int)(ty) * 32 + (int)(tx)];
// 		else if (admin->player->text == 'N')
// 			c = admin->text->text_N[(int)(ty) * 32 + (int)(tx)];
// 		if (c == 0)
// 			my_mlx_pixel_put(mlx, admin->rays->r + 512, baseline, BLACK_PIXEL);
// 		else
// 			my_mlx_pixel_put(mlx, admin->rays->r + 512, baseline, WHITE_PIXEL);	
// 		ty += case_step;
// 		admin->text->ty = ty;
// 		baseline++;
// 	// while (baseline < stopline && baseline < W_HEIGHT)
// 	// {


// 				// if (admin->rays->distV < admin->rays->distH)
// 				// {
// 				// 	my_mlx_pixel_put(mlx, admin->rays->r + 512, baseline, FGREEN_PIXEL);
// 				// 	//printf(GREEN" dist = %f | lineH = %d "RESET"\n", dist, lineH);
// 				// }
// 				// else
// 				// {
// 				// 	my_mlx_pixel_put(mlx, admin->rays->r + 512, baseline, GREEN_PIXEL);
// 				// 	//printf(YELLOW" dist = %f | lineH = %d "RESET"\n", dist, lineH);			
// 				// }	
// 			//baseline++;
// 	}
// }


void 	draw_Wall(t_admin *admin, t_mlx *mlx, double dist)
{
	int lineH;
	int baseline;
	int stopline;
	int color;
	float case_step;
	float case_off;

	if (dist < 1)
		dist = 1;
	fix_fisheye(admin, dist);
	lineH = ((PIX * mlx->imgame->height) / ((int)dist));
	baseline = (mlx->imgame->height / 2) - (lineH / 2);
	//stopline = (mlx->imgame->height / 2) + (lineH / 2);
	if (baseline < 0)
		baseline = 0;
	stopline = lineH + baseline;
	case_step = TEXT_H / (float)lineH;
	case_off = 0;
	if (lineH > mlx->imgame->height)
	{
		case_off = (lineH - mlx->imgame->height) / 2;
		lineH = mlx->imgame->height;	
	}
	admin->text->ty = case_off * case_step;
	if (admin->player->text == 'S' || admin->player->text == 'N')
	{
		admin->text->tx = (int)(admin->rays->rx) % TEXT_W;
		if (admin->rays->ra < PI)
			admin->text->tx = (TEXT_W - 1) - admin->text->tx;
	}
	else
	{
		admin->text->tx = (int)(admin->rays->ry) % TEXT_H;
		if (admin->rays->ra > (PI / 2) && admin->rays->ra < (3 * (PI / 2)))
			admin->text->tx = (TEXT_H - 1) - admin->text->tx;
	}

	while (baseline < stopline && baseline < mlx->imgame->height)
	{
		
		color = find_color(admin->text ,admin->player->text);
		my_mlx_pixel_put(mlx, admin->rays->r + 512, baseline, color);
		baseline++;
		admin->text->ty += case_step;
	}
}

void	choise_Text(t_admin *admin, t_rays *rays)
{
	if (rays->distV < rays->distH)
	{
		if (rays->ra <= (PI / 2) || rays->ra > (3 * (PI / 2)))
		{
			rays->color = CYAN_PIXEL;
			admin->player->text = 'E'; // East texture			
		}
		if (rays->ra > (PI / 2) && rays->ra <= (3 * (PI / 2)))
		{
			rays->color = YELLOW_PIXEL;
			admin->player->text = 'W'; // West texture
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

void	drawLine(t_admin *admin)
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
		
		// if (admin->player->px < admin->map->sizeline * 64 && admin->player->py < admin->map->nbline * 64)
		// {
		// 	//my_mlx_pixel_put(mlx, dist, admin->player->py, GREEN_PIXEL);
		// 	// if (admin->rays->distV < admin->rays->distH)
		// 	// 	my_mlx_pixel_put(mlx, finalx, finaly, FGREEN_PIXEL);
		// 	// else
		// 		my_mlx_pixel_put(admin->mlx, finalx, finaly, admin->rays->color);
		// }	
		x++;
	}
}
