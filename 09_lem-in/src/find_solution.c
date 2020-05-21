/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 19:33:18 by jtsai             #+#    #+#             */
/*   Updated: 2019/11/16 16:27:26 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_ants_allocation(t_info *info)
{
	int	i;
	int	*arr;

	if (!info->main_flow || info->main_flow->num == 0)
		return ;
	ft_printf("--------------------------------------------\n");
	ft_printf("Ants allocations:\n\n");
	arr = info->ants_allocation;
	i = -1;
	while (++i < info->main_flow->num)
	{
		ft_printf("flow[%d] (%d deges): ", i, info->main_flow->queue[i]->size);
		ft_printf("%d ants.\n", arr[i]);
	}
}

int		find_solution(t_info *info, t_flow *main_flow)
{
	int			i;
	int			max;
	int			ants;
	t_ft_queue	*q;

	main_flow->send = (int *)malloc(main_flow->num * sizeof(int));
	info->ants_allocation = (int *)malloc(main_flow->num * sizeof(int));
	i = -1;
	while (++i < main_flow->num)
		info->ants_allocation[i] = 0;
	max = main_flow->queue[main_flow->num - 1]->size + main_flow->rounds;
	ants = info->ants;
	i = -1;
	while (++i < main_flow->num)
	{
		q = main_flow->queue[i];
		main_flow->send[i] = max - q->size;
		ants -= main_flow->send[i];
		if (ants < 0)
			main_flow->send[i] += ants;
		if (main_flow->send[i] < 0)
			main_flow->send[i] = 0;
		info->ants_allocation[i] = main_flow->send[i];
	}
	return (1);
}

void	build_paths_for_ants(t_info *info, t_flow *main_flow)
{
	int				i;
	t_room			*pre_room;
	t_room			*curr_room;
	t_queue_node	*node;

	i = -1;
	while (++i < main_flow->num)
	{
		pre_room = info->start;
		node = main_flow->queue[i]->front;
		while (node)
		{
			curr_room = (t_room *)node->data;
			pre_room->next = curr_room;
			pre_room = curr_room;
			node = node->next;
		}
	}
}
