/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 10:36:37 by jtsai             #+#    #+#             */
/*   Updated: 2018/10/06 09:33:58 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>

# define WIDTH	200
# define MAX	WIDTH * WIDTH
# define MARK	WIDTH * 4

typedef struct	s_xy
{
	int			x;
	int			y;
	int			min;
	int			max;
}				t_xy;

typedef struct	s_tmp
{
	int			k;
	int			len;
	int			pre;
	int			now;
	int			num;
}				t_tmp;

typedef struct	s_save
{
	t_xy		p[MAX];
	int			p_num;
	t_xy		cor[MAX];
	int			cor_num;
	t_xy		me[MAX];
	int			me_num;
	t_xy		you[MAX];
	int			you_num;
	t_xy		ans[MAX];
	int			ans_num;
}				t_save;

typedef struct	s_info
{
	int			**tmp_m;
	int			**tmp_y;
	int			tmp;
	t_save		s;
	char		**map;
	char		piece[WIDTH][WIDTH];
	t_xy		size;
	t_xy		p_size;
	t_xy		ans;
	char		me;
	char		you;
	int			min_len;
	int			check_end_pre;
	int			check_end;
	int			file;
}				t_info;

void			read_info(t_info *info, char *s);
void			read_map_size(t_info *info, char *s);
void			read_map(t_info *info, char *s);
void			read_piece(t_info *info, char *s);
void			init_map(t_info *info);

void			save_valid_coor(t_info *info, int x, int y, int num);
void			save_boundry(t_info *info, t_xy *d, int *num);

void			strategy(t_info *info);
void			find_answer(t_info *info);

#endif
