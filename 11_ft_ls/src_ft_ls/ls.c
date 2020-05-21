/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:45:16 by jtsai             #+#    #+#             */
/*   Updated: 2019/10/15 15:55:35 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_data(char **found, t_ls_msg *all, char *pre_dir)
{
	int		i;
	char	*tmp;

	i = -1;
	while (found[++i])
	{
		tmp = ft_strjoin_c(pre_dir, found[i], '/');
		all->data_arr[i].name = found[i];
		if (readlink(tmp, 0, 0) == -1)
			stat(tmp, &(all->data_arr[i].data));
		else
			lstat(tmp, &(all->data_arr[i].data));
		all->data_arr[i].type = file_type(all->data_arr[i].data.st_mode);
		if (pre_dir)
			free(tmp);
	}
	all->num = i;
}

void	separate_files(t_ls_msg *all, t_ls_msg *dir)
{
	int		i;
	char	*tmp;

	i = -1;
	while (++i < all->num)
	{
		tmp = all->data_arr[i].name;
		if (ft_strcmp(tmp, ".") == 0 || ft_strcmp(tmp, "..") == 0)
			continue;
		if (all->data_arr[i].type == 'd')
		{
			dir->data_arr[dir->num++] = all->data_arr[i];
		}
	}
}

void	ls_read_dir(t_ls_var var, t_ls_info *info, char *d_name)
{
	if (info->flag['a'] == 0 && var.path[0] == '.')
		return ;
	var.new_path = ft_strjoin_c(d_name, var.path, '/');
	var.found_num = 0;
	var.d = opendir(var.new_path);
	if (var.d)
	{
		while ((var.read = readdir(var.d)) != NULL)
			var.found_num++;
		closedir(var.d);
	}
	else
		return (ls(0, 0, info, var.new_path));
	var.found = (char **)malloc((1 + var.found_num) * sizeof(char *));
	ft_memset(var.found, 0, sizeof(char *) * (1 + var.found_num));
	var.j = 0;
	var.d = opendir(var.new_path);
	while ((var.read = readdir(var.d)) != NULL)
		var.found[var.j++] = ft_strdup(var.read->d_name);
	var.found[var.j] = 0;
	closedir(var.d);
	ls(var.found, var.found_num, info, var.new_path);
	if (d_name)
		free(var.new_path);
}

int		ls_print_dir_head(char **found, t_ls_info *info, char *pre_dir_name)
{
	if (info->mark || info->total_num > 1)
	{
		if (info->mark)
			write(1, "\n", 1);
		ft_printf("%s:\n", pre_dir_name);
	}
	if (!found)
		return (permission_denied(pre_dir_name));
	info->mark = 1;
	return (1);
}

void	ls(char **found, int found_num, t_ls_info *info, char *pre_dir_name)
{
	t_ls_msg all;
	t_ls_msg dir;
	t_ls_var var;

	if (ls_print_dir_head(found, info, pre_dir_name) == 0)
		return ;
	init_msg(&all, &dir, 0, found_num);
	get_data(found, &all, pre_dir_name);
	sort_by_flags(&all, info);
	free(found);
	ls_sprint_msg(&all, info, pre_dir_name);
	if (info->flag['R'])
	{
		separate_files(&all, &dir);
		if (dir.num)
		{
			var.i = -1;
			while (++var.i < dir.num)
			{
				var.path = dir.data_arr[var.i].name;
				ls_read_dir(var, info, pre_dir_name);
			}
		}
	}
	ls_free(all, dir);
}
