/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 13:45:24 by jtsai             #+#    #+#             */
/*   Updated: 2018/08/12 19:13:18 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		r(t_fdf *p, int i, int j)
{
	return ((int)((double)(p->map[i][j]) * p->h / p->divide));
}

int		tr(int a, int b, int c)
{
	return ((int)((double)(a * b) / (double)c));
}

int		pos(t_fdf *p, int i, int j, int c)
{
	if (c == 1)
		return (p->start_x + tr(i, p->vx, p->map_line) +
				tr(j, p->ux, p->max_len));
	else if (c == 2)
		return (p->start_y + tr(i, p->vy, p->map_line) +
				tr(j, p->uy, p->max_len));
	else
		return (0);
	return (0);
}

void	draw_start(t_fdf *p, int si, int sj, t_draw d)
{
	while (p->i != d.end_i)
	{
		d.tmp_i = p->i;
		p->j = (sj > 0) ? 0 : p->map_len[p->i] - 1;
		d.end_j = (sj > 0) ? p->map_len[p->i] : -1;
		p->x = pos(p, p->i, p->j, 1);
		p->y = pos(p, p->i, p->j, 2) - r(p, p->i, p->j);
		while (p->j != d.end_j)
		{
			if (p->i + 1 != p->map_line && p->map_len[p->i + 1] > p->j)
			{
				p->x = pos(p, p->i + 1, p->j, 1);
				p->y = pos(p, p->i + 1, p->j, 2) - r(p, p->i + 1, p->j);
				draw_line(p, p->map[p->i + 1][p->j],
						pos(p, p->i, p->j, 1),
						pos(p, p->i, p->j, 2) - r(p, p->i, p->j));
			}
			p->j += sj;
			if (p->j != d.end_j)
				draw_line(p, p->map[p->i][p->j - sj],
						pos(p, p->i, p->j, 1),
						pos(p, p->i, p->j, 2) - r(p, p->i, p->j));
		}
		p->i = d.tmp_i + si;
	}
}

int		draw_fdf(t_fdf *p)
{
	int		s_i;
	int		s_j;
	t_draw	d;

	d.tmp = 0 <= (int)p->theta % 32 && (int)p->theta % 32 < 16;
	d.tmp_i = ((p->theta - 32 < 0) + (abs((int)p->phi - 32) < 16) == 1);
	d.tmp_j = ((p->theta - 48 < 0) + (abs((int)p->phi - 32) < 16) == 1);
	if (d.tmp)
	{
		s_i = (d.tmp_i == 1) ? 1 : -1;
		s_j = s_i;
	}
	else
	{
		s_i = (d.tmp_j == 1) ? -1 : 1;
		s_j = s_i * -1;
	}
	p->i = (s_i > 0) ? 0 : p->map_line - 1;
	d.end_i = (s_i > 0) ? p->map_line : -1;
	draw_start(p, s_i, s_j, d);
	messages(p);
	return (0);
}
