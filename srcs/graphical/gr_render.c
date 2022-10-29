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

void	drawplay_direct(t_player *player, t_admin *admin, double pa, double lon)
{
	int		p;
	double	px;
	double	py;

	p = 0;
	while (p++ < 100)
	{
		px = (player->px + (cos(pa) * p * (lon / 100))) / admin->map->reduc;
		py = (player->py + (sin(pa) * p * (lon / 100))) / admin->map->reduc;
		if (px < admin->map->sizeline * PIX && py < admin->map->nbline * PIX)
			my_mlx_pixel_put(admin->mlx, px, py, YELLOW_PIXEL);
	}
}
// representation sur ma minimap de mon player, avec quelques pixels de cote
// pour ameliorer la visibilite a l'affichage
// j'appelle ici aussi mes rayons 3D, calculant la distance jusqu'a un 1(mur),
// me servira pour l'affichage des textures a la bonne distance

//printf(GREEN"player->px = %d | player->py = %d | adresse player= %p"RESET"\n"
//, player->px, player->py, admin->player );
void	drawplayer(t_admin *admin, t_mlx *mlx, t_player *player)
{
	int	x;
	int	y;

	x = -2;
	y = -2;
	while (y < 3)
	{
		while (x < 3)
		{
			my_mlx_pixel_put(mlx, (player->px + x) / admin->map->reduc,
				(player->py + y) / admin->map->reduc, 0xFFFF66);
			x++;
		}
		y++;
		x = -2;
	}
	drawplay_direct(player, admin, player->pa, 30.0); 
}
//drawRays3D(admin, admin->player, admin->rays, admin->map);
	//drawRays3DVerti(admin, admin->player, admin->rays, admin->map);
	//drawLine(admin, mlx);

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
	black_image(admin);
	drawrays3d(admin, admin->player, admin->rays, admin->map);
	drawmap2d(admin->mlx, admin->map);
	drawplayer(admin, admin->mlx, admin->player);
	mlx_put_image_to_window(admin->mlx->mlx_ptr, admin->mlx->mlx_win,
		admin->mlx->imgame, 0, 0);
	return (0);
}
