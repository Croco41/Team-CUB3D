/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_mlx_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:37:10 by cgranja           #+#    #+#             */
/*   Updated: 2022/10/10 15:37:22 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mlx_start_init(t_mlx *mlx, t_admin *admin)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (1);
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, W_WIDTH, W_HEIGHT, "CUB3D");
	if (mlx->mlx_win == NULL)
		return (1);
	mlx->imgame = mlx_new_image(mlx->mlx_ptr, W_WIDTH, W_HEIGHT);
	if (mlx->imgame == NULL)
		return (2);
	mlx_loop_hook(mlx->mlx_ptr, &render, admin);
	mlx_hook(mlx->mlx_win, KeyPress, KeyPressMask, &key_pressed, admin);
	mlx_hook(mlx->mlx_win, KeyRelease, KeyReleaseMask, &key_released, admin);
	mlx_hook(mlx->mlx_win, 17, 1L << 17, ft_close, admin);
	mlx_loop(mlx->mlx_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->imgame);
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx_ptr);
	return (0);
}

// printf(RED"mlx = %p"RESET"\n", mlx);
// printf(GREEN"admin->mlx = %p"RESET"\n", &admin->mlx);
// printf(CYAN"img_width = %d | img_height = %d"RESET"\n", mlx->window->width, mlx->window->height);
//printf(YELLOW"Mlx_start_init:player->px = %d | player->py = %d | adresse player= %p"RESET"\n", admin->player->px, admin->player->py, admin->player );
//printf(CYAN"mlx_start_init:adresse mlx= %p"RESET"\n", admin->mlx );