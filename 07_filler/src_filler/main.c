/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:59:31 by jtsai             #+#    #+#             */
/*   Updated: 2018/10/24 18:27:19 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_info(t_info *info)
{
	info->p_size.x = 0;
	info->p_size.y = 0;
	info->ans.x = 0;
	info->ans.y = 0;
	info->s.p_num = 0;
	info->s.me_num = 0;
	info->s.you_num = 0;
	info->s.cor_num = 0;
}

void	init_map(t_info *info)
{
	int	i;

	init_info(info);
	info->size.x = 0;
	info->size.y = 0;
	info->check_end_pre = 0;
	info->check_end = 0;
	info->map = (char **)malloc((WIDTH + 1) * sizeof(char *));
	info->tmp_m = (int **)malloc((WIDTH + 1) * sizeof(int *));
	info->tmp_y = (int **)malloc((WIDTH + 1) * sizeof(int *));
	i = -1;
	while (++i < WIDTH)
	{
		info->map[i] = (char *)malloc((WIDTH + 1) * sizeof(char));
		info->tmp_m[i] = (int *)malloc((WIDTH + 1) * sizeof(int));
		info->tmp_y[i] = (int *)malloc((WIDTH + 1) * sizeof(int));
	}
}

void	print_ans(t_info *info)
{
	int	i;

	save_boundry(info, info->s.me, &info->s.me_num);
	save_boundry(info, info->s.you, &info->s.you_num);
	i = -1;
	while (++i < info->s.me_num)
		save_valid_coor(info, info->s.me[i].x, info->s.me[i].y, i);
	if (info->s.cor_num != 0)
	{
		strategy(info);
		ft_printf("%d %d\n", info->ans.x, info->ans.y);
	}
	else
		ft_printf("0 0\n");
	init_info(info);
	info->check_end_pre = info->check_end;
	info->check_end = 0;
}

int		main(void)
{
	int		k;
	char	*s;
	t_info	info;

	init_map(&info);
	while (1)
	{
		k = get_next_line(0, &s);
		if (k <= 0)
			break ;
		else if ('0' <= s[0] && s[0] <= '9')
			read_map(&info, s);
		else if (s[0] == 'P' && s[1] == 'i')
			read_piece(&info, s);
		else if (s[0] == '$')
			read_info(&info, s);
		else if (info.size.x == 0 && s[0] == 'P' && s[1] == 'l')
			read_map_size(&info, s);
		if (info.p_size.x != 0)
			print_ans(&info);
		free(s);
	}
	return (0);
}
