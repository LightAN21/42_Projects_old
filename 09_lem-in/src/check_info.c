/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:59:35 by jtsai             #+#    #+#             */
/*   Updated: 2019/11/16 16:58:50 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_room(char **sep, t_info *info, t_room *room)
{
	int	i;

	room->x = ft_atoi(sep[1]);
	room->y = ft_atoi(sep[2]);
	room->ants = 0;
	room->order = -1;
	room->link_num = 0;
	room->mark = 0;
	room->ant_id = 0;
	room->nbr = dict_new();
	room->pre = 0;
	room->next = 0;
	room->nbr_list = 0;
	dict_add(info->dict, sep[0], room);
	info->rooms++;
	i = -1;
	while (sep[++i])
		free(sep[i]);
	free(sep);
}

int		check_room(char *s, t_info *info, int mark)
{
	char	**sep;
	t_room	*room;

	if (s[0] == 'L' || ft_words(s, ' ') != 3 || info->links)
		return (-1);
	if (!(sep = ft_strsplit(s, ' ')))
		return (-1);
	if (ft_strchr(sep[0], '-') || !ft_isnum(sep[1]) || !ft_isnum(sep[2]))
		return (check_fail_free_split(sep));
	if (dict_get(info->dict, sep[0]))
		return (check_fail_free_split(sep));
	if (!(room = (t_room *)malloc(sizeof(t_room))))
		return (check_fail_free_split(sep));
	if (!(room->name = ft_strsub(sep[0], 0, ft_strlen(sep[0]))))
		return (check_fail_free_split(sep));
	init_room(sep, info, room);
	if (mark == 1)
		info->start = room;
	else if (mark == 2)
		info->end = room;
	return (1);
}

int		check_link(char *s, t_info *info)
{
	char	**sep;
	t_room	*r1;
	t_room	*r2;

	if (ft_words(s, '-') != 2)
		return (-1);
	if (!(sep = ft_strsplit(s, '-')))
		return (-1);
	r1 = (t_room *)dict_get(info->dict, sep[0]);
	r2 = (t_room *)dict_get(info->dict, sep[1]);
	if (!r1 || !r2)
		return (check_fail_free_split(sep));
	info->links++;
	if (!dict_get(r1->nbr, r2->name) && !dict_get(r2->nbr, r1->name))
	{
		dict_add(r1->nbr, r2->name, r2);
		dict_add(r2->nbr, r1->name, r1);
		r1->link_num++;
		if (r1 != r2)
			r2->link_num++;
	}
	free(sep[0]);
	free(sep[1]);
	free(sep);
	return (1);
}

int		check_start_end(char *s, t_info *info)
{
	int		mark;
	int		k;
	char	*tmp;

	k = (ft_strcmp("##end", s) == 0) ? 2 : 0;
	mark = (ft_strcmp("##start", s) == 0) ? 1 : k;
	if (mark == 0)
		return (1);
	if ((mark == 1 && info->start) || (mark == 2 && info->end))
		return (-1);
	while (1)
	{
		if ((k = get_next_line(info->file, &tmp)) <= 0)
			return (-1);
		if (tmp[0] != '#')
			break ;
		free(tmp);
	}
	if (save_line(tmp, info) < 0)
		return (fail(tmp));
	if (check_room(tmp, info, mark) < 0)
		return (fail(tmp));
	if (tmp)
		free(tmp);
	return (1);
}

int		check_info(char *s, t_info *info)
{
	if (save_line(s, info) < 0)
		return (-1);
	if (s[0] == '#' && s[1] == '#')
	{
		if (check_start_end(s, info) < 0)
			return (-1);
	}
	else if (s[0] == '#')
		return (1);
	else if (ft_strchr(s, ' '))
	{
		if (check_room(s, info, 0) < 0)
			return (-1);
	}
	else if (ft_countchar(s, '-') == 1)
	{
		if (check_link(s, info) < 0)
			return (-1);
	}
	else
		return (-1);
	return (1);
}
