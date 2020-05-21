/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:58:51 by jtsai             #+#    #+#             */
/*   Updated: 2019/11/16 17:24:26 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	save_line(char *s, t_info *info)
{
	info->tail->next = (t_lines *)malloc(sizeof(t_lines));
	info->tail = info->tail->next;
	if (!info->tail)
		return (-1);
	info->tail->data = 0;
	info->tail->data = ft_strsub(s, 0, ft_strlen(s));
	info->tail->next = NULL;
	if (!info->tail->data)
		return (-1);
	return (1);
}

int	read_map(t_info *info)
{
	int		k;
	char	*s;

	while (info->ants == 0)
	{
		if ((k = get_next_line(info->file, &s)) <= 0)
			return (-1);
		if (s[0] == '#')
			info->ants += 0;
		else if (!ft_isnum(s) || (info->ants = ft_atoi(s)) < 0 ||
				save_line(s, info) < 0)
			return (fail(s));
		else if (ft_atoi(s) == 0)
			break ;
		free(s);
	}
	while ((k = get_next_line(info->file, &s)) > 0)
	{
		if (check_info(s, info) < 0)
			return (fail(s));
		free(s);
	}
	if (!info->rooms || !info->links || !info->start || !info->end)
		return (-1);
	return (0);
}

int	initialize(t_info *info)
{
	ft_memset(info, 0, sizeof(t_info));
	info->dict = dict_new();
	info->flow_queue = queue_new();
	info->que = queue_new();
	info->lines = (t_lines *)malloc(sizeof(t_lines));
	if (!info->dict || !info->lines || !info->que)
		return (-1);
	info->tail = info->lines;
	info->ant_id = 1;
	return (1);
}

int	process(t_info *info)
{
	if (read_map(info) < 0)
		return (-1);
	if (make_roomlist(info) < 0)
		return (-1);
	if (make_order(info, -1) < 0)
		return (-1);
	if (info->ants == 0)
		return (0);
	info->steps = (unsigned int)(info->ants + info->rooms);
	while (1)
	{
		if (find_flows_by_edmonds_karp(info) == 0)
			break ;
	}
	info->steps = 0;
	return (1);
}

int	main(int ac, char **av)
{
	t_info	info;

	if (initialize(&info) < 0)
		return (error_message(&info));
	if (get_arguments(&info, ac, av) < 0)
		return (error_message(&info));
	if (process(&info) < 0)
		return (error_message(&info));
	if (!info.print_without_map)
		print_map(&info);
	if (info.ants == 0)
		ft_printf("\nError: No ants.\n");
	else if (info.flow_queue->size == 0)
		no_possible_solution(&info);
	else
	{
		find_solution(&info, info.main_flow);
		build_paths_for_ants(&info, info.main_flow);
		if (!info.print_without_map)
			printf("\n");
		move_ants(&info, info.main_flow);
	}
	print_info(&info);
	return (0);
}
