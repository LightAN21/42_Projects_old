/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf_w.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 21:18:19 by jtsai             #+#    #+#             */
/*   Updated: 2018/08/11 21:29:27 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		w(t_fdf *p, int i, int j)
{
	return ((int)((double)(p->map[i][j] * p->h) / p->divide));
}

void	draw_line_w(t_fdf *p, int x2, int y2)
{
	p->x1 = p->x;
	p->y1 = p->y;
	p->sx = (p->x < x2) ? 1 : -1;
	p->sy = (p->y < y2) ? 1 : -1;
	p->dx = p->sx * (x2 - p->x);
	p->dy = p->sy * (y2 - p->y);
	p->n = -1 * p->dy;
	p->m = -1 * p->dx;
	while (p->x != x2 || p->y != y2)
	{
		p->n += p->dy;
		p->m += p->dx;
		if (p->n << 1 > p->dx)
		{
			p->y += p->sy;
			p->n -= p->dx;
		}
		if (p->m << 1 > p->dy)
		{
			p->x += p->sx;
			p->m -= p->dy;
		}
		mlx_pixel_put(p->mlx, p->win, p->x, p->y, 0xFFFFFF);
	}
}

int		draw_fdf_w(t_fdf *p)
{
	p->i = -1;
	while (++p->i < p->map_line)
	{
		p->x = p->start_x + p->i * p->vx;
		p->y = p->start_y + p->i * p->vy - w(p, p->i, 0);
		p->j = 0;
		while (++p->j < p->map_len[0])
			if (0 <= p->x && p->x < p->win_h && 0 <= p->y && p->y < p->win_h)
				draw_line_w(p, p->x + p->ux,
						p->y + p->uy + w(p, p->i, p->j - 1) - w(p, p->i, p->j));
	}
	p->j = -1;
	while (++p->j < p->map_len[0])
	{
		p->x = p->start_x + p->j * p->ux;
		p->y = p->start_y + p->j * p->uy - w(p, 0, p->j);
		p->i = 0;
		while (++p->i < p->map_line)
			if (0 <= p->x && p->x < p->win_h && 0 <= p->y && p->y < p->win_h)
				draw_line_w(p, p->x + p->vx,
						p->y + p->vy + w(p, p->i - 1, p->j) - w(p, p->i, p->j));
	}
	return (0);
}
