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

void	Rays_distancecheck(t_player *player, t_rays *rays, t_map *map, int order)
{
		while (rays->dof < 8)
		{
//printf("hello1\n");
			rays->mx = (int)(rays->rx) >> 6;
			rays->my = (int)(rays->ry) >> 6;
			rays->mp = rays->my * map->sizeline + rays->mx;
	//printf(YELLOW"rays->mp: %d, {rays->mx} : %d "RESET"\n", (rays->mp), rays->mx);
			if (rays->mp > 0 && rays->mp < map->mapS && map->map[rays->mp] == 1)
			{
				
				if (order == 0)
				{
					rays->hx = rays->rx;
					rays->hy = rays->ry;
					rays->distH = get_dist(player->px, player->py, rays->hx, rays->hy); //hit wall
				}
				else if (order == 1)
				{
					rays->vx = rays->rx;
					rays->vy = rays->ry;
					rays->distV = get_dist(player->px, player->py, rays->vx, rays->vy);
				}
				rays->dof = 8;
			}
			else
			{
				rays->rx += rays->xo;
				rays->ry += rays->yo; 
				rays->dof += 1; // next line
			}
		}
}

void	Rays_horizontalcheck(t_player *player, t_rays *rays)
{
		double aTan;
		rays->dof = 0;
		rays->distH = 1000000;
		rays->hx = player->px;
		rays->hy = player->py;
		aTan = -1/(tan(rays->ra));
		//looking down
		if (rays->ra > PI)
		{
			rays->ry = (((int)player->py>>6)<<6) - 0.0001; //s'assurer qu'on soit en float et decalage de 6 bits 
			rays->rx = (player->py - rays->ry)*aTan + player->px;
			rays->yo = -64;
			rays->xo = -rays->yo * aTan;
		}
		//looking up
		else if (rays->ra < PI)
		{
			rays->ry = (((int)player->py>>6)<<6) + 64;
			rays->rx = (player->py - rays->ry)*aTan + player->px;
	//printf(BLUE"rays->rx: %f, rays->ry: %f, {player->py} : %d "RESET"\n", (rays->rx), rays->ry, player->py);
			rays->yo = 64;
			rays->xo = -rays->yo * aTan;
		}
		//looking straight left or right
		else if (rays->ra == 0 || rays->ra == PI)
		{
			rays->rx = player->px;
			rays->ry = player->py;
			rays->dof = 8; 
		}
}

void	Rays_verticalcheck(t_player *player, t_rays *rays)
{
		double nTan;
		
		nTan = -(tan(rays->ra));
		rays->dof = 0;
		//looking left
		if (rays->ra > PI/2 && rays->ra < (3 * PI)/2)
		{
			rays->rx = (((int)player->px >> 6) << 6) - 0.0001; //s'assurer qu'on soit en float et decalage de 6 bits 
			rays->ry = (player->px - rays->rx) * nTan + player->py;
			rays->xo = -64;
			rays->yo = -rays->xo * nTan;
		}
		//looking right
		else if (rays->ra < PI/2 || rays->ra > (3 * PI)/2)
		{
			rays->rx = (((int)player->px >> 6) << 6) + 64;
			rays->ry = (player->px - rays->rx) * nTan + player->py;
	//printf(BLUE"rays->rx: %f, rays->ry: %f, {player->py} : %d "RESET"\n", (rays->rx), rays->ry, player->py);
			rays->xo = 64;
			rays->yo = -rays->xo * nTan;
		}
		//looking straight up or down
		else if (rays->ra == 0 || rays->ra == PI)
		{
			rays->rx = player->px;
			rays->ry = player->py;
		}
}

