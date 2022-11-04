/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_init_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:45:50 by cgranja           #+#    #+#             */
/*   Updated: 2022/10/27 17:46:03 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	find(float tx, float ty, t_img *text)
// {
// 	tx = tx * text->width;
// 	ty = ty * text->height;
// 	return (((int *)text->data)[(int)ty * text->width + (int)tx]);
// }

int	find_color(t_text *text, char d)
{
	int	color;

	color = 0;
	if (d == 'S')
		color = ((int *)text->ts->data)[(int)(text->ty * text->ts->height)
			* text->ts->width + (int)(text->tx * text->ts->width)];
	else if (d == 'N')
		color = ((int *)text->tn->data)[(int)(text->ty * text->tn->height)
			* text->tn->width + (int)(text->tx * text->tn->width)];
	else if (d == 'E')
		color = ((int *)text->te->data)[(int)(text->ty * text->te->height)
			* text->te->width + (int)(text->tx * text->te->width)];
	else if (d == 'W')
		color = ((int *)text->tw->data)[(int)(text->ty * text->tw->height)
			* text->tw->width + (int)(text->tx * text->tw->width)];
	return (color);
}

	// text->text_E = "./srcs/textures/2048_clay.xpm";
	// text->text_W = "./srcs/textures/2048_damier.xpm";
	// text->text_N = "./srcs/textures/2048_damier.xpm";
	// text->text_S = "./srcs/textures/2048_clay.xpm";

	// text->text_E = "./srcs/textures/texE_bee.xpm";
	// text->text_W = "./srcs/textures/texW_pumpkin.xpm";
	// text->text_N = "./srcs/textures/texN.xpm";
	// text->text_S = "./srcs/textures/texS.xpm";

int	init_texture(t_mlx *mlx, t_text *text)
{
	int	pixh;
	int	pixw;

	pixh = TEXT_H;
	pixw = TEXT_W;
	text->text_e = "./srcs/textures/2048_wood.xpm";
	text->text_w = "./srcs/textures/teo.xpm";
	text->text_n = "./srcs/textures/2048_cloud.xpm";
	text->text_s = "./srcs/textures/2048_clay.xpm";
	text->te = mlx_xpm_file_to_image(mlx->mlx_ptr, text->text_e, &pixw, &pixh);
	text->tw = mlx_xpm_file_to_image(mlx->mlx_ptr, text->text_w, &pixw, &pixh);
	text->ts = mlx_xpm_file_to_image(mlx->mlx_ptr, text->text_s, &pixw, &pixh);
	text->tn = mlx_xpm_file_to_image(mlx->mlx_ptr, text->text_n, &pixw, &pixh);
	if (text->te == NULL || text->tw == NULL || text->ts == NULL
		|| text->tn == NULL)
		return (1);
	return (0);
}
