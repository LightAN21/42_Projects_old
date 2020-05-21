/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:28:42 by jtsai             #+#    #+#             */
/*   Updated: 2018/10/06 09:37:09 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	save_tmp_bd(t_info *info, int **t, t_xy *b, t_tmp *v)
{
	int	i;
	int	j;

	i = b[v->k].x - 2;
	while (++i < b[v->k].x + 2)
	{
		j = b[v->k].y - 2;
		while (++j < b[v->k].y + 2)
		{
			if (0 <= i && 0 <= j &&
					t[i % info->size.x][j % info->size.y] == -1)
			{
				b[v->num].x = i % info->size.x;
				b[v->num++].y = j % info->size.y;
				t[i % info->size.x][j % info->size.y] = v->len;
			}
		}
	}
}

void	set_tmp(t_info *info, int **t, t_xy *b, int num)
{
	t_tmp	v;

	v.pre = 0;
	v.now = num;
	v.num = num;
	v.len = 0;
	while (++v.len)
	{
		v.k = v.pre - 1;
		while (++v.k < v.now)
			save_tmp_bd(info, t, b, &v);
		if (v.num == v.now)
			break ;
		v.pre = v.now;
		v.now = v.num;
	}
}

void	init_tmp(t_info *info, int **t, int m, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= info->size.x)
	{
		j = -1;
		while (++j <= info->size.y)
		{
			if (info->map[i][j] == info->you)
				t[i][j] = y;
			else if (info->map[i][j] == info->me)
				t[i][j] = m;
			else
				t[i][j] = -1;
		}
	}
}

void	strategy(t_info *info)
{
	info->ans.x = info->s.cor[0].x;
	info->ans.y = info->s.cor[0].y;
	if (info->check_end_pre == info->check_end)
		return ;
	init_tmp(info, info->tmp_m, -42, MARK);
	init_tmp(info, info->tmp_y, MARK, -42);
	set_tmp(info, info->tmp_y, info->s.you, info->s.you_num);
	set_tmp(info, info->tmp_m, info->s.me, info->s.me_num);
	find_answer(info);
}
