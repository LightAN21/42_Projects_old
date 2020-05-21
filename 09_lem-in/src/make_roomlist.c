/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_roomlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 09:37:27 by jtsai             #+#    #+#             */
/*   Updated: 2019/11/16 16:35:24 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	make_order(t_info *info, int ord)
{
	int		i;
	int		num;
	t_room	*tmp;

	queue_push(info->que, info->end);
	while (info->que->size)
	{
		num = info->que->size + (++ord * 0);
		while (--num >= 0)
		{
			tmp = queue_pop(info->que);
			tmp->order = ord;
			i = tmp->link_num;
			while (--i >= 0)
			{
				if (tmp->nbr_list[i]->order == -1
						&& tmp->nbr_list[i] != info->start)
				{
					tmp->nbr_list[i]->order = 0;
					queue_push(info->que, tmp->nbr_list[i]);
				}
			}
		}
	}
	return (1);
}

int	make_nbr_list(t_room *room)
{
	int			i;
	int			j;
	t_dict_list	*tmp;

	room->nbr_list = (t_room **)malloc((room->link_num + 1) * sizeof(t_room *));
	if (!room->nbr_list)
		return (-1);
	j = 0;
	i = -1;
	while (++i < DICT_SIZE)
	{
		tmp = room->nbr->element[i];
		while (tmp)
		{
			room->nbr_list[j] = (t_room *)tmp->data;
			j++;
			tmp = tmp->next;
		}
	}
	room->nbr_list[j] = NULL;
	return (1);
}

int	make_roomlist(t_info *info)
{
	int			i;
	int			j;
	t_dict_list	*tmp;

	info->roomlist = (t_room **)malloc((info->rooms + 1) * sizeof(t_room *));
	if (!info->roomlist)
		return (-1);
	info->roomlist[info->rooms] = NULL;
	j = 0;
	i = DICT_SIZE;
	while (--i >= 0)
	{
		tmp = info->dict->element[i];
		while (tmp)
		{
			info->roomlist[j++] = (t_room *)(tmp->data);
			if (make_nbr_list((t_room *)(tmp->data)) < 0)
				return (-1);
			tmp = tmp->next;
		}
	}
	if (info->rooms < 100)
		data_heap_sort(info->roomlist, info->rooms, room_cmp);
	return (1);
}
