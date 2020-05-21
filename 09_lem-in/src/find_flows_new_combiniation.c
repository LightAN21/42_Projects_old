/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_flows_new_combiniation.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:58:51 by jtsai             #+#    #+#             */
/*   Updated: 2019/11/16 16:25:28 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	flow_steps_count(t_info *info, t_flow *flow)
{
	t_tmp_var	v;

	v.additional_ants = 0;
	v.sum = 0;
	v.i = flow->num - 1;
	while (--v.i >= 0)
	{
		v.sum += flow->queue[v.i + 1]->size - flow->queue[v.i]->size;
		v.additional_ants += v.sum;
	}
	v.remain = info->ants - v.additional_ants;
	if (v.remain < 0)
		v.remain = 0;
	v.rounds = (v.remain / flow->num) + ((v.remain % flow->num == 0) ? 0 : 1);
	v.steps = v.rounds + flow->queue[flow->num - 1]->size - 1;
	flow->rounds = v.rounds;
	flow->ideal_steps = v.steps;
	if (v.steps < info->steps)
	{
		info->steps = v.steps;
		info->main_flow = flow;
	}
}

void	save_flow_level(t_info *info, t_flow *flow, t_ft_dict *d)
{
	t_tmp_var	var;

	var.i = -1;
	while (++var.i < flow->num)
	{
		var.s = flow->queue[var.i];
		var.curr_room = (t_room *)var.s->tail->data;
		if (var.curr_room == info->end)
			continue;
		var.j = -1;
		while (var.curr_room->nbr_list[++var.j])
		{
			var.nbr = var.curr_room->nbr_list[var.j];
			var.ele = dict_element(var.curr_room->nbr, var.nbr->name);
			if (var.ele->mark && dict_get(d, var.nbr->name) == 0)
			{
				queue_push(var.s, var.nbr);
				if (var.nbr != info->end)
					dict_add(d, var.nbr->name, var.nbr);
				break ;
			}
		}
		if (var.curr_room->nbr_list[var.j])
			info->mark++;
	}
}

void	save_flow(t_info *info, t_flow *flow)
{
	int			i;
	t_room		*curr_room;
	t_ft_dict	*d;

	d = dict_new();
	dict_add(d, info->start->name, info->start);
	i = -1;
	while (++i < flow->num)
	{
		curr_room = (t_room *)(flow->queue[i]->front->data);
		dict_add(d, curr_room->name, curr_room);
	}
	i = -1;
	info->mark = 1;
	while (info->mark)
	{
		info->mark = 0;
		save_flow_level(info, flow, d);
	}
	fix_flow(info, flow);
	dict_free(d);
	flow_heap_sort(flow->queue, flow->num, queue_len_cmp);
	flow_steps_count(info, flow);
	queue_push(info->flow_queue, flow);
}

void	make_new_flow_list(t_flow *flow, t_ft_stack *stack)
{
	int	i;

	flow->queue = (t_ft_queue **)malloc((flow->num + 1) * sizeof(t_ft_queue *));
	i = -1;
	while (++i < flow->num)
	{
		flow->queue[i] = queue_new();
		queue_push(flow->queue[i], stack_pop(stack));
	}
	flow->queue[i] = 0;
}

void	get_new_flow_combination(t_info *info, t_flow *flow)
{
	int			i;
	t_room		*curr_room;
	t_room		*nbr;
	t_dict_list	*ele;
	t_ft_stack	*stack;

	stack = stack_new();
	curr_room = info->start;
	flow->num = 0;
	i = -1;
	while (curr_room->nbr_list[++i])
	{
		nbr = curr_room->nbr_list[i];
		ele = dict_element(curr_room->nbr, nbr->name);
		if (ele->mark)
		{
			flow->num++;
			stack_push(stack, nbr);
		}
	}
	make_new_flow_list(flow, stack);
	stack_free(stack);
	save_flow(info, flow);
}
