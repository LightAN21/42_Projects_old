/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:51:38 by jtsai             #+#    #+#             */
/*   Updated: 2019/11/07 13:58:09 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	try_1_default(t_info *info)
{
	color_init(info);
	info->draw = draw_try_1;
	info->def = try_1_default;
	info->half_width = info->width >> 1;
	info->half_height = info->height >> 1;
	info->zoom = (info->width - 50) / 3;
	info->zoom_x = info->half_width;
	info->zoom_y = info->half_height;
	info->zoom_on = 0;
	info->zoom_init = info->zoom;
	info->zoom_center_x = 0;
	info->zoom_center_y = 0;
	info->center_x = 0;
	info->center_y = 0;
	info->r = 100;
	info->cx = -0.75;
	info->cy = 0.11;
	info->cr = sqrt(info->cx * info->cx + info->cy * info->cy);
	info->ctheta = atan2(info->cy, info->cx);
	info->iter_max = 100;
}

void	draw_try_1(t_info *info)
{
	t_var	v;

	v.r2 = info->r * info->r;
	v.x = -1;
	while (++v.x < info->width)
	{
		v.y = -1;
		while (++v.y < info->height)
		{
			v.zx = info->zoom_center_x + (v.x - info->zoom_x) / info->zoom;
			v.zy = info->zoom_center_y + (v.y - info->zoom_y) / info->zoom;
			v.iter = -1;
			while (++v.iter < info->iter_max
					&& v.zx * v.zx + v.zy * v.zy < v.r2)
			{
				v.xtmp = v.zx * v.zx - v.zy * v.zy;
				v.zy = -2 * v.zx * v.zy + info->cy;
				v.zx = v.xtmp + info->cx;
			}
			put_color(info, v.x, v.y, (v.iter < info->iter_max) ? \
					info->color[v.iter % 48] : 0);
		}
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
}

int		try_1(void)
{
	t_info info;

	info.width = 500;
	info.height = 500;
	julia_default(&info);
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, info.width, info.height, "fractol");
	info.img = (unsigned *)mlx_new_image(info.mlx, 500, 500);
	info.scr = (unsigned *)mlx_get_data_addr(info.img,
			&info.bits, &info.size_line, &info.endian);
	draw_try_1(&info);
	mlx_hook(info.win, 2, 2, deal_key_julia, (void *)(&info));
	mlx_key_hook(info.win, deal_key_base, (void *)(&info));
	mlx_mouse_hook(info.win, deal_mouse_base, (void *)(&info));
	mlx_hook(info.win, 6, 1L << 6, deal_mousemove_julia, (void *)(&info));
	mlx_loop(info.mlx);
	return (0);
}
