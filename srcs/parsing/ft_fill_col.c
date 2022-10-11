/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_col.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:59:18 by ebarguil          #+#    #+#             */
/*   Updated: 2022/10/06 21:00:16 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_fill_col(char *l, int end, int r, int i)
{
	char	buf[BUFFER_SIZE];
	int		rgb[3];

	while (l[++i] && i < end)
	{
		if (l[i] == ',')
			continue ;
		ft_bzero(buf, BUFFER_SIZE);
		while (l[i] && l[i] != ',' && i < end)
		{
			buf[i] = l[i];
			i++;
		}
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
