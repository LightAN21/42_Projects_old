/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:31:05 by jtsai             #+#    #+#             */
/*   Updated: 2019/11/16 16:31:07 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	check_flags(t_info *info, char *s)
{
	int		i;

	i = 0;
	while (s[++i])
	{
		if (s[i] == 'i')
			info->print_info = 1;
		else if (s[i] == 'r')
			info->print_relation = 1;
		else if (s[i] == 'm')
			info->print_room_info = 1;
		else if (s[i] == 's')
			info->print_steps = 1;
		else if (s[i] == 'f')
			info->print_main_flow = 1;
		else if (s[i] == 'a')
			info->print_all_flows = 1;
		else if (s[i] == 'l')
			info->print_ants_allocation = 1;
		else if (s[i] == 'n')
			info->print_without_map = 1;
		else
			return (-1);
	}
	return (1);
}

int	get_arguments(t_info *info, int ac, char **av)
{
	int	k;

	if (ac == 1)
	{
		info->file = 0;
		return (1);
	}
	k = 0;
	while (++k < ac)
	{
		if (info->file <= 0 && av[k][0] != '-')
		{
			info->file = open(av[k], O_RDONLY);
			if (info->file > 0)
				continue ;
			else
				return (-1);
		}
		if (check_flags(info, av[k]) < 0)
			return (-1);
	}
	return (1);
}
