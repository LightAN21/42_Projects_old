/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 09:51:29 by jtsai             #+#    #+#             */
/*   Updated: 2018/10/06 08:46:54 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include <stdio.h>
# include "../lib/minilibx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>

# define WIDTH	200

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	char		map[WIDTH][WIDTH];
	char		p[WIDTH][WIDTH];
	char		player;
	int			m_x;
	int			m_y;
	int			p_x;
	int			p_y;
	int			ans_x;
	int			ans_y;
	int			p1;
	int			p2;
	int			end;
}				t_mlx;

void			read_info(t_mlx *p);
void			read_coor(t_mlx *info, char *s);
void			read_piece(t_mlx *info, char *s);

void			draw_map(t_mlx *p);
void			print_piece(t_mlx *p, int color);

#endif
