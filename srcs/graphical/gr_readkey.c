/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_readkey.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:41:13 by cgranja           #+#    #+#             */
/*   Updated: 2022/10/10 17:41:24 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_readkey(int keycode, t_admin *admin)
{

	printf(RED"ICIREADKEY [pa] %f"RESET"\n", admin->player->pa);
	if (keycode == 97) //a
	{
		//printf(RED"ICI 97"RESET"\n");
		//admin->player->px -= 15;
		admin->player->pa-=0.1;
		
		if (admin->player->pa < 0)
			admin->player->pa += 2*PI;
		admin->player->pdx = cos(admin->player->pa) * 5;
		admin->player->pdy = sin(admin->player->pa) * 5;
		// admin->player->px += admin->player->pdy;
		// admin->player->py -= admin->player->pdx;
	}
	if (keycode == 100)  //d
	{
		//admin->player->px += 15;
		admin->player->pa+=0.1;
		if (admin->player->pa > 2*PI)
			admin->player->pa -= 2*PI;
		admin->player->pdx = cos(admin->player->pa) * 5;
		admin->player->pdy = sin(admin->player->pa) * 5;
		// admin->player->px -= admin->player->pdy;
		// admin->player->py += admin->player->pdx;
	}

	int	next_x;
	int next_y;

	if (keycode == 119)
	{
		next_x = ((admin->player->px + admin->player->pdx) / admin->map->mapS);
		next_y = ((admin->player->py + admin->player->pdy) / admin->map->mapS);
		//admin->player->pa
		printf(GREEN"ICIW119 [pdx] %f | [pdy] %f "RESET"\n", admin->player->pdx, admin->player->pdy);
		if (admin->map->map[get_int(next_x, (admin->player->py / admin->map->mapS), admin->map)] == 0)
			admin->player->px += admin->player->pdx;
		if (admin->map->map[get_int((admin->player->px / admin->map->mapS), next_y, admin->map)] == 0)
			admin->player->py += admin->player->pdy;
	}

	if (keycode == 115) 
	{
		next_x = ((admin->player->px - admin->player->pdx) / admin->map->mapS);
		next_y = ((admin->player->py - admin->player->pdy) / admin->map->mapS);
		//admin->player->py += 15;
		if (admin->map->map[get_int(next_x, (admin->player->py / admin->map->mapS), admin->map)] == 0)
			admin->player->px -= admin->player->pdx;
		if (admin->map->map[get_int((admin->player->px / admin->map->mapS), next_y, admin->map)] == 0)
			admin->player->py -= admin->player->pdy;
	}
	// if (keycode == 65307)
	// {
	// 	ft_closeok(admin);
	// 	return (0);
	// }
	
	//print_img(&admin->map, admin);
	// return (1);
	return (0);
}
