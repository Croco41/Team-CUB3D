/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:49:08 by ebarguil          #+#    #+#             */
/*   Updated: 2022/10/06 18:57:05 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_map(t_map *map, char *str)
{
	ft_strcopy(str, map->name);
	map->tex_no[0] = '\0';
	map->tex_so[0] = '\0';
	map->tex_we[0] = '\0';
	map->tex_ea[0] = '\0';
	map->flo = -1;
	map->cel = -1;
	map->fd = 0;
}

int	ft_parsing(t_map *map, char *str)
{
	ft_init_map(map, str);
	if (!map->name[0])
		return (ft_error_int("argument is invalid (too long or NULL)", 1));
	if (ft_check_name(map))
		return (1);
	if (ft_check_elems(map) && !close(map->fd))
		return (1);
	close(map->fd);
	return (0);
}
