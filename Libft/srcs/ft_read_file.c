/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:49:41 by ebarguil          #+#    #+#             */
/*   Updated: 2022/11/04 16:15:29 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**fill_ret(t_rf *p, int fd)
{
	char	**ret;
	char	*l;

	ret = malloc(sizeof(char *) * (p->l + 1));
	if (!ret)
		return (NULL);
	l = gnl(fd);
	p->i = 0;
	while (l)
	{
		ret[p->i] = l;
		l = gnl(fd);
		p->i++;
	}
	ret[p->i] = 0;
	return (ret);
}

char	**ft_read_file(int fd, int cp)
{
	char	**ret;
	t_rf	p;

	if (fd < 0 || cp < 0 || BUFFER_SIZE <= 0
		|| read(fd, p.buf, 0) < 0 || read(cp, p.buf, 0) < 0)
		return (NULL);
	p.l = 1;
	p.r = 1;
	while (p.r)
	{
		p.r = read(cp, p.buf, BUFFER_SIZE);
		if (p.r == -1)
			return (NULL);
		p.buf[p.r] = '\0';
		p.i = -1;
		while (p.buf[++p.i])
			if (p.buf[p.i] == '\n')
				p.l++;
	}
	ret = fill_ret(&p, fd);
	close(cp);
	return (ret);
}
