/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:20:29 by jtsai             #+#    #+#             */
/*   Updated: 2019/10/15 15:54:53 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/syslimits.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>
# include <string.h>
# include <limits.h>
# include <sys/acl.h>

# define LS_BUFF_SIZE 4096
# define TIME_DIFF 15724800

typedef struct		s_ls_data
{
	char			*name;
	char			type;
	struct stat		data;
}					t_ls_data;

typedef struct		s_ls_msg
{
	char			*path;
	int				num;
	t_ls_data		*data_arr;
}					t_ls_msg;

typedef struct		s_ls_info
{
	int				flag_def[128];
	int				flag[128];
	int				mark;
	int				found_num;
	int				error_num;
	int				total_num;
	char			*dir_name;
	char			**found;
	t_ls_data		*error;
	int				buff_i;
	char			buff[LS_BUFF_SIZE];
}					t_ls_info;

typedef struct		s_ls_var
{
	int				i;
	int				j;
	struct dirent	*read;
	DIR				*d;
	char			*r;
	char			*path;
	char			*new_path;
	char			**found;
	int				found_num;
	int				sum;
}					t_ls_var;

void				init_ls(t_ls_info *info, int argc);
void				ls_free(t_ls_msg all, t_ls_msg dir);
int					illegal_option(char c);
int					permission_denied(char *s);
void				data_heap_sort(t_ls_data *arr, int length,
						int (*cmp)(t_ls_data, t_ls_data));
int					reverse_strcmp(const char *a, const char *b);

void				init_msg(t_ls_msg *all, t_ls_msg *dir, t_ls_msg *file,
						int found_num);
void				ls_first_step(t_ls_info *info);
void				ls_read_dir_first_step(t_ls_msg *dir, t_ls_info *info);
void				ls(char **found, int found_num, t_ls_info *info,
						char *pre_dir_name);
void				ls_sprint_msg(t_ls_msg *msg, t_ls_info *info, char *path);
void				ls_flag_l(t_ls_data msg, char *path);
void				sort_by_flags(t_ls_msg *s, t_ls_info *info);
int					name_start_with_dot(char *path);

char				file_type(mode_t mode);
int					cmp_data_alpha(t_ls_data a, t_ls_data b);
int					cmp_data_alpha_reverse(t_ls_data a, t_ls_data b);
int					cmp_data_time(t_ls_data a, t_ls_data b);
int					cmp_data_time_reverse(t_ls_data a, t_ls_data b);

#endif
