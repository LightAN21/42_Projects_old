/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 07:56:54 by jtsai             #+#    #+#             */
/*   Updated: 2019/11/16 16:16:17 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/jtsai_dictionary/ft_dictionary.h"
# include "../lib/jtsai_stack_queue/ft_stack_queue.h"
# include <fcntl.h>

typedef struct		s_lines
{
	char			*data;
	struct s_lines	*next;
}					t_lines;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				ants;
	int				order;
	int				link_num;
	int				mark;
	int				ant_id;
	t_ft_dict		*nbr;
	struct s_room	*pre;
	struct s_room	*next;
	struct s_room	**nbr_list;
}					t_room;

typedef struct		s_flow
{
	int				num;
	int				ideal_steps;
	t_ft_queue		**queue;
	t_ft_queue		*bfs_path;
	int				*send;
	int				rounds;
}					t_flow;

typedef struct		s_info
{
	t_room			**roomlist;
	t_flow			*main_flow;
	t_ft_queue		*flow_queue;
	t_ft_queue		*que;
	t_ft_queue		**move_list;
	int				*ants_allocation;
	int				mark;
	int				file;
	int				ants;
	int				links;
	int				rooms;
	t_ft_dict		*dict;
	t_room			*start;
	t_room			*end;
	t_lines			*lines;
	t_lines			*tail;
	int				steps;
	int				ant_id;
	int				ants_at_end;
	int				ants_copy;
	int				print_info;
	int				print_relation;
	int				print_room_info;
	int				print_steps;
	int				print_main_flow;
	int				print_all_flows;
	int				print_ants_allocation;
	int				print_without_map;
}					t_info;

typedef struct		s_tmp_var
{
	int				i;
	int				j;
	t_room			*curr_room;
	t_room			*nbr;
	t_dict_list		*ele;
	t_ft_queue		*s;
	int				additional_ants;
	int				remain;
	int				sum;
	int				rounds;
	int				steps;
}					t_tmp_var;

int					error_message(t_info *info);
int					no_possible_solution(t_info *info);

int					get_arguments(t_info *info, int ac, char **av);
int					save_line(char *s, t_info *info);
int					check_info(char *s, t_info *info);

int					make_roomlist(t_info *info);
int					make_order(t_info *info, int ord);

int					room_cmp(t_room *a, t_room *b);
void				data_heap_sort(t_room **arr, int length,\
					int (*cmp)(t_room *, t_room *));

int					queue_len_cmp(t_ft_queue *a, t_ft_queue *b);
void				flow_heap_sort(t_ft_queue **arr, int length,\
					int (*cmp)(t_ft_queue *, t_ft_queue *));

int					fix_flow(t_info *info, t_flow *flow);
int					find_flows_by_edmonds_karp(t_info *info);
void				breadth_first_search(t_info *info, t_room *start);
void				flow_record(t_info *info, t_flow *flow);
void				get_new_flow_combination(t_info *info, t_flow *flow);

int					find_solution(t_info *info, t_flow *main_flow);
void				build_paths_for_ants(t_info *info, t_flow *main_flow);
void				move_ants(t_info *info, t_flow *main_flow);

void				print_map(t_info *info);
void				print_info(t_info *info);
void				print_room_relation(t_info *info);
void				print_room_info(t_info *info);

void				print_flows(t_info *info);
void				print_main_flow(t_info *info);
void				print_all_flows(t_info *info);
void				print_ants_allocation(t_info *info);

int					check_fail_free_split(char **s);
int					free_move_list(t_info *info);
int					fail(char *tmp);
#endif
