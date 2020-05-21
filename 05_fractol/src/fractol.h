/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:27:39 by jtsai             #+#    #+#             */
/*   Updated: 2019/11/07 13:55:36 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx/mlx.h"
# include "../lib/libft/libft.h"
# include <stdlib.h>
# include <string.h>
# include <math.h>

typedef struct	s_info
{
	void		*mlx;
	void		*win;
	unsigned	*img;
	unsigned	*scr;
	unsigned	color[100];
	void		(*draw)(struct s_info *);
	void		(*def)(struct s_info *);
	int			width;
	int			height;
	int			half_width;
	int			half_height;
	int			zoom_x;
	int			zoom_y;
	int			zoom_on;
	double		zoom;
	double		zoom_init;
	double		zoom_center_x;
	double		zoom_center_y;
	double		center_x;
	double		center_y;
	double		r;
	double		r2;
	double		cr;
	double		cx;
	double		cy;
	double		ctheta;
	int			iter_max;
	int			bits;
	int			size_line;
	int			endian;
	int			i;
}				t_info;

typedef struct	s_var
{
	int			x;
	int			y;
	int			iter;
	double		zx;
	double		zy;
	double		xtmp;
	double		r2;
}				t_var;

void			mandelbrot_default(t_info *info);
void			julia_default(t_info *info);
void			tricorn_default(t_info *info);
void			try_1_default(t_info *info);

int				mandelbort(void);
int				julia(void);
int				tricorn(void);
int				try_1(void);

void			draw_mandelbort(t_info *info);
void			draw_julia(t_info *info);
void			draw_tricorn(t_info *info);
void			draw_try_1(t_info *info);

void			color_init(t_info *info);
unsigned int	color(int iter, int iter_max);
void			put_color(t_info *info, int x, int y, unsigned color);

int				deal_mouse_base(int button, int x, int y, t_info *info);
int				deal_key_base(int key, t_info *info);

int				deal_key_julia(int key, t_info *info);
int				deal_mousemove_julia(int x, int y, t_info *info);

#endif
