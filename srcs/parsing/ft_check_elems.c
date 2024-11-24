/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_elems.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:46:35 by ebarguil          #+#    #+#             */
/*   Updated: 2022/10/06 20:37:32 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_elems_ok(t_map *map)
{
	if (!map->tex_no[0])
		return (false);
	if (!map->tex_so[0])
		return (false);
	if (!map->tex_we[0])
		return (false);
	if (!map->tex_ea[0])
		return (false);
	if (map->flo == -1)
		return (false);
	if (map->cel == -1)
		return (false);
	return (true);
}

int	ft_check_elems(t_map *map)
{
	char	*l;
	int		i;

	l = gnl(map->fd);
	while (l)
	{
		printf(CYAN"[%s]"RESET"\n", l);
		i = 0;
		while (l[i] && l[i] == ' ')
			i++;
		if (l[i] == '\n' || ft_elems_ok(map))
		{
			free(l);
			l = gnl(map->fd);
			continue ;
		}
		ft_save_elems(map, &l[i]);
		free(l);
		l = gnl(map->fd);
	}
	if (!ft_elems_ok(map))
		return (ft_error_int("Error while parsing elements of map", 1));
	return (0);
}
