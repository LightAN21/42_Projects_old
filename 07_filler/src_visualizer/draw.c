/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 08:37:51 by jtsai             #+#    #+#             */
/*   Updated: 2018/10/06 08:39:46 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	draw_map(t_mlx *p)
{
	int	i;
	int	j;
	int	c;

	c = 0x424242;
	i = -1;
	while (++i < p->m_x + 1)
	{
		j = -1;
		while (++j < p->m_y * 11 + 1)
			mlx_pixel_put(p->mlx, p->win, j, i * 11, c);
	}
	j = -1;
	while (++j < p->m_y + 1)
	{
		i = -1;
		while (++i < p->m_x * 11 + 1)
			mlx_pixel_put(p->mlx, p->win, j * 11, i, c);
	}
}

void	put_block(t_mlx *p, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
			mlx_pixel_put(p->mlx, p->win, x + i, y + j, color);
	}
}

void	print_piece(t_mlx *p, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < p->p_x)
	{
		j = -1;
		while (++j < p->p_y)
		{
			if (p->p[i][j] == '.')
				continue ;
			put_block(p, 11 * ((p->ans_y + j + p->m_y) % p->m_y) + 1, \
					11 * ((p->ans_x + i + p->m_x) % p->m_x) + 1, color);
			p->map[(p->ans_x + i + p->m_x) % p->m_x]\
				[(p->ans_y + j + p->m_y) % p->m_y] = p->player;
		}
	}
}
