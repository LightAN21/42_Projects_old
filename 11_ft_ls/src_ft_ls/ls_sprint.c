/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:45:40 by jtsai             #+#    #+#             */
/*   Updated: 2019/10/15 14:26:27 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	file_type(mode_t mode)
{
	mode_t	m;

	m = mode & S_IFMT;
	if (m == S_IFREG)
		return ('-');
	else if (m == S_IFDIR)
		return ('d');
	else if (m == S_IFLNK)
		return ('l');
	else if (m == S_IFBLK)
		return ('b');
	else if (m == S_IFCHR)
		return ('c');
	else if (m == S_IFIFO)
		return ('p');
	else if (m == S_IFSOCK)
		return ('s');
	return ('?');
}

void	ls_flag_l_total(t_ls_msg *msg, t_ls_info *info)
{
	int		i;
	quad_t	sum;
	char	*tmp;

	sum = 0;
	i = -1;
	while (++i < msg->num)
	{
		tmp = msg->data_arr[i].name;
		if (tmp[0] != '.' || info->flag['a'])
			sum += msg->data_arr[i].data.st_blocks;
	}
	ft_printf("total %lld\n", sum);
}

void	ls_sprint_msg(t_ls_msg *msg, t_ls_info *info, char *path)
{
	int		i;
	char	*tmp;

	if (info->flag['l'] && path && (info->flag['a'] || msg->num > 2))
		ls_flag_l_total(msg, info);
	tmp = 0;
	i = -1;
	while (++i < msg->num)
	{
		if (!info->flag['a']
			&& name_start_with_dot(msg->data_arr[i].name))
			continue;
		if (info->flag['l'])
		{
			tmp = ft_strjoin_c(path, msg->data_arr[i].name, '/');
			ls_flag_l(msg->data_arr[i], tmp);
			if (tmp && path)
			{
				free(tmp);
				tmp = 0;
			}
		}
		else
			ft_printf("%s\n", msg->data_arr[i].name);
	}
}
