/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 11:03:11 by jtsai             #+#    #+#             */
/*   Updated: 2018/08/11 20:38:26 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_fdf *p, int hight, int x2, int y2)
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
		if (0 <= p->x && p->x < p->win_h && 0 <= p->y && p->y < p->win_h)
			mlx_pixel_put(p->mlx, p->win, p->x, p->y, colors(p, hight, x2, y2));
	}
}
