/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_flows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 09:37:27 by jtsai             #+#    #+#             */
/*   Updated: 2019/11/16 16:40:42 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		queue_len_cmp(t_ft_queue *a, t_ft_queue *b)
{
	return (a->size - b->size);
}

void	swap_queue(t_ft_queue **arr, int i, int j)
{
	t_ft_queue	*tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void	flow_heap_heapfiy(t_ft_queue **arr, int length, int root,
		int (*cmp)(t_ft_queue *, t_ft_queue *))
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
		swap_queue(arr, root, i);
		root = i;
	}
}

void	flow_heap_sort(t_ft_queue **arr, int length,
		int (*cmp)(t_ft_queue *, t_ft_queue *))
{
	int	i;

	i = (length >> 1);
	while (--i >= 0)
		flow_heap_heapfiy(arr, length, i, cmp);
	i = length;
	while (--i >= 0)
	{
		swap_queue(arr, 0, i);
		flow_heap_heapfiy(arr, i, 0, cmp);
	}
}
