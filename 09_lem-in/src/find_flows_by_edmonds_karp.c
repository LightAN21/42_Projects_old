/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_flows_by_edmonds_karp.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:58:51 by jtsai             #+#    #+#             */
/*   Updated: 2019/11/16 16:25:37 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		fix_flow(t_info *info, t_flow *flow)
{
	int	i;

	i = -1;
	while (++i < flow->num)
	{
		if ((t_room *)flow->queue[i]->tail->data != info->end)
			queue_push(flow->queue[i], info->end);
	}
	return (1);
}

int		breadth_first_search_nbr(t_info *info, t_ft_dict *d, t_room *curr_room)
{
	int			i;
	t_dict_list	*ele;
	t_room		*curr_nbr;

	i = curr_room->link_num;
	while (--i >= 0)
	{
		curr_nbr = curr_room->nbr_list[i];
		ele = dict_element(curr_room->nbr, curr_nbr->name);
		if (curr_nbr != info->start
				&& ele->mark == 0 && dict_get(d, curr_nbr->name) == 0)
		{
			dict_add(d, curr_nbr->name, curr_nbr);
			curr_nbr->pre = curr_room;
			if (curr_nbr == info->end)
				return (1);
			queue_push(info->que, curr_nbr);
		}
	}
	return (0);
}

void	breadth_first_search(t_info *info, t_room *start)
{
	int			num;
	t_ft_dict	*d;

	d = dict_new();
	dict_add(d, start->name, start);
	queue_push(info->que, start);
	while (info->que->size)
	{
		num = info->que->size;
		while (--num >= 0)
		{
			if (breadth_first_search_nbr(info, d, queue_pop(info->que)))
			{
				queue_clear(info->que);
				dict_free(d);
				return ;
			}
		}
	}
	queue_clear(info->que);
	dict_free(d);
}

void	flow_record(t_info *info, t_flow *flow)
{
	t_room		*curr_room;
	t_room		*pre_room;
	t_ft_stack	*stack;
	t_dict_list	*ele;

	stack = stack_new();
	curr_room = info->end;
	while (curr_room && curr_room != info->start)
	{
		stack_push(stack, curr_room);
		pre_room = curr_room->pre;
		ele = dict_element(curr_room->nbr, pre_room->name);
		ele->mark = 0;
		ele = dict_element(pre_room->nbr, curr_room->name);
		ele->mark = 1;
		curr_room->pre = 0;
		curr_room = pre_room;
	}
	stack_push(stack, info->start);
	flow->bfs_path = queue_new();
	while (stack->size)
		queue_push(flow->bfs_path, stack_pop(stack));
	stack_free(stack);
}

int		find_flows_by_edmonds_karp(t_info *info)
{
	t_flow	*flow;

	breadth_first_search(info, info->start);
	if (info->end->pre == 0)
		return (0);
	flow = (t_flow *)malloc(sizeof(t_flow));
	flow_record(info, flow);
	get_new_flow_combination(info, flow);
	return (1);
}
