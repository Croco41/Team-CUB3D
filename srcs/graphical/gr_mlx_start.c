/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_mlx_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <cgranja@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:37:10 by cgranja           #+#    #+#             */
/*   Updated: 2022/11/08 16:19:55 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mlx_start_init(t_mlx *mlx, t_admin *admin)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		return (1);
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, W_WIDTH, W_HEIGHT, "CUB3D");
	if (mlx->mlx_win == NULL)
		return (1);
	if (init_texture(mlx, admin->map))
		return (ft_close(admin));
	mlx->imgame = mlx_new_image(mlx->mlx_ptr, W_WIDTH, W_HEIGHT);
	if (mlx->imgame == NULL)
		return (1);
	mlx_loop_hook(mlx->mlx_ptr, &render, admin);
	mlx_hook(mlx->mlx_win, KeyPress, KeyPressMask, &key_pressed, admin);
	mlx_hook(mlx->mlx_win, KeyRelease, KeyReleaseMask, &key_released, admin);
	mlx_hook(mlx->mlx_win, 17, 1L << 17, ft_closeok, admin);
	mlx_loop(mlx->mlx_ptr);
	ft_closeok(admin);
	return (0);
}

// printf(RED"mlx = %p"RESET"\n", mlx);
// printf(GREEN"admin->mlx = %p"RESET"\n", &admin->mlx);
// printf(CYAN"img_width = %d | img_height = %d"RESET"\n", 
//mlx->window->width, mlx->window->height);
//printf(YELLOW"Mlx_start_init:player->px = %d | player->py = %d | 
//adresplayer= %p"RESET"\n",admin->player->px,admin->player->py,admin->player);
//printf(CYAN"mlx_start_init:adresse mlx= %p"RESET"\n", admin->mlx );