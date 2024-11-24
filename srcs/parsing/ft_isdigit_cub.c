/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_cub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:26:22 by ebarguil          #+#    #+#             */
/*   Updated: 2022/10/18 17:28:20 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_isdigit_cub(char *s, int n)
{
	int	i;

	i = -1;
	while (s && s[++i] && i < n)
	{
		if (s[i] == ',')
			continue ;
		if (s[i] < '0' || s[i] > '9')
		{
			return (false);
		}
	}
	return (true);
}
