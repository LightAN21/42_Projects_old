/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 01:32:02 by jtsai             #+#    #+#             */
/*   Updated: 2019/10/15 01:37:01 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_ls(t_ls_info *info, int argc)
{
	ft_memset(info, 0, sizeof(t_ls_info) - LS_BUFF_SIZE);
	info->flag_def['l'] = 1;
	info->flag_def['R'] = 1;
	info->flag_def['a'] = 1;
	info->flag_def['r'] = 1;
	info->flag_def['t'] = 1;
	info->found = (char **)malloc(argc * sizeof(char *));
	info->error = (t_ls_data *)malloc(argc * sizeof(t_ls_data));
}

void	init_msg(t_ls_msg *all, t_ls_msg *dir, t_ls_msg *file, int found_num)
{
	int	n;

	n = 3 + found_num;
	if (all)
	{
		all->path = 0;
		all->num = 0;
		all->data_arr = (t_ls_data *)malloc(n * sizeof(t_ls_data));
	}
	if (dir)
	{
		dir->path = 0;
		dir->num = 0;
		dir->data_arr = (t_ls_data *)malloc(n * sizeof(t_ls_data));
	}
	if (file)
	{
		file->path = 0;
		file->num = 0;
		file->data_arr = (t_ls_data *)malloc(n * sizeof(t_ls_data));
	}
}

void	ls_free(t_ls_msg all, t_ls_msg dir)
{
	int	i;

	i = -1;
	while (++i < all.num)
		free(all.data_arr[i].name);
	free(all.data_arr);
	free(dir.data_arr);
}
