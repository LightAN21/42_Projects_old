/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:09:42 by jtsai             #+#    #+#             */
/*   Updated: 2019/10/15 14:36:12 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	inputs_sep(char *s, t_ls_info *info)
{
	struct stat	data;

	info->mark = 1;
	if (ft_strlen(s) > PATH_MAX)
	{
		info->error[info->error_num].name = s;
		info->error[info->error_num++].type = 0;
	}
	else if (stat(s, &data) >= 0)
		info->found[info->found_num++] = s;
	else
	{
		info->error[info->error_num].name = s;
		info->error[info->error_num++].type = 1;
	}
}

int		get_inputs(char *s, t_ls_info *info)
{
	int			i;

	if (s[0] == '-' && s[1] != 0 && info->mark == 0)
	{
		i = 0;
		while (s[++i])
		{
			if (info->flag_def[(int)s[i]])
				info->flag[(int)s[i]] = 1;
			else
				return (illegal_option(s[i]));
		}
	}
	else
		inputs_sep(s, info);
	return (1);
}

void	print_not_found(t_ls_data *err, int len)
{
	int	i;

	data_heap_sort(err, len, cmp_data_alpha);
	i = -1;
	while (++i < len)
	{
		if (err[i].type)
			ft_printf("ft_ls: %s: No such file or directory\n", err[i].name);
		else
		{
			ft_putstr("ft_ls: ");
			ft_putstr(err[i].name);
			ft_putstr(": File name too long\n");
		}
	}
	free(err);
}

int		check_inputs(int ac, char **av, t_ls_info *info)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (get_inputs(av[i], info) == 0)
		{
			free(info->found);
			free(info->error);
			return (0);
		}
	}
	info->found[info->found_num] = 0;
	info->total_num = info->found_num + info->error_num;
	info->mark = 0;
	return (1);
}

int		main(int ac, char **av)
{
	t_ls_info	info;
	t_ls_msg	dir;

	init_ls(&info, ac);
	if (ac > 1)
	{
		if (check_inputs(ac, av, &info) == 0)
			return (0);
	}
	print_not_found(info.error, info.error_num);
	if (info.found_num)
		ls_first_step(&info);
	else if (info.error_num == 0)
	{
		init_msg(0, &dir, 0, info.found_num);
		dir.num = 1;
		dir.data_arr[0].name = ".";
		dir.data_arr[0].type = 'd';
		stat(".", &(dir.data_arr[0].data));
		ls_read_dir_first_step(&dir, &info);
	}
	return (0);
}
