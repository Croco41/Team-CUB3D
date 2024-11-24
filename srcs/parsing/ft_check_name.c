/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:49:54 by ebarguil          #+#    #+#             */
/*   Updated: 2022/10/04 15:50:01 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_name(t_map *map)
{
	int	i;

	if (ft_strlen(map->name) < 4)
		return (ft_error_int("map name is too short to be valid", 1));
	i = ft_strlen(map->name);
	if (map->name[--i] != 'b' || map->name[--i] != 'u'
		|| map->name[--i] != 'c' || map->name[--i] != '.')
		return (ft_error_int("map name not ending by \".cub\"", 1));
	map->fd = open(map->name, O_DIRECTORY);
	if (map->fd > 0)
	{
		close(map->fd);
		return (ft_error_int("map name is a Directory", 1));
	}
	map->fd = open(map->name, O_RDONLY);
	if (map->fd < 0)
		return (ft_error_int("map name doesn't exist", 1));
	return (0);
}
