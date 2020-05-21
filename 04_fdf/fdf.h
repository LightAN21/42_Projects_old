/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 11:05:23 by jtsai             #+#    #+#             */
/*   Updated: 2018/08/12 20:12:28 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include "get_next_line.h"
# include "libft/includes/libft.h"
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	int				win_h;
	int				invalid;
	int				**map;
	int				**map_color;
	int				map_line;
	int				*map_len;
	int				max_len;
	int				x;
	int				y;
	int				i;
	int				j;
	int				x1;
	int				y1;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				n;
	int				m;
	int				start_x;
	int				start_y;
	int				center_x;
	int				center_y;
	int				ux;
	int				uy;
	int				vx;
	int				vy;
	double			unit_len;
	double			theta;
	double			phi;
	double			h;
	double			divide;
}					t_fdf;

typedef struct		s_map
{
	char			**line;
	int				line_len;
	struct s_map	*next;
}					t_map;

typedef struct		s_draw
{
	int				end_i;
	int				end_j;
	int				tmp_i;
	int				tmp_j;
	int				tmp;
}					t_draw;

void				draw_line(t_fdf *t, int hight, int x2, int y2);
int					read_fdf(int fd, t_fdf *p);
int					window_fdf(t_fdf *p);
int					draw_fdf(t_fdf *p);
int					draw_fdf_w(t_fdf *p);
int					fix_colors(char *s);
int					colors(t_fdf *p, int h, int x2, int y2);
int					error(int e);
void				special_map(void);
void				messages(t_fdf *p);
int					free_map(t_fdf *p, int c);

#endif
