/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcopy_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:31:34 by ebarguil          #+#    #+#             */
/*   Updated: 2022/10/05 17:35:43 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcopy_n(char *src, char dst[BUFFER_SIZE], int n)
{
	int		i;

	ft_bzero(dst, BUFFER_SIZE);
	if (!src || ft_strlen(src) > BUFFER_SIZE - 1)
		return ;
	i = -1;
	while (src[++i] && n - i > 0)
		dst[i] = src[i];
	return ;
}