void	drawRays3D(t_admin *admin, t_player *player, t_rays *rays, t_map *map)
{
	rays->ra = player->pa - DR * 30;
	if (rays->ra < 0)
		rays->ra += 2 * PI;
	if (rays->ra > 2 * PI)
		rays->ra -= 2 * PI;
	admin->rays->r = 0;
	while (rays->r < 60)
	{
		rays->distH = 1000000.0;
		rays->distV = 1000000.0;
		rays->hx = player->px;
		rays->hy = player->py;
		rays->vx = player->px;
		rays->vy = player->py;
		Rays_horizontalcheck(player, rays);
		Rays_distancecheck(player, rays, map, 0);
		Rays_verticalcheck(player, rays);
		Rays_distancecheck(player, rays, map, 1);
		drawLine(admin, admin->mlx);
		draw_Wall(admin, admin->map, admin->mlx, admin->rays->distF);

		//rays->ra = rays->ra + (PI / 180);
		rays->ra += DR;
		if (rays->ra < 0)
		rays->ra += 2 * PI;
		if (rays->ra > 2 * PI)
		rays->ra -= 2 * PI;
		rays->r++;
	}
}

// void drawRays3Dold(t_admin *admin, t_player *player, t_rays *rays, t_map *map)
// {
// 	//int r, mx, my, mp, dof;
// 	//double rx, ry, ra, xo, yo;
// 	//rays->ra = player->pa - (5 * PI / 180);
// 	rays->ra = player->pa - DR * 30;
// 	if (rays->ra < 0)
// 		rays->ra += 2 * PI;
// 	if (rays->ra > 2 * PI)
// 		rays->ra -= 2 * PI;
// 	admin->rays->r = 0;
// 	while (rays->r < 10)
// 	{
	
// 	//Check horizontal Line
// printf(RED"pa = [%f] | ra = [%f]"RESET"\n", player->pa * 180 / PI, rays->ra * 180 / PI);
// 		rays->dof = 0;
// 		rays->distH = 1000000;
// 		rays->hx = player->px;
// 		rays->hy = player->py;
// 		double aTan = -1/(tan(rays->ra));
// 		//looking down
// 		if (rays->ra > PI)
// 		{
// 			rays->ry = (((int)player->py>>6)<<6) - 0.0001; //s'assurer qu'on soit en float et decalage de 6 bits 
// 			rays->rx = (player->py - rays->ry)*aTan + player->px;
// 			rays->yo = -64;
// 			rays->xo = -rays->yo*aTan;
// 		}
// 		//looking up
// 		else if (rays->ra < PI)
// 		{
// 			rays->ry = (((int)player->py>>6)<<6) + 64;
// 			rays->rx = (player->py - rays->ry)*aTan + player->px;
// 	//printf(BLUE"rays->rx: %f, rays->ry: %f, {player->py} : %d "RESET"\n", (rays->rx), rays->ry, player->py);
// 			rays->yo = 64;
// 			rays->xo = -rays->yo*aTan;
// 		}
// 		//looking straight left or right
// 		else if (rays->ra == 0 || rays->ra == PI)
// 		{
// 			rays->rx = player->px;
// 			rays->ry = player->py;
// 			rays->dof = 8; 
// 		}
// 		// else if (map->map[rays->mp] == 5)
// 		// 	exit (1);
// 	//printf(YELLOW"rays->rx: %f, {player->px} : %d "RESET"\n", (rays->rx), player->px);
// 		while (rays->dof < 8)
// 		{
// //printf("hello1\n");
// 			rays->mx = (int)(rays->rx) >> 6;
// 			rays->my = (int)(rays->ry) >> 6;
// 			rays->mp = rays->my * map->sizeline + rays->mx;
// 	//printf(YELLOW"rays->mp: %d, {rays->mx} : %d "RESET"\n", (rays->mp), rays->mx);
// 			if (rays->mp > 0 && rays->mp < map->mapS && map->map[rays->mp] == 1)
// 			{
// 				rays->hx = rays->rx;
// 				rays->hy = rays->ry;
// 				rays->distH = get_dist(player->px, player->py, rays->hx, rays->hy); //hit wall
// 				rays->dof = 8;
// 			}
// 			else
// 			{
// 				rays->rx += rays->xo;
// 				rays->ry += rays->yo; 
// 				rays->dof += 1; // next line
// 			}
// 	printf(BLUE"rays->rx: %f, rays->ry: %f, rays->dof: %d "RESET"\n", (rays->rx), rays->ry, rays->dof);

// 		}
// 		//drawLine(admin, admin->mlx);
// 		// rays->ra = rays->ra + (PI / 180);
// 	rays->ra += DR;
// 	if (rays->ra < 0)
// 		rays->ra += 2 * PI;
// 	if (rays->ra > 2 * PI)
// 		rays->ra -= 2 * PI;
// 	rays->r++;
// 	}
// //printf("hello\n");
// }

