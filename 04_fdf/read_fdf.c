/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 17:13:40 by jtsai             #+#    #+#             */
/*   Updated: 2018/08/12 21:36:15 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	free_list(t_map **m)
{
	int		i;
	t_map	*tmp;
	t_map	*c;

	c = *m;
	while (c)
	{
		i = -1;
		while (c->line[++i])
			free(c->line[i]);
		free(c->line);
		tmp = c;
		c = c->next;
		free(tmp);
	}
	return (0);
}

int	malloc_map(t_fdf *p, int lines)
{
	p->map_line = lines;
	if (!(p->map = (int **)malloc((lines + 1) * sizeof(int *))))
		return (-1);
	p->map[lines] = NULL;
	if (!(p->map_len = (int *)malloc(lines * sizeof(int))))
		return (-1);
	if (!(p->map_color = (int **)malloc((lines + 1) * sizeof(int *))))
		return (-1);
	p->map_color[lines] = NULL;
	return (1);
}

int	save_to_map(t_fdf *p, t_map **m, int lines)
{
	int		i;
	int		j;
	t_map	*t;

	t = *m;
	i = -1;
	while (++i < lines)
	{
		if (!(p->map[lines - i - 1] = (int *)malloc(t->line_len * sizeof(int))))
			return (0);
		if (!(p->map_color[lines - i - 1] =
					(int *)malloc(t->line_len * sizeof(int))))
			return (0);
		j = -1;
		while (++j < t->line_len)
		{
			p->map[lines - i - 1][j] = ft_atoi(t->line[j]);
			p->map_color[lines - i - 1][j] = fix_colors(t->line[j]);
			if (p->map_color[lines - i - 1][j] == -42)
				return (-42 - (lines - i - 1));
		}
		p->map_len[lines - i - 1] = j;
		t = t->next;
	}
	return (1);
}

int	save_numbers(t_fdf *p, char *tmp, t_map **m)
{
	t_map	*new;

	if (!(new = (t_map *)malloc(sizeof(t_map))))
		return (0);
	if (!(new->line = ft_strsplit(tmp, ' ')))
		return (0);
	new->line_len = 0;
	while (new->line[new->line_len] != NULL)
		new->line_len++;
	if (new->line_len > p->max_len)
		p->max_len = new->line_len;
	new->next = *m;
	if (new->next)
		if (new->line_len != (*m)->line_len)
			p->invalid = 1;
	*m = new;
	return (1);
}

int	read_fdf(int fd, t_fdf *p)
{
	int		k;
	int		count_lines;
	char	*tmp;
	t_map	*m;

	tmp = NULL;
	m = NULL;
	count_lines = 0;
	p->invalid = 0;
	p->max_len = 1;
	while ((k = get_next_line(fd, &tmp)) > 0)
	{
		if (!save_numbers(p, tmp, &m))
			return (free_list(&m));
		count_lines++;
		free(tmp);
	}
	if (k < 0 || count_lines == 0 || m->line[0] == NULL)
		return (error((k < 0) ? 'g' : 'e'));
	if (malloc_map(p, count_lines) < 0)
		return (free_list(&m));
	k = save_to_map(p, &m, count_lines);
	free_list(&m);
	return (k);
}
