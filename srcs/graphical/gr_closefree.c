/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_closefree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:41:29 by cgranja           #+#    #+#             */
/*   Updated: 2022/10/11 15:41:33 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_all_mlx(t_admin *admin, t_mlx *mlx)
{
	if (admin->text->te)
		mlx_destroy_image(mlx->mlx_ptr, admin->text->te);
	if (admin->text->tw)
		mlx_destroy_image(mlx->mlx_ptr, admin->text->tw);
	if (admin->text->ts)
		mlx_destroy_image(mlx->mlx_ptr, admin->text->ts);
	if (admin->text->tn)
		mlx_destroy_image(mlx->mlx_ptr, admin->text->tn);
	if (mlx->imgame)
		mlx_destroy_image(mlx->mlx_ptr, mlx->imgame);
	if (mlx->mlx_win)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
		mlx->mlx_ptr = NULL;
	}
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
}

int	ft_close(t_admin *admin)
{
	if (admin->mlx->mlx_ptr)
		ft_free_all_mlx(admin, admin->mlx);
	return (1);
}

int	ft_closeok(t_admin *admin)
{
	ft_close(admin);
	exit(0);
	return (0);
}
