/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:59:59 by jtsai             #+#    #+#             */
/*   Updated: 2018/10/24 18:27:52 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	read_coor(t_mlx *info, char *s)
{
	int	i;

	i = 0;
	while (s[i] != '(')
		i++;
	info->player = s[++i];
	while (s[i] != '[')
		i++;
	info->ans_x = ft_atoi(s + ++i);
	while (s[i] != ' ')
		i++;
	info->ans_y = ft_atoi(s + i);
}

void	read_piece(t_mlx *info, char *s)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (s[i] != ' ' && s[i])
		i++;
	info->p_x = ft_atoi(s + i++);
	while (s[i] != ' ' && s[i])
		i++;
	info->p_y = ft_atoi(s + i);
	i = -1;
	while (++i < info->p_x)
	{
		get_next_line(0, &tmp);
		j = -1;
		while (++j < info->p_y)
			info->p[i][j] = tmp[j];
		info->p[i][j] = '\0';
		free(tmp);
	}
}

void	read_map_size(t_mlx *info, char *s)
{
	int	i;

	i = 1;
	while (s[i] != ' ' && s[i])
		i++;
	info->m_x = ft_atoi(s + i++);
	while (s[i] != ' ' && s[i])
		i++;
	info->m_y = ft_atoi(s + i);
}

void	read_map(t_mlx *info, char *s)
{
	int	i;
	int	j;
	int	row;

	row = ft_atoi(s);
	j = 0;
	i = 4;
	while (s[i])
	{
		info->map[row][j++] = s[i];
		i++;
	}
	info->map[row][j] = '\0';
}

void	read_info(t_mlx *p)
{
	int		k;
	char	*s;

	while (1)
	{
		k = get_next_line(0, &s);
		if (k <= 0)
			break ;
		else if (s[0] == 'P' && s[1] == 'l')
			read_map_size(p, s);
		else if ('0' <= s[0] && s[0] <= '9')
			read_map(p, s);
		else if (s[0] == 'P' && s[1] == 'i')
		{
			read_piece(p, s);
			free(s);
			break ;
		}
		free(s);
	}
}
