/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_col.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <cgranja@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:59:18 by ebarguil          #+#    #+#             */
/*   Updated: 2022/11/07 18:27:31 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_fill_col(char *l, int end, int r, int i)
{
	char	buf[BUFFER_SIZE];
	int		rgb[3];
	int		b;

	while (l[++i] && i < end)
	{
		if (l[i] == ',')
			continue ;
		ft_bzero(buf, BUFFER_SIZE);
		b = 0;
		while (l[i] && l[i] != ',' && i < end)
			buf[b++] = l[i++];
		if (!l[i])
			i--;
		if (r == 2)
			return (-1);
		rgb[++r] = ft_atoi(buf);
		if (rgb[r] < 0 || rgb[r] > 255)
			return (-1);
	}
	if (r != 2)
		return (-1);
	return ((rgb[0] << 16) + (rgb[1] << 8) + rgb[2]);
}
