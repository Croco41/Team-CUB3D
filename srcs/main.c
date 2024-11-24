/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <cgranja@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:56:06 by ebarguil          #+#    #+#             */
/*   Updated: 2022/11/12 16:31:43 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_admin		admin;
	t_mlx		mlx;
	t_player	player;
	t_rays		rays;
	t_map		map;

	admin.mlx = &mlx;
	admin.player = &player;
	admin.rays = &rays;
	admin.map = &map;
	init_struct(&admin);
	if (BUFFER_SIZE != 1024)
		return (ft_error_int("libft.h => BUFFER_SIZE must be 1024", 1));
	ac--;
	if (ac != 1)
		return (ft_error_int("Too few/many argument(s)", 1));
	if (ft_parsing(admin.map, av[1]))
		return (ft_free_pars(admin.map), 1);
	admin.map->mapsur = admin.map->sizeline * admin.map->nbline;
	init_player_position(admin.map, admin.player, admin.rays, 0);
	size_minimap(admin.map);
	if (mlx_start_init(admin.mlx, &admin) == 1)
		return (ft_close(&admin), ft_error_int("Error with mlx start", 1));
	return (ft_closeok(&admin), 0);
}

/*

	printf(GREEN"av : [%s] / name : [%s]"RESET"\n", av[1], map.name);
	printf(GREEN"tex_no : [%s]"RESET"\n", map.tex_no);
	printf(GREEN"tex_so : [%s]"RESET"\n", map.tex_so);
	printf(GREEN"tex_we : [%s]"RESET"\n", map.tex_we);
	printf(GREEN"tex_ea : [%s]"RESET"\n", map.tex_ea);
	printf(GREEN"flo : [%i]"RESET"\n", map.flo);
	printf(GREEN"cel : [%i]"RESET"\n", map.cel);
	printf(GREEN"sizeline : [%d]"RESET"\n", map.sizeline);
	printf(GREEN"nbline : [%d]"RESET"\n", map.nbline);

	// printf(BRED"mlx N/A [%p]"RESET"\n", admin.mlx);
	// printf(BRED"player N/A [%p]"RESET"\n", admin.player);
	// printf(BRED"rays N/A [%p]"RESET"\n", admin.rays);
	// printf(BRED"text N/A [%p]"RESET"\n", admin.text);
	// printf(BRED"map N/A [%p]"RESET"\n", admin.map);
*/
