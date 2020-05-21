/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 11:22:52 by jtsai             #+#    #+#             */
/*   Updated: 2018/08/13 10:55:55 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	free_map(t_fdf *p, int c)
{
	int		i;

	i = p->map_line;
	while (--i >= c)
		free(p->map[i]);
	i = p->map_line;
	while (--i >= c)
		free(p->map_color[i]);
	free(p->map);
	free(p->map_color);
	free(p->map_len);
	if (p->mlx)
		free(p->mlx);
	if (p->win)
		free(p->win);
	return (0);
}

int	fdf(char *filepath)
{
	t_fdf	ptr;
	int		fd;
	int		k;

	ptr.mlx = NULL;
	ptr.win = NULL;
	if ((fd = open(filepath, O_RDONLY)) < 0)
		return (error('o'));
	ft_putstr("Loading...\n");
	k = read_fdf(fd, &ptr);
	if (close(fd) < 0)
		return (free_map(&ptr, 0) + error('c'));
	if (k == -1)
		return (free_map(&ptr, 0));
	if (k == 0)
		return (free_map(&ptr, 0) + error('m'));
	if (k <= -42)
		return (error(-42) + free_map(&ptr, (-1) * k - 42));
	if (ptr.invalid)
		error(-100);
	window_fdf(&ptr);
	return (free_map(&ptr, 0));
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		fdf(argv[1]);
	else
		write(1, "usage: ./fdf source_file\n", 25);
	return (0);
}
