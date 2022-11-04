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
	t_admin	admin;
	t_map	map;
	t_mlx	mlx;
	t_player	player;
	t_rays	rays;
	t_text	text;
	
	admin.map = &map;
	admin.mlx = &mlx;
	admin.player = &player;
	admin.rays = &rays;
	admin.text = &text;

	init_struct(&admin);

	admin.map->sizeline = 9;
	admin.map->nbline = 22;
	admin.map->mapsur = admin.map->sizeline * admin.map->nbline;

	int map2[] =
	{
		' ',1,1,1,1,1,1,1,1,    
		' ',1,0,0,'E',0,0,0,1,    
		1,1,1,0,1,1,1,1,' ',
		1,0,0,0,1,0,0,1,' ',
		1,0,0,0,0,0,0,1,' ',
		1,0,0,1,0,1,0,1,' ',
		1,0,1,0,0,0,0,1,' ',
		1,0,0,0,0,0,0,1,' ',
		1,1,1,0,1,1,1,1,' ',
		1,0,0,0,1,0,0,1,' ',
		1,0,0,0,0,0,0,1,' ',
		1,0,0,0,0,1,0,1,' ',
		1,0,0,0,0,0,0,1,' ',
		1,0,0,0,0,0,0,1,' ',
		1,0,0,0,0,0,0,1,' ',
		1,1,1,0,1,1,1,1,' ',
		1,0,0,0,1,0,0,1,' ',
		1,0,0,0,0,0,0,1,' ',
		1,0,0,0,0,1,0,1,' ',
		1,0,0,0,0,0,0,1,' ',
		1,1,1,1,1,1,1,1,' ',
		1,1,1,1,1,1,1,1,' ',
	};
	// int map2[] =
	// {
	// 	1,1,1,1,1,1,1,1,    
	// 	1,0,0,'E',0,0,0,1,    
	// 	1,1,1,0,1,1,1,1,
	// 	1,0,0,0,1,0,0,1,
	// 	1,0,0,0,0,0,0,1,
	// 	1,0,0,0,0,1,0,1,
	// 	//1,0,0,0,0,0,0,1,
	// 	1,1,1,1,1,1,1,1,
	// };
	admin.map->map = map2;
	init_player_position(admin.map, admin.player, admin.rays);
	size_minimap(admin.map);
	if (!mlx_start_init(admin.mlx, &admin))
	{
		return (1);
	}
	// size_minimap(admin.map, admin.mlx);
	//init_player_position(admin.map, admin.player, admin.rays);
	return (0);
}
