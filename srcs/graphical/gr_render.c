/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:47:09 by cgranja           #+#    #+#             */
/*   Updated: 2022/10/10 15:47:36 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// impression du pixel
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
//printf(RED"img->width = %d | x = %d | y = %d"RESET"\n", mlx->imgame->width, x, y);
// printf(RED"x = %d | y = %d"RESET"\n", x, y);
	((int *)mlx->imgame->data)[y * mlx->imgame->width + x] = color;
}

// fonction pour effacer mes deplacements et rayons entre 2 positions, surement 
//vouee a disparaitre
void	black_image(t_admin *admin)
{
	int	i; 
	int	j;

	j = 0;
	i = 0;
	while (j < W_HEIGHT)
	{
		while (i < W_WIDTH)
		{
			my_mlx_pixel_put(admin->mlx, i, j, GRAY_PIXEL);
			i++;
		}
		j++;
		i = 0;
	}
	draw_floor(admin);
}



// representation sur ma minimap de mon player, avec quelques pixels de cote
// pour ameliorer la visibilite a l'affichage
// j'appelle ici aussi mes rayons 3D, calculant la distance jusqu'a un 1(mur),
// me servira pour l'affichage des textures a la bonne distance
void	drawPlayer(t_admin *admin, t_mlx *mlx, t_player *player)
{
//printf(GREEN"player->px = %d | player->py = %d | adresse player= %p"RESET"\n", player->px, player->py, admin->player );
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 5)
	{
		while (x < 5)
		{
			my_mlx_pixel_put(mlx, player->px + x, player->py + y, 0xFFFF66);
			x++;
		}
		y++;
		x = 0;
	}
	drawRays3D(admin, admin->player, admin->rays, admin->map);
	//drawRays3DVerti(admin, admin->player, admin->rays, admin->map);
	//drawLine(admin, mlx);
}

// gestionnaire de ma partie minimap, lance la fonction qui affiche des pixels 
// differents en fonction de 0(sol) ou 1(mur)
// la fonction du joueur sur la minimap et qui affiche tout ca sur la fenetre
int	render(t_admin *admin)
{
	if (admin->mlx->mlx_win == NULL)
	{
		printf(YELLOW"admin->mlx = %p"RESET"\n", admin->mlx);
		exit (1);
	}
	use_key(admin);
//printf(RED"REnder:player->px = %d | player->py = %d | adresse player= %p"RESET"\n", admin->player->px, admin->player->py, admin->player );
	black_image(admin);
	drawMap2D(admin->mlx, admin->map);
	drawPlayer(admin, admin->mlx, admin->player);
	mlx_put_image_to_window(admin->mlx->mlx_ptr, admin->mlx->mlx_win, admin->mlx->imgame, 0, 0);
	return (0);
}
