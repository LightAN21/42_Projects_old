/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:26:20 by jtsai             #+#    #+#             */
/*   Updated: 2019/11/07 12:57:44 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	tricorn_default(t_info *info)
{
	color_init(info);
	info->draw = draw_tricorn;
	info->def = tricorn_default;
	info->half_width = info->width >> 1;
	info->half_height = info->height >> 1;
	info->zoom = info->width / 4;
	info->zoom_x = info->half_width;
	info->zoom_y = info->half_height;
	info->zoom_on = 0;
	info->zoom_init = info->zoom;
	info->zoom_center_x = 0;
	info->zoom_center_y = 0;
	info->center_x = 0;
	info->center_y = 0;
	info->r = 4;
	info->r2 = 16;
	info->cx = -1;
	info->cy = 0;
	info->cr = sqrt(info->cx * info->cx + info->cy * info->cy);
	info->ctheta = atan2(info->cy, info->cx);
	info->iter_max = 100;
}

void	draw_tricorn(t_info *info)
{
	t_var	v;

	v.x = -1;
	while (++v.x < info->width)
	{
		v.y = -1;
		while (++v.y < info->height)
		{
			info->cx = info->zoom_center_x + (v.x - info->zoom_x) / info->zoom;
			info->cy = info->zoom_center_y + (v.y - info->zoom_y) / info->zoom;
			v.zx = info->cx;
			v.zy = info->cy;
			v.iter = -1;
			while (++v.iter < info->iter_max
					&& v.zx * v.zx + v.zy * v.zy < info->r2)
			{
				v.xtmp = v.zx * v.zx - v.zy * v.zy + info->cx;
				v.zy = -2 * v.zx * v.zy + info->cy;
				v.zx = v.xtmp;
			}
			put_color(info, v.x, v.y, (v.iter < info->iter_max) ? \
					info->color[v.iter % 48] : 0);
		}
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
}

int		tricorn(void)
{
	t_info info;

	info.width = 500;
	info.height = 500;
	tricorn_default(&info);
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, info.width, info.height, "fractol");
	info.img = (unsigned *)mlx_new_image(info.mlx, 500, 500);
	info.scr = (unsigned *)mlx_get_data_addr(info.img,
			&info.bits, &info.size_line, &info.endian);
	draw_tricorn(&info);
	mlx_hook(info.win, 2, 2, deal_key_base, (void *)(&info));
	mlx_mouse_hook(info.win, deal_mouse_base, (void *)(&info));
	mlx_loop(info.mlx);
	return (0);
}
