/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:56:06 by ebarguil          #+#    #+#             */
/*   Updated: 2022/10/06 20:37:45 by ebarguil         ###   ########.fr       */
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

// int	main(int ac, char **av)
// {
// 	t_map	map;

// 	if (BUFFER_SIZE <= 0)
// 		return (ft_error_int("BUFFER_SIZE must be above 0", 1));
// 	ac--;
// 	if (ac != 1)
// 		return (ft_error_int("Too few/many argument(s)", 1));
// 	if (ft_parsing(&map, av[1]))
// 		return (1);
// 	printf(GREEN"av : [%s] / name : [%s]"RESET"\n", av[1], map.name);
// 	printf(GREEN"tex_no : [%s]"RESET"\n", map.tex_no);
// 	printf(GREEN"tex_so : [%s]"RESET"\n", map.tex_so);
// 	printf(GREEN"tex_we : [%s]"RESET"\n", map.tex_we);
// 	printf(GREEN"tex_ea : [%s]"RESET"\n", map.tex_ea);
// 	printf(GREEN"flo : [%i]"RESET"\n", map.flo);
// 	printf(GREEN"cel : [%i]"RESET"\n", map.cel);
// 	return (0);
// }
