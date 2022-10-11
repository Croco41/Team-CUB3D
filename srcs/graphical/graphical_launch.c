/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_launch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:55:22 by cgranja           #+#    #+#             */
/*   Updated: 2022/10/10 17:55:26 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_admin admin;
	t_map map;
	t_mlx mlx;
	t_player player;
	t_rays rays;
	
	admin.map = &map;
	admin.mlx = &mlx;
	admin.player = &player;
	admin.rays = &rays;
	init_struct(&admin);

	admin.map->sizeline = 8;
	admin.map->nbline = 8;
	admin.map->mapS = 64;
	int map2[] =
	{
		1,1,1,1,1,1,1,1,    
		1,0,1,0,0,0,0,1,    
		1,0,1,0,0,0,0,1,
		1,0,1,0,0,0,0,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,0,1,0,1,
		1,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1,
	};
	admin.map->map = map2;
	if (!mlx_start_init(admin.mlx, &admin))
	{
		return (1);
	}
	return (0);
}
