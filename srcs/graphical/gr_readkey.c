/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_readkey.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:41:13 by cgranja           #+#    #+#             */
/*   Updated: 2022/10/10 17:41:24 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	use_key(t_admin *admin)
{
	if (admin->player->key_l == 1)
		turn_left(admin->player);
	if (admin->player->key_r == 1)
		turn_right(admin->player);
	if (admin->player->key_w == 1)
		move_up(admin->map, admin->player);
	if (admin->player->key_s == 1)
		move_down(admin->map, admin->player);
}

int	key_released(int keycode, t_admin *admin)
{
	if (keycode == 97)
		admin->player->key_l = 0;
	if (keycode == 100)
		admin->player->key_r = 0;
	if (keycode == 119)
		admin->player->key_w = 0;
	if (keycode == 115)
		admin->player->key_s = 0;
	return (0);
}

int	key_pressed(int keycode, t_admin *admin)
{
	if (keycode == 97)
		admin->player->key_l = 1;
	if (keycode == 100)
		admin->player->key_r = 1;
	if (keycode == 119)
		admin->player->key_w = 1;
	if (keycode == 115)
		admin->player->key_s = 1;
	if (keycode == 65307)
		ft_close(admin);
	return (0);
}
