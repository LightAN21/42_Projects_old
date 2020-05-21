/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:28:42 by jtsai             #+#    #+#             */
/*   Updated: 2018/10/06 00:22:36 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_bd(t_info *info, int x, int y)
{
	int	i;
	int	j;

	i = x - 2;
	while (++i < x + 2)
	{
		j = y - 2;
		while (++j < y + 2)
		{
			if (i >= info->size.x || j >= info->size.y)
				continue ;
			if (info->map[(i + info->size.x) % info->size.x]\
					[(j + info->size.y) % info->size.y] == '.')
				return (1);
		}
	}
	return (0);
}

void	save_boundry(t_info *info, t_xy *d, int *num)
{
	int		k;

	info->tmp = 0;
	k = -1;
	while (++k < *num)
	{
		if (check_bd(info, d[k].x, d[k].y))
		{
			d[info->tmp].x = d[k].x;
			d[info->tmp++].y = d[k].y;
		}
	}
	*num = info->tmp;
}

int		check_valid(t_info *info, int k, t_xy *start, t_xy *record)
{
	int	a;
	int	b;

	a = info->s.p[k].x;
	b = info->s.p[k].y;
	if (start->x + a >= info->size.x || start->y + b >= info->size.y)
		return (0);
	a = (start->x + a + info->size.x) % info->size.x;
	b = (start->y + b + info->size.y) % info->size.y;
	if (info->map[a][b] == info->you)
		return (0);
	else if (info->map[a][b] == info->me)
	{
		if (++info->tmp > 1)
			return (0);
		record->x = a;
		record->y = b;
	}
	return (1);
}

int		check_valid_cor(t_info *info, int i, int j, int num)
{
	int		k;
	t_xy	start;
	t_xy	record;

	start.x = i;
	start.y = j;
	info->tmp = 0;
	k = -1;
	while (++k < info->s.p_num)
	{
		if (!check_valid(info, k, &start, &record))
			return (0);
	}
	if (info->tmp != 1)
		return (0);
	if (record.x == info->s.me[num].x && record.y == info->s.me[num].y)
		return (1);
	return (0);
}

void	save_valid_coor(t_info *info, int x, int y, int num)
{
	int	i;
	int	j;

	i = x - info->p_size.x;
	while (++i <= x)
	{
		j = y - info->p_size.y;
		while (++j <= y)
		{
			if (check_valid_cor(info, i, j, num))
			{
				info->s.cor[info->s.cor_num].x = i;
				info->s.cor[info->s.cor_num++].y = j;
			}
			if (info->check_end_pre == info->check_end && info->s.cor_num > 0)
				break ;
		}
		if (info->check_end_pre == info->check_end && info->s.cor_num > 0)
			break ;
	}
}
