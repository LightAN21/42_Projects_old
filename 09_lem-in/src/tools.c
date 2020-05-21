/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 08:11:26 by jtsai             #+#    #+#             */
/*   Updated: 2019/11/16 17:21:20 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	error_message(t_info *info)
{
	info->mark = 1;
	ft_printf("ERROR\n\n");
	ft_printf("usage: ./lem-in [-irmsfaln] [file]\n\n");
	ft_printf("Example 1:\n");
	ft_printf("./lem-in -i maps/subjet1.map\n\n");
	ft_printf("Example 2:\n");
	ft_printf("./lem-in -im < maps/subjet1.map\n\n");
	ft_printf("Example 3:\n");
	ft_printf("cat maps/subjet1.map | ./lem-in -s\n\n");
	ft_printf("File format example:\n");
	ft_printf("3\n##start\nA 1 0\n##end\nB 9 0\nC 22 0\nD 13 0\n");
	ft_printf("A-D\nB-C\nC-D\nA-B\n");
	return (-1);
}

int	free_move_list(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->main_flow->num)
		queue_free(info->move_list[i]);
	free(info->move_list);
	return (1);
}

int	no_possible_solution(t_info *info)
{
	ft_printf("\nError: No paths ");
	ft_printf("from start room (%s) ", info->start->name);
	ft_printf("to end room (%s).\n", info->end->name);
	return (0);
}

int	fail(char *tmp)
{
	if (tmp)
		free(tmp);
	return (-1);
}

int	check_fail_free_split(char **s)
{
	int i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
	return (-1);
}
