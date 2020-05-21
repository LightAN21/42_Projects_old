/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_roomlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 09:37:27 by jtsai             #+#    #+#             */
/*   Updated: 2019/11/16 16:41:24 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		room_cmp(t_room *a, t_room *b)
{
	return (ft_strcmp(a->name, b->name));
}

void	swap_data(t_room **arr, int i, int j)
{
	t_room	*tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void	data_heapfiy(t_room **arr, int length, int root,
		int (*cmp)(t_room *, t_room *))
{
	int	i;
	int	left;
	int	right;

	while (root < length)
	{
		i = root;
		left = (root << 1) + 1;
		right = (root << 1) + 2;
		if (left >= length && right >= length)
			break ;
		if (left < length && cmp(arr[left], arr[i]) > 0)
			i = left;
		if (right < length && cmp(arr[right], arr[i]) > 0)
			i = right;
		if (i == root)
			break ;
		swap_data(arr, root, i);
		root = i;
	}
}

void	data_heap_sort(t_room **arr, int length,
		int (*cmp)(t_room *, t_room *))
{
	int	i;

	i = (length >> 1);
	while (--i >= 0)
		data_heapfiy(arr, length, i, cmp);
	i = length;
	while (--i >= 0)
	{
		swap_data(arr, 0, i);
		data_heapfiy(arr, i, 0, cmp);
	}
}
