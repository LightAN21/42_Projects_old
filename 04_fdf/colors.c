/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:37:13 by jtsai             #+#    #+#             */
/*   Updated: 2018/08/09 10:45:52 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		colors(t_fdf *p, int h, int x2, int y2)
{
	int	c;

	if (p->y1 != y2)
		c = h + (p->map[p->i][p->j] - h) * (p->y - p->y1) / (y2 - p->y1);
	else if (p->x1 != x2)
		c = h + (p->map[p->i][p->j] - h) * (p->x - p->x1) / (x2 - p->x1);
	else
		c = p->map[p->i][p->j];
	while (c < 0)
		c += 60;
	while (c >= 60)
		c -= 60;
	if (0 <= c && c < 10)
		c = 0xFF0000 + 0x000100 * (255 * c / 10);
	else if (10 <= c && c < 20)
		c = 0xFFFF00 - 0x010000 * (255 * (c - 10) / 10);
	else if (20 <= c && c < 30)
		c = 0xFF00 + 255 * (c - 20) / 10;
	else if (30 <= c && c < 40)
		c = 0xFFFF - 0x0100 * (255 * (c - 30) / 10);
	else if (40 <= c && c < 50)
		c = 0xFF + 0x010000 * (255 * (c - 40) / 10);
	else if (50 <= c && c < 60)
		c = 0xFF00FF - 255 * (c - 50) / 10;
	return (c);
}