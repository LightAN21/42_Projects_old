/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:25:31 by jtsai             #+#    #+#             */
/*   Updated: 2019/11/16 17:08:17 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	insert_new(t_info *info, t_flow *flow, int *first)
{
	int		i;
	t_room	*room;

	i = -1;
	while (++i < flow->num)
	{
		if (flow->send[i] > 0)
		{
			room = (t_room *)flow->queue[i]->front->data;
			if (*first)
				ft_printf("L%d-%s", info->ant_id, room->name);
			else
				ft_printf(" L%d-%s", info->ant_id, room->name);
			*first = 0;
			room->ant_id = info->ant_id++;
			if (room != info->end)
				queue_push(info->move_list[i], room);
			else
				info->ants_at_end++;
			info->ants--;
			flow->send[i]--;
		}
	}
}

void	move_old(t_info *info, t_flow *flow, int *first)
{
	int			i;
	int			len;
	t_room		*room;
	t_ft_queue	*q;

	i = -1;
	while (++i < flow->num)
	{
		q = info->move_list[i];
		len = q->size;
		while (--len >= 0)
		{
			room = (t_room *)queue_pop(q);
			if (*first)
				ft_printf("L%d-%s", room->ant_id, room->next->name);
			else
				ft_printf(" L%d-%s", room->ant_id, room->next->name);
			*first = 0;
			room->next->ant_id = room->ant_id;
			if (room->next != info->end)
				queue_push(q, room->next);
			else
				info->ants_at_end++;
		}
	}
}

void	move_ants_init(t_info *info, t_flow *main_flow)
{
	int	i;

	info->steps = 1;
	info->ant_id = 1;
	info->ants_at_end = 0;
	info->ants_copy = info->ants;
	info->move_list = (t_ft_queue **)malloc((1 + main_flow->num) *\
			sizeof(t_ft_queue *));
	i = -1;
	while (++i < main_flow->num)
		info->move_list[i] = queue_new();
}

void	move_ants(t_info *info, t_flow *main_flow)
{
	int	first;

	move_ants_init(info, main_flow);
	if (info->print_steps)
		ft_printf("(Step %d): ", info->steps);
	first = 1;
	insert_new(info, main_flow, &first);
	ft_printf("\n");
	while (info->ants_at_end != info->ants_copy)
	{
		info->steps++;
		if (info->print_steps)
			ft_printf("(Step %d): ", info->steps);
		first = 1;
		move_old(info, main_flow, &first);
		if (info->ants > 0)
			insert_new(info, main_flow, &first);
		ft_printf("\n");
	}
	info->ants = info->ants_at_end;
	free_move_list(info);
}
