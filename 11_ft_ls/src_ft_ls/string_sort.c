/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 01:35:02 by jtsai             #+#    #+#             */
/*   Updated: 2019/10/15 01:35:29 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	swap_data(t_ls_data *arr, int i, int j)
{
	t_ls_data	tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void	data_heapfiy(t_ls_data *arr, int length, int root,
		int (*cmp)(t_ls_data, t_ls_data))
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

void	data_heap_sort(t_ls_data *arr, int length,
		int (*cmp)(t_ls_data, t_ls_data))
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

void	sort_by_flags(t_ls_msg *msg, t_ls_info *info)
{
	int	flag;

	flag = info->flag['r'] * 10 + info->flag['t'];
	if (flag == 0)
		data_heap_sort(msg->data_arr, msg->num, cmp_data_alpha);
	else if (flag == 1)
		data_heap_sort(msg->data_arr, msg->num, cmp_data_time);
	else if (flag == 10)
		data_heap_sort(msg->data_arr, msg->num, cmp_data_alpha_reverse);
	else if (flag == 11)
		data_heap_sort(msg->data_arr, msg->num, cmp_data_time_reverse);
}
