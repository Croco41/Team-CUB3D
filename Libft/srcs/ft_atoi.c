/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <cgranja@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:21:58 by ebarguil          #+#    #+#             */
/*   Updated: 2022/11/07 17:06:53 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_c(const char c)
{
	long	res;

	res = 0;
	if (c >= '0' && c <= '9')
		res = res * 10 + (c - '0');
	else
		return (c);
	return ((int)res);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		neg;
	long	res;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	neg = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (res < 0 && neg == 1)
		return (-1);
	if (res < 0 && neg == -1)
		return (0);
	return ((int)res * neg);
}