// void drawRays3DVerti(t_admin *admin, t_player *player, t_rays *rays, t_map *map)
// {
// 	//int r, mx, my, mp, dof;
// 	//double rx, ry, ra, xo, yo;
// 	//rays->ra = player->pa - (5 * PI / 180);
// 	rays->r = 0;
// 	rays->ra = player->pa - DR * 30;
// 	while (rays->r < 10)
// 	{
// 	//Check horizontal Line
// printf(RED"pa = [%f] | ra = [%f]"RESET"\n", player->pa * 180 / PI, rays->ra * 180 / PI);
// 		rays->dof = 0;
// 		rays->distV = 1000000;
// 		rays->vx = player->px;
// 		rays->vy = player->py;
// 		double nTan = -(tan(rays->ra));
// 		//looking left
// 		if (rays->ra > PI/2 && rays->ra < (3 * PI)/2)
// 		{
// 			rays->rx = (((int)player->px>>6)<<6) - 0.0001; //s'assurer qu'on soit en float et decalage de 6 bits 
// 			rays->ry = (player->px - rays->rx)*nTan + player->py;
// 			rays->xo = -64;
// 			rays->yo = -rays->xo*nTan;
// 		}
// 		//looking right
// 		else if (rays->ra < PI/2 || rays->ra > (3 * PI)/2)
// 		{
// 			rays->rx = (((int)player->px>>6)<<6) + 64;
// 			rays->ry = (player->px - rays->rx)*nTan + player->py;
// 	//printf(BLUE"rays->rx: %f, rays->ry: %f, {player->py} : %d "RESET"\n", (rays->rx), rays->ry, player->py);
// 			rays->xo = 64;
// 			rays->yo = -rays->xo*nTan;
// 		}
// 		//looking straight up or down
// 		else if (rays->ra == 0 || rays->ra == PI)
// 		{
// 			rays->rx = player->px;
// 			rays->ry = player->py;
// 			rays->dof = 8; 
// 		}
// 		// else if (map->map[rays->mp] == 5)
// 		// 	exit (1);
// 	//printf(YELLOW"rays->rx: %f, {player->px} : %d "RESET"\n", (rays->rx), player->px);
// 		while (rays->dof < 8)
// 		{
// //printf("hello1\n");
// 			rays->mx = (int)(rays->rx) >> 6;
// 			rays->my = (int)(rays->ry) >> 6;
// 			rays->mp = rays->my * map->sizeline + rays->mx;
// 	//printf(YELLOW"rays->mp: %d, {rays->mx} : %d "RESET"\n", (rays->mp), rays->mx);
// 			if (rays->mp > 0 && rays->mp < map->mapS && map->map[rays->mp] == 1)
// 			{
// 				rays->vx = rays->rx;
// 				rays->vy = rays->ry;
// 				rays->distV = get_dist(player->px, player->py, rays->vx, rays->vy); //hit wall
// 				rays->dof = 8;
// 			}
// 			else
// 			{
// 				rays->rx += rays->xo;
// 				rays->ry += rays->yo; // hit wall
// 				rays->dof += 1; // next line
// 			}
// 	printf(BLUE"rays->rx: %f, rays->ry: %f, rays->dof: %d "RESET"\n", (rays->rx), rays->ry, rays->dof);

// 		}
// 		// if (rays->distV < rays->distH)
// 		// {
// 		// 	rays->rx = rays->vx;
// 		// 	rays->ry = rays->vy;
// 		// }
// 		// if (rays->distH < rays->distV)
// 		// {
// 		// 	rays->rx = rays->hx;
// 		// 	rays->ry = rays->hy;
// 		// }
// 		drawLine(admin, admin->mlx);
// 		//rays->ra = rays->ra + (PI / 180);
// 		rays->ra += DR;
// 		if (rays->ra < 0)
// 		rays->ra += 2 * PI;
// 		if (rays->ra > 2 * PI)
// 		rays->ra -= 2 * PI;
	
// 		rays->r++;
// 	}
// //printf("hello\n");
// }
