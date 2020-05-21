/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_answer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 21:30:32 by jtsai             #+#    #+#             */
/*   Updated: 2018/10/06 09:06:07 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	set_minimum(t_info *info)
{
	int	i;
	int	j;
	int	k;
	int	t;
	int	m;

	k = -1;
	while (++k < info->s.cor_num)
	{
		m = MARK;
		t = -1;
		while (++t < info->s.p_num)
		{
			i = (info->s.cor[k].x + info->s.p[t].x + \
					info->size.x) % info->size.x;
			j = (info->s.cor[k].y + info->s.p[t].y + \
					info->size.y) % info->size.y;
			if (info->tmp_y[i][j] < m && info->tmp_y[i][j] != -1)
				m = info->tmp_y[i][j];
		}
		info->s.cor[k].min = m;
		if (m < info->min_len)
			info->min_len = m;
	}
}

void	find_closest(t_info *info)
{
	int	k;

	k = -1;
	while (++k < info->s.cor_num)
	{
		if (info->s.cor[k].min <= info->min_len)
		{
			info->ans.x = info->s.cor[k].x;
			info->ans.y = info->s.cor[k].y;
			info->min_len = info->s.cor[k].min;
		}
	}
}

void	find_answer(t_info *info)
{
	info->min_len = MARK;
	set_minimum(info);
	find_closest(info);
}
