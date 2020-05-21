/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 09:45:10 by jtsai             #+#    #+#             */
/*   Updated: 2018/10/24 18:31:40 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"
#include <stdio.h>

int		check_end(t_mlx *p)
{
	int	i;
	int	j;
	int	overlap;

	overlap = 0;
	i = -1;
	while (++i < p->p_x)
	{
		j = -1;
		while (++j < p->p_y)
		{
			if (p->p[i][j] == '*' &&
					p->map[(p->ans_x + i + p->m_x) % p->m_x]\
					[(p->ans_y + j + p->m_y) % p->m_y] == p->player)
				overlap++;
		}
	}
	if (overlap != 1)
		return (0);
	return (1);
}

int		reading(t_mlx *p)
{
	int		k;
	char	*s;

	while (1)
	{
		k = get_next_line(0, &s);
		if (k <= 0)
			break ;
		else if (s[0] == '<')
		{
			read_coor(p, s);
			free(s);
			break ;
		}
		else if (s[0] == 'P' && s[1] == 'i')
			read_piece(p, s);
		free(s);
	}
	return (0);
}

int		deal_map(t_mlx *p)
{
	reading(p);
	if (check_end(p))
	{
		if (p->player == 'O' || p->player == 'X')
			print_piece(p, (p->player == 'O') ? 0xFFCC00 : 0x6699FF);
		p->p1 += (p->player == 'O');
		p->p2 += (p->player == 'X');
	}
	else if (p->end <= 2)
		p->end++;
	if (p->end == 2)
	{
		if (p->p1 > p->p2 + 1)
			mlx_string_put(p->mlx, p->win, 5,
					p->m_x * 11 + 8, 0xFFCC00, "P1 win!");
		else if (p->p2 > p->p1 + 1)
			mlx_string_put(p->mlx, p->win, 5,
					p->m_x * 11 + 8, 0x6699FF, "P2 win!");
	}
	return (0);
}

int		deal_key(int key, t_mlx *p)
{
	if (key == 53)
		exit(1);
	deal_map(p);
	return (0);
}

int		main(void)
{
	t_mlx	p;

	p.p1 = 0;
	p.p2 = 0;
	read_info(&p);
	p.end = 0;
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, p.m_y * 11 + 1, p.m_x * 11 + 80, "Filler");
	draw_map(&p);
	mlx_hook(p.win, 2, 2, deal_key, &p);
	mlx_loop_hook(p.mlx, deal_map, &p);
	mlx_loop(p.mlx);
	return (0);
}
