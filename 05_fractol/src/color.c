/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:54:31 by jtsai             #+#    #+#             */
/*   Updated: 2019/11/07 13:01:00 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_save(t_info *info, unsigned init, unsigned diff, int sign)
{
	unsigned k;

	k = 0;
	if (sign == 1)
	{
		while (k < 8)
			info->color[info->i++] = init + diff * k++;
	}
	else
	{
		while (k < 8)
			info->color[info->i++] = init - diff * k++;
	}
}

void	color_init(t_info *info)
{
	info->i = 0;
	color_save(info, 0x0000ff, 0x002000, 1);
	color_save(info, 0x00ffff, 0x000020, -1);
	color_save(info, 0x00ff00, 0x200000, 1);
	color_save(info, 0xffff00, 0x002000, -1);
	color_save(info, 0xff0000, 0x000020, 1);
	color_save(info, 0xff00ff, 0x200000, -1);
}

void	put_color(t_info *info, int x, int y, unsigned color)
{
	info->scr[x + y * info->width] = color;
}
