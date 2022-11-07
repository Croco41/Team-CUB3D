/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_init_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <cgranja@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:45:50 by cgranja           #+#    #+#             */
/*   Updated: 2022/11/07 21:49:05 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	find(float tx, float ty, t_img *text)
// {
// 	tx = tx * map->width;
// 	ty = ty * map->height;
// 	return (((int *)map->data)[(int)ty * map->width + (int)tx]);
// }

int	find_color(t_map *map, char d)
{
	int	color;

	color = 0;
	if (d == 'S')
		color = ((int *)map->ts->data)[(int)(map->ty * map->ts->height)
			* map->ts->width + (int)(map->tx * map->ts->width)];
	else if (d == 'N')
		color = ((int *)map->tn->data)[(int)(map->ty * map->tn->height)
			* map->tn->width + (int)(map->tx * map->tn->width)];
	else if (d == 'E')
		color = ((int *)map->te->data)[(int)(map->ty * map->te->height)
			* map->te->width + (int)(map->tx * map->te->width)];
	else if (d == 'W')
		color = ((int *)map->tw->data)[(int)(map->ty * map->tw->height)
			* map->tw->width + (int)(map->tx * map->tw->width)];
	return (color);
}

	// map->text_E = "./srcs/textures/2048_clay.xpm";
	// map->text_W = "./srcs/textures/2048_damier.xpm";
	// map->text_N = "./srcs/textures/2048_damier.xpm";
	// map->text_S = "./srcs/textures/2048_clay.xpm";

	// map->text_E = "./srcs/textures/texE_bee.xpm";
	// map->text_W = "./srcs/textures/texW_pumpkin.xpm";
	// map->text_N = "./srcs/textures/texN.xpm";
	// map->text_S = "./srcs/textures/texS.xpm";

int	init_texture(t_mlx *mlx, t_map *map)
{
	int	pixh;
	int	pixw;

	pixh = TEXT_H;
	pixw = TEXT_W;
	map->te = mlx_xpm_file_to_image(mlx->mlx_ptr, map->tex_ea, &pixw, &pixh);
	map->tw = mlx_xpm_file_to_image(mlx->mlx_ptr, map->tex_we, &pixw, &pixh);
	map->ts = mlx_xpm_file_to_image(mlx->mlx_ptr, map->tex_so, &pixw, &pixh);
	map->tn = mlx_xpm_file_to_image(mlx->mlx_ptr, map->tex_no, &pixw, &pixh);
	if (map->te == NULL || map->tw == NULL || map->ts == NULL
		|| map->tn == NULL)
		return (1);
	return (0);
}
