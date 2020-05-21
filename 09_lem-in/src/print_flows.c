/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:58:51 by jtsai             #+#    #+#             */
/*   Updated: 2019/11/16 16:39:13 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_flow(t_info *info, t_flow *flow)
{
	int				i;
	t_room			*room;
	t_queue_node	*n;

	i = -1;
	while (++i < flow->num)
	{
		ft_printf("flow[%d] (%d deges): ", i, flow->queue[i]->size);
		ft_printf("(%s) ", info->start->name);
		n = flow->queue[i]->front;
		while (n)
		{
			room = (t_room *)n->data;
			ft_printf("(%s) ", room->name);
			n = n->next;
		}
		ft_printf("\n");
	}
	ft_printf("Ideal steps using this flow with %d ants: %d steps.\n",\
			info->ants, flow->ideal_steps);
}

void	print_main_flow(t_info *info)
{
	t_flow	*flow;

	flow = info->main_flow;
	ft_printf("--------------------------------------------\n");
	if (!flow)
	{
		ft_printf("No flows.\n");
		return ;
	}
	ft_printf("Main flows (%d flows):\n\n", flow->num);
	print_flow(info, flow);
	if (!info->print_ants_allocation)
		print_ants_allocation(info);
}

void	print_all_flows(t_info *info)
{
	t_queue_node	*n;
	t_flow			*flow;

	ft_printf("============================================\n");
	ft_printf("All flow combinations found by Edmonds-Karp algorithm:\n");
	n = info->flow_queue->front;
	while (n)
	{
		flow = (t_flow *)n->data;
		ft_printf("--------------------------------------------\n");
		ft_printf("(%d flows):\n\n", flow->num);
		print_flow(info, flow);
		n = n->next;
	}
	ft_printf("============================================\n");
}
