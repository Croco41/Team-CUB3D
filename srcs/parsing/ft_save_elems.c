/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_elems.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <cgranja@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:48:06 by ebarguil          #+#    #+#             */
/*   Updated: 2022/11/07 18:19:21 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_calc_data(char *l, char one, char two)
{
	int	i;
	int	y;
	int	ret;

	i = 0;
	y = i + 1;
	ret = 0;
	if (l[i] && l[y] && (l[i] == one && l[y] == ' '))
		ret = 1;
	else if (l[i] && l[y] && l[y + 1]
		&& (l[i] == one && l[y] == two && l[y + 1] == ' '))
		ret = 2;
	while (ret > 0 && l[ret] == ' ')
		ret++;
	return (ret);
}

static int	ft_free_tex(char **tex, int x)
{
	free (*tex);
	*tex = NULL;
	return (x);
}

int	ft_save_this_tex(char *l, int x, char **tex)
{
	char	*tmp;
	int		fd;
	int		i;

	if (!x)
		return (0);
	i = x;
	while (l[i] && l[i] != ' ')
		i++;
	tmp = ft_strdup_n(&l[x], i - x);
	if (!tmp)
		return (2);
	i = ft_strlen(tmp);
	if (i < 4 || tmp[--i] != 'm' || tmp[--i] != 'p'
		|| tmp[--i] != 'x' || tmp[--i] != '.')
		return (ft_free_tex(&tmp, 3));
	fd = open(tmp, O_RDONLY);
	if (fd < 0)
		return (ft_free_tex(&tmp, 4));
	close(fd);
	if (*tex)
		free (*tex);
	*tex = tmp;
	return (1);
}

int	ft_save_this_col(char *l, int x, int *color)
{
	int		i;

	if (!x)
		return (0);
	i = x;
	while (l[i] && l[i] != ' ')
		i++;
	if (ft_contains(&l[x], ',') != 2 || l[x] == ',' || l[i - 1] == ','
		|| i - x > 11 || i - x < 5 || !ft_isdigit_cub(&l[x], i - x))
		return (0);
	*color = ft_fill_col(&l[x], i - x, -1, -1);
	return (1);
}

void	ft_save_elems(t_map *map, char *l)
{
	int	r;

	r = 0;
	r += ft_save_this_tex(l, ft_calc_data(l, 'N', 'O'), &map->tex_no);
	r += ft_save_this_tex(l, ft_calc_data(l, 'S', 'O'), &map->tex_so);
	r += ft_save_this_tex(l, ft_calc_data(l, 'W', 'E'), &map->tex_we);
	r += ft_save_this_tex(l, ft_calc_data(l, 'E', 'A'), &map->tex_ea);
	r += ft_save_this_col(l, ft_calc_data(l, 'F', ' '), &map->flo);
	r += ft_save_this_col(l, ft_calc_data(l, 'C', ' '), &map->cel);
	if (!r)
		ft_warning_int("This line was ignored on .cub :", l, 1);
	else if (r == 2)
		ft_warning_int("Exeption malloc (ft_save_this_tex) :", l, 1);
	else if (r == 3)
		ft_warning_int("This texture is not a \".xmp\"", l, 1);
	else if (r == 4)
		ft_warning_int("This texture doesn't exist :", l, 1);
	return ;
}
