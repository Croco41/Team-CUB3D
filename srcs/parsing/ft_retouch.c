/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retouch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <cgranja@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:27:58 by cgranja           #+#    #+#             */
/*   Updated: 2022/11/07 19:30:15 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_jump_space(t_map *map)
{
	int	y;
	int	x;

	x = -1;
	while (1)
	{
		y = -1;
		x++;
		while (map->om[++y])
		{
			if (map->om[y][x] && map->om[y][x] == ' ')
				continue ;
			else
				return (x);
		}
	}
	return (0);
}

char	*ft_resize_c(char *src, int gsize, char c)
{
	char	*ret;
	int		i;

	ret = malloc(sizeof(char) * gsize + 1);
	if (!ret)
		return (NULL);
	i = -1;
	while (src && src[++i] && i < gsize)
		ret[i] = src[i];
	while (i < gsize)
		ret[i++] = c;
	ret[i] = '\0';
	return (ret);
}

int	ft_retouch_while(t_map *map, int y, int j)
{
	char	*tmp;

	if (ft_strlen_nos(&map->om[y][j]) <= map->sizeline)
	{
		tmp = ft_resize_c(&map->om[y][j], map->sizeline, ' ');
		if (!tmp)
			return (ft_error_int("Malloc exception (ft_retouch)", 1));
		free (map->om[y]);
		map->om[y] = tmp;
	}
	return (0);
}

int	ft_retouch(t_map *map)
{
	int		y;
	int		j;

	y = -1;
	j = ft_jump_space(map);
	while (map->om[++y])
		if (ft_strlen_nos(&map->om[y][j]) > map->sizeline)
			map->sizeline = ft_strlen_nos(&map->om[y][j]);
	map->nbline = y;
	y = -1;
	while (map->om[++y])
		if (ft_retouch_while(map, y, j))
			return (1);
	return (0);
}
