/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:59:59 by jtsai             #+#    #+#             */
/*   Updated: 2018/10/06 09:06:48 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_info(t_info *info, char *s)
{
	int		i;
	int		j;
	char	k;
	char	*me;

	me = "[./jtsai.filler]";
	i = 0;
	while (s[i] != 'p')
		i++;
	k = s[++i];
	while (s[i] != '[')
		i++;
	j = 0;
	while (s[i] != ']')
	{
		if (me[j++] != s[i++])
			break ;
	}
	if (me[j] == ']' && s[i] == ']')
	{
		info->me = (k == '1') ? 'O' : 'X';
		info->you = (k == '1') ? 'X' : 'O';
	}
}

void	read_map_size(t_info *info, char *s)
{
	int	i;

	i = 1;
	while (s[i] != ' ' && s[i])
		i++;
	info->size.x = ft_atoi(s + i++);
	while (s[i] != ' ' && s[i])
		i++;
	info->size.y = ft_atoi(s + i);
}

void	read_map(t_info *info, char *s)
{
	int		i;
	int		j;
	int		row;
	char	c;

	row = ft_atoi(s);
	j = 0;
	i = 3;
	while (s[++i])
	{
		c = (s[i] == 'o' || s[i] == 'x') ? s[i] + 'A' - 'a' : s[i];
		if (c == info->me)
		{
			info->s.me[info->s.me_num].x = row;
			info->s.me[info->s.me_num++].y = j;
		}
		if (c == info->you)
		{
			info->s.you[info->s.you_num].x = row;
			info->s.you[info->s.you_num++].y = j;
			info->check_end++;
		}
		info->map[row][j++] = c;
	}
	info->map[row][j] = '\0';
}

void	save_star_position(t_info *info)
{
	int	i;
	int	j;

	info->s.p_num = 0;
	i = -1;
	while (++i < info->p_size.x)
	{
		j = -1;
		while (++j < info->p_size.y)
		{
			if (info->piece[i][j] == '*')
			{
				info->s.p[info->s.p_num].x = i;
				info->s.p[info->s.p_num++].y = j;
			}
		}
	}
}

void	read_piece(t_info *info, char *s)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (s[i] != ' ' && s[i])
		i++;
	info->p_size.x = ft_atoi(s + i++);
	while (s[i] != ' ' && s[i])
		i++;
	info->p_size.y = ft_atoi(s + i);
	i = -1;
	while (++i < info->p_size.x)
	{
		get_next_line(0, &tmp);
		j = -1;
		while (++j < info->p_size.y)
			info->piece[i][j] = tmp[j];
		info->piece[i][j] = '\0';
		free(tmp);
	}
	save_star_position(info);
}
