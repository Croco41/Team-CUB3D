/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:41:14 by ebarguil          #+#    #+#             */
/*   Updated: 2022/10/06 20:25:30 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

# define BUFFER_SIZE 1024

/*
 * === ft_gnl === *
 */

typedef struct s_gnl
{
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	char		*line;
	int			r;
	int			i;
	int			j;
}	t_gnl;

char	*gnl(int fd);

/*
 * === ft_bzero === *
 */

void	ft_bzero(char *str, int x);

/*
 * === ft_str === *
 */

int		ft_strlen(char *s);
void	ft_strcopy_n(char *src, char dst[BUFFER_SIZE], int n);
void	ft_strcopy(char *src, char dst[BUFFER_SIZE]);
int		ft_contains(char *s, char c);

/*
 * === ft_ conv === *
 */

int		ft_atoi(const char *str);

#endif