/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <cgranja@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:46:35 by ebarguil          #+#    #+#             */
/*   Updated: 2022/11/07 19:33:29 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	*ft_free_split(char **strs)
{
	int	i;

	i = -1;
	if (strs)
	{
		while (strs[++i])
			free(strs[i]);
		free(strs);
	}
	return (NULL);
}

bool	ft_all_ok(t_map *map)
{
	if (!map->tex_no)
		return (false);
	if (!map->tex_so)
		return (false);
	if (!map->tex_we)
		return (false);
	if (!map->tex_ea)
		return (false);
	if (map->flo == -1)
		return (false);
	if (map->cel == -1)
		return (false);
	if (map->map_ok == false)
		return (false);
	return (true);
}

/*
	int	x = -1;
	while (data[++x])
		printf(BRED"[%s]"RESET"\n", data[x]);
*/

bool	ft_on_map(char *l)
{
	int	i;

	i = -1;
	while (l[++i])
		if (!ft_strchr(l[i], "01NSEW "))
			return (false);
	return (true);
}

int	ft_read_data(t_map *map, char **data)
{
	int		y;
	int		i;

	if (!data)
		return (ft_error_int("Error while read the file", 1));
	y = -1;
	while (data[++y])
	{
		i = 0;
		while (data[y][i] && data[y][i] == ' ')
			i++;
		if (data[y][i] == '\0')
			continue ;
		if (ft_on_map(data[y]) && !map->om)
			map->om = &data[y];
		if (!map->om)
			ft_save_elems(map, &data[y][i]);
	}
	if (map->om)
		ft_save_map(map);
	ft_free_split(data);
	if (!ft_all_ok(map))
		return (ft_error_int("Elements/Map are invalid", 1));
	return (0);
}
