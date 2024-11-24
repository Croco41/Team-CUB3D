/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:49:08 by ebarguil          #+#    #+#             */
/*   Updated: 2022/11/04 15:17:13 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_map(t_map *map, char *str)
{
	map->name = ft_strdup(str);
	map->tex_no = NULL;
	map->tex_so = NULL;
	map->tex_we = NULL;
	map->tex_ea = NULL;
	map->map = NULL;
	map->om = NULL;
	map->map_ok = false;
	map->sizeline = 0;
	map->nbline = 0;
	map->flo = -1;
	map->cel = -1;
	map->fd = 0;
}

int	ft_parsing(t_map *map, char *str)
{
	ft_init_map(map, str);
	if (!map->name)
		return (ft_error_int("Exeption malloc (ft_init_map)", 1));
	if (ft_check_name(map))
		return (1);
	if (ft_read_data(map, ft_read_file(map->fd, open(map->name, O_RDONLY)))
		&& !close(map->fd))
		return (1);
	close(map->fd);
	return (0);
}
