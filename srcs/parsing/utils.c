/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:30:01 by ebarguil          #+#    #+#             */
/*   Updated: 2022/11/04 11:19:54 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_error_int(char *e, int x)
{
	write(2, BRED"\nERROR :\n ! ", ft_strlen(BRED) + 12);
	write(2, e, ft_strlen(e));
	write(2, " !" RESET "\n\n", ft_strlen(RESET) + 4);
	return (x);
}

int	ft_warning_int(char *w, char *l, int x)
{
	write(2, BORANGE"\nWARNING :\n ! ", ft_strlen(BORANGE) + 12);
	write(2, w, ft_strlen(w));
	if (l)
	{
		write(2, "\n\t -> \"", 7);
		write(2, l, ft_strlen(l));
		write(2, "\"", 1);
	}
	write(2, RESET"\n\n", ft_strlen(RESET) + 2);
	return (x);
}

int	ft_strlen_nos(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	while (i >= 1 && s[i - 1] == ' ')
		i--;
	return (i);
}

void	ft_free_pars(t_map *map)
{
	if (map->name)
		free (map->name);
	if (map->tex_no)
		free (map->tex_no);
	if (map->tex_so)
		free (map->tex_so);
	if (map->tex_we)
		free (map->tex_we);
	if (map->tex_ea)
		free (map->tex_ea);
	if (map->map)
		free (map->map);
	return ;
}
