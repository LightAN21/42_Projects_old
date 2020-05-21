/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_first_step.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:45:29 by jtsai             #+#    #+#             */
/*   Updated: 2019/10/15 15:55:17 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		name_start_with_dot(char *path)
{
	int	i;

	i = ft_strlen(path);
	if (i == 0)
		return (0);
	i--;
	while (i >= 0 && path[i] != '/')
		i--;
	if (path[i + 1] == '.')
		return (1);
	return (0);
}

void	get_data_0(char **found, t_ls_msg *all, t_ls_info *info)
{
	int			i;
	char		t;
	t_ls_var	var;

	i = -1;
	while (found[++i])
	{
		all->data_arr[all->num].name = found[i];
		if (readlink(found[i], 0, 0) == -1)
			stat(found[i], &(all->data_arr[all->num].data));
		else
			lstat(found[i], &(all->data_arr[all->num].data));
		t = file_type(all->data_arr[all->num].data.st_mode);
		all->data_arr[all->num].type = t;
		if (t == 'l' && info->flag['l'] == 0)
		{
			var.d = opendir(found[i]);
			if (var.d)
			{
				stat(found[i], &(all->data_arr[all->num].data));
				closedir(var.d);
			}
		}
		all->num++;
	}
}

void	separate_files_0(t_ls_msg *all, t_ls_msg *dir, t_ls_msg *file,
		t_ls_info *info)
{
	int		i;
	char	c;

	i = -1;
	while (++i < all->num)
	{
		c = all->data_arr[i].type;
		if (c == 'd' || (c == 'l' && info->flag['l'] == 0))
		{
			dir->data_arr[dir->num++] = all->data_arr[i];
		}
		else
		{
			file->data_arr[file->num++] = all->data_arr[i];
		}
	}
}

void	ls_read_dir_first_step(t_ls_msg *dir, t_ls_info *info)
{
	t_ls_var	var;

	var.i = -1;
	while (++var.i < dir->num)
	{
		var.path = dir->data_arr[var.i].name;
		var.d = opendir(var.path);
		if (var.d)
		{
			while ((var.read = readdir(var.d)) != NULL)
				var.found_num++;
			closedir(var.d);
			var.found = (char **)malloc((1 + var.found_num) * sizeof(char *));
			var.j = 0;
			var.d = opendir(var.path);
			while ((var.read = readdir(var.d)) != NULL)
				var.found[var.j++] = ft_strdup(var.read->d_name);
			var.found[var.j] = 0;
			closedir(var.d);
			ls(var.found, var.found_num, info, var.path);
		}
		else
			ls(0, 0, info, var.path);
	}
}

void	ls_first_step(t_ls_info *info)
{
	t_ls_msg	all;
	t_ls_msg	dir;
	t_ls_msg	file;

	init_msg(&all, &dir, &file, info->found_num);
	get_data_0(info->found, &all, info);
	sort_by_flags(&all, info);
	separate_files_0(&all, &dir, &file, info);
	free(info->found);
	if (file.num)
	{
		ls_sprint_msg(&file, info, 0);
		info->mark = 1;
	}
	if (dir.num)
	{
		ls_read_dir_first_step(&dir, info);
	}
	free(all.data_arr);
	free(dir.data_arr);
	free(file.data_arr);
}
