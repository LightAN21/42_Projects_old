/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:55:07 by jtsai             #+#    #+#             */
/*   Updated: 2019/11/07 12:02:17 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** 123, 124:	left, right
** 125, 126:	down, up
** 49:			space
** 69, 78:		num pad +, -
** 4, 5:		scroll up, down
** 36:			enter
** 53:			esc
*/

int	deal_key_julia(int key, t_info *info)
{
	if (key == 123 || key == 124)
	{
		info->ctheta += (key == 124) ? 0.01 : -0.01;
		if (info->ctheta > 6.2831853 || info->ctheta < -6.2831853)
			info->ctheta = 0;
		info->cx = info->cr * cos(info->ctheta);
		info->cy = info->cr * sin(info->ctheta);
		draw_julia(info);
	}
	else if (key == 125 || key == 126)
	{
		info->cr += (key == 126) ? 0.01 : -0.01;
		if (info->cr < 0)
			info->cr = 0;
		info->cx = info->cr * cos(info->ctheta);
		info->cy = info->cr * sin(info->ctheta);
		draw_julia(info);
	}
	else if (key == 49)
	{
		info->zoom_on ^= 1;
		draw_julia(info);
	}
	return (0);
}

int	deal_mousemove_julia(int x, int y, t_info *info)
{
	if (info->zoom_on && (x != info->zoom_x || y != info->zoom_y))
	{
		info->zoom_x = x;
		info->zoom_y = y;
		info->zoom_center_x = info->center_x + \
						(x - info->half_width) / info->zoom;
		info->zoom_center_y = info->center_y + \
						(y - info->half_height) / info->zoom;
		info->cx = -info->zoom_center_x;
		info->cy = info->zoom_center_y;
		info->cr = sqrt(info->cx * info->cx + info->cy * info->cy);
		info->ctheta = atan2(info->cy, info->cx);
		draw_julia(info);
	}
	return (0);
}

int	deal_mouse_base(int button, int x, int y, t_info *info)
{
	if (button == 4 || button == 5)
	{
		info->zoom_x = x;
		info->zoom_y = y;
		info->zoom_center_x = info->center_x + \
						(x - info->half_width) / info->zoom;
		info->zoom_center_y = info->center_y + \
						(y - info->half_height) / info->zoom;
		info->zoom *= (button == 4) ? 1.05 : 0.952381;
		if (info->zoom < 1)
		{
			info->zoom = 1;
			return (0);
		}
		info->draw(info);
		info->center_x = info->zoom_center_x + \
						(info->half_width - x) / info->zoom;
		info->center_y = info->zoom_center_y + \
						(info->half_width - y) / info->zoom;
	}
	return (0);
}

int	deal_key_base(int key, t_info *info)
{
	if (key == 53)
	{
		exit(0);
		return (0);
	}
	if (key == 78 || key == 69)
	{
		info->iter_max += (key == 69) ? 5 : -5;
		if (info->iter_max < 0)
			info->iter_max = 0;
		info->draw(info);
	}
	else if (key == 36)
	{
		info->def(info);
		info->draw(info);
	}
	return (0);
}
