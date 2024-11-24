/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <cgranja@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:41:14 by ebarguil          #+#    #+#             */
/*   Updated: 2022/11/07 19:28:27 by cgranja          ###   ########.fr       */
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
 * === ft_read_file === *
 */

typedef struct s_rf
{
	char		buf[BUFFER_SIZE + 1];
	int			r;
	int			l;
	int			i;
}	t_rf;

char	**ft_read_file(int fd, int cp);

/*
 * === ft_bzero === *
 */

void	ft_bzero(char *str, int x);

/*
 * === ft_str === *
 */

int		ft_strlen(char *s);
char	*ft_strdup_n(char *str, int n);
char	*ft_strdup(char *str);
int		ft_contains(char *s, char c);
char	*ft_strchr(char c, char *set);

/*
 * === ft_ conv === *
 */

int		ft_atoi_c(const char c);
int		ft_atoi(const char *str);

#endif