/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 14:22:27 by jtsai             #+#    #+#             */
/*   Updated: 2018/08/12 21:51:43 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	d(int a)
{
	return ((double)a);
}

void	set_unit(t_fdf *p, double m)
{
	double	a;
	double	b;

	while (p->theta < 0)
		p->theta += 64;
	while (p->theta >= 64)
		p->theta -= 64;
	while (p->phi < 0)
		p->phi += 64;
	while (p->phi >= 64)
		p->phi -= 64;
	a = (double)p->map_line * m;
	b = (double)p->max_len * m;
	p->ux = (int)(b * cos(p->theta / 32 * M_PI));
	p->uy = (int)(b * sin(p->theta / 32 * M_PI) * sin(p->phi / 32 * M_PI));
	p->vx = (int)(a * (-1) * sin(p->theta / 32 * M_PI));
	p->vy = (int)(a * cos(p->theta / 32 * M_PI) * sin(p->phi / 32 * M_PI));
	p->start_x = p->center_x;
	p->start_y = p->center_y;
	p->start_x -= (int)(d(p->vx) / d(p->map_line - 1) * d(p->map_line - 1)
			/ 2) + (int)(d(p->ux) / d(p->max_len - 1) * d(p->max_len - 1) / 2);
	p->start_y -= (int)(d(p->vy) / d(p->map_line - 1) * d(p->map_line - 1)
			/ 2) + (int)(d(p->uy) / d(p->max_len - 1) * d(p->max_len - 1) / 2);
	p->h = m * cos(p->phi / 32 * M_PI);
}

void	reset_map(t_fdf *p)
{
	p->h = (p->max_len > p->map_line) ? d(p->max_len) : d(p->map_line);
	p->unit_len = (int)(4 + 50 / (1 + p->h / 15));
	p->win_h = (int)(3 * p->h * d(p->unit_len) / 2) + 100;
	p->win_h = (p->win_h > 1500) ? 1500 : p->win_h;
	p->center_x = (int)(d(p->win_h) / 2);
	p->center_y = (int)(d(p->win_h) / 2);
	p->theta = 8;
	p->phi = 8;
	p->divide = 10;
}

int		deal_key(int key, t_fdf *p)
{
	mlx_clear_window(p->mlx, p->win);
	if (key == 53)
	{
		exit(0);
		return (0);
	}
	else if (key == 24 || (key == 27 && p->unit_len > 2))
		p->unit_len += (key - 24) ? -2 : 2;
	else if (key == 1 || key == 13)
		p->center_y += 40 * ((key - 1) ? -1 : 1);
	else if (key == 0 || key == 2)
		p->center_x += 40 * ((key) ? 1 : -1);
	else if (key == 123 || key == 124)
		p->theta += (key - 123) ? 1 : -1;
	else if (key == 125 || key == 126)
		p->phi += (key - 125) ? -1 : 1;
	else if (key == 34 || key == 40)
		p->divide += (key - 34) ? 1 : -1;
	else if (key == 49)
		reset_map(p);
	if (p->divide < 1 || p->divide > 18)
		p->divide = (p->divide < 1) ? 1 : 18;
	set_unit(p, p->unit_len);
	draw_fdf(p);
	return (0);
}

int		window_fdf(t_fdf *p)
{
	int	k;

	if (!(p->mlx = mlx_init()))
		return (error('i'));
	reset_map(p);
	if (!(p->win = mlx_new_window(p->mlx, p->win_h, p->win_h, "fdf")))
		return (error('w'));
	ft_putstr("-----------------------------------------------\n");
	ft_putstr("Map Ready.\n");
	ft_putstr("-----------------------------------------------\n");
	set_unit(p, p->unit_len);
	draw_fdf(p);
	k = mlx_hook(p->win, 2, 2, deal_key, (void *)p);
	mlx_loop(p->mlx);
	return (1);
}
