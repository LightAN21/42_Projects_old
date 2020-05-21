/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_queue.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 09:07:15 by jtsai             #+#    #+#             */
/*   Updated: 2018/10/29 11:10:48 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_QUEUE_H
# define FT_STACK_QUEUE_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct			s_stack_node
{
	void				*data;
	struct s_stack_node	*next;
}						t_stack_node;

typedef struct			s_ft_stack
{
	int					size;
	t_stack_node		*top;
}						t_ft_stack;

typedef struct			s_queue_node
{
	void				*data;
	struct s_queue_node	*next;
}						t_queue_node;

typedef struct			s_ft_queue
{
	int					size;
	t_queue_node		*front;
	t_queue_node		*tail;
}						t_ft_queue;

t_ft_stack				*stack_new(void);
int						stack_push(t_ft_stack *stk, void *data);
void					*stack_pop(t_ft_stack *stk);
void					stack_clear(t_ft_stack *stk);
void					stack_free(t_ft_stack *stk);

t_ft_queue				*queue_new(void);
int						queue_push(t_ft_queue *que, void *data);
void					*queue_pop(t_ft_queue *que);
void					queue_clear(t_ft_queue *que);
void					queue_free(t_ft_queue *que);

#endif
