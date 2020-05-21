/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 09:39:56 by jtsai             #+#    #+#             */
/*   Updated: 2019/11/16 16:39:59 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_map(t_info *info)
{
	t_lines	*tmp;

	tmp = info->lines->next;
	while (tmp)
	{
		ft_printf("%s\n", tmp->data);
		tmp = tmp->next;
	}
}

void	print_room_links(t_info *info)
{
	int		i;
	int		j;
	t_room	*tmp;

	i = -1;
	while (++i < info->rooms)
	{
		ft_printf("\n\n[%02d]", i);
		tmp = info->roomlist[i];
		j = -1;
		while (++j < info->rooms)
		{
			if (dict_get(tmp->nbr, info->roomlist[j]->name))
				ft_printf("%5d", 1);
			else
				ft_printf("%5s", " ");
		}
	}
	ft_printf("\n\n");
}

void	print_room_relation(t_info *info)
{
	int	i;

	ft_printf("--------------------------------------------\n");
	ft_printf("Room's relationships:\n\n");
	if (info->rooms > 100)
	{
		ft_printf("Too many rooms(rooms > 50).\n");
		ft_printf("Try to use \"-m\" to print all neighbers of each room\n");
		return ;
	}
	ft_printf("      ");
	i = -1;
	while (++i < info->rooms)
		ft_printf("[%02d] ", i);
	print_room_links(info);
	i = -1;
	while (++i < info->rooms)
		ft_printf("Name of room [%02d]: %s\n", i, info->roomlist[i]->name);
}

void	print_room_info(t_info *info)
{
	int				i;
	int				j;
	t_room			*tmp;

	ft_printf("--------------------------------------------\n");
	ft_printf("Rooms' informations:\n");
	i = -1;
	while (++i < info->rooms)
	{
		tmp = info->roomlist[i];
		ft_printf("\n");
		ft_printf("Name:\t%s\n", tmp->name);
		ft_printf("Coor:\t(%d, %d)\n", tmp->x, tmp->y);
		ft_printf("links:\t%d\n", tmp->link_num);
		ft_printf("Neighbers: ");
		j = -1;
		while (++j < tmp->link_num)
			ft_printf("%s ", tmp->nbr_list[j]->name);
		ft_printf("\n");
		if (tmp->order != 0 && tmp->order != -1)
			ft_printf("Order:\t%d\n", tmp->order);
		else
			ft_printf("Order:\t%s\n", ((tmp->order == 0) ? "end" : "start"));
	}
}

void	print_info(t_info *info)
{
	if (info->print_room_info)
		print_room_info(info);
	if (info->print_relation)
		print_room_relation(info);
	if (info->print_all_flows)
		print_all_flows(info);
	if (info->print_main_flow)
		print_main_flow(info);
	if (info->print_ants_allocation)
		print_ants_allocation(info);
	if (info->print_info)
	{
		ft_printf("--------------------------------------------\n");
		ft_printf("Informations:\n\n");
		ft_printf("Ants:\t%d\n", info->ants);
		ft_printf("Rooms:\t%d\n", info->rooms);
		ft_printf("Links:\t%d\n", info->links);
		ft_printf("Name of the starting room:  %s\n", info->start->name);
		ft_printf("Name of the ending room:    %s\n", info->end->name);
	}
	if (info->print_steps)
	{
		ft_printf("--------------------------------------------\n");
		ft_printf("My solution steps: %d\n", info->steps);
	}
}
