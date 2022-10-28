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

// 	//printf(GREEN"text->height = %d | text->width = %d | ty = %f | tx = %f "RESET"\n", text->height, text->width, ty, tx );
// 	return (((int *)text->data)[(int)ty * text->width + (int)tx]);
// }

int	find_color(t_text *text, char d)
{
	int color;

	color = 0;
	// if (d == 'S')
	// 	color = find(text->tx, text->ty, text->TS);
	// else if (d == 'N')
	// 	color = find(text->tx, text->ty, text->TN);
	// else if (d == 'E')
	// 	color = find(text->tx, text->ty, text->TE);
	// else if (d == 'W')
	// 	color = find(text->tx, text->ty, text->TW);
	if (d == 'S')
		color = ((int *)text->TS->data)[(int)(text->ty) * text->TS->width + (int)(text->tx)];
	else if (d == 'N')
		color = ((int *)text->TN->data)[(int)(text->ty) * text->TN->width + (int)(text->tx)];
	else if (d == 'E')
		color = ((int *)text->TE->data)[(int)(text->ty) * text->TE->width + (int)(text->tx)];
	else if (d == 'W')
		color = ((int *)text->TW->data)[(int)(text->ty) * text->TW->width + (int)(text->tx)];
	// else
	// 	color = BLACK_PIXEL;
	return (color);
}

int	init_texture(t_admin *admin, t_text *text)
{
	int	pixH;
	int pixW;

	pixH = TEXT_H;
	pixW = TEXT_W;	
	text->text_E = "./srcs/textures/texE_bee.xpm";
	text->text_W = "./srcs/textures/texW_pumpkin.xpm";
	text->text_N = "./srcs/textures/texN.xpm";
	text->text_S = "./srcs/textures/texS.xpm";

	text->TE = mlx_xpm_file_to_image(admin->mlx->mlx_ptr, text->text_E, &pixW, &pixH);
	text->TW = mlx_xpm_file_to_image(admin->mlx->mlx_ptr, text->text_W, &pixW, &pixH);
	text->TS = mlx_xpm_file_to_image(admin->mlx->mlx_ptr, text->text_S, &pixW, &pixH);
	text->TN = mlx_xpm_file_to_image(admin->mlx->mlx_ptr, text->text_N, &pixW, &pixH);
	if (text->TE == NULL || text->TW == NULL || text->TS == NULL || text->TN == NULL)
		return (1);
	return (0);
}