/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 09:14:23 by jtsai             #+#    #+#             */
/*   Updated: 2018/10/29 10:55:58 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack_queue.h"

t_ft_stack	*stack_new(void)
{
	t_ft_stack	*new;

	if (!(new = (t_ft_stack *)malloc(sizeof(t_ft_stack))))
		return (NULL);
	new->size = 0;
	new->top = NULL;
	return (new);
}

int			stack_push(t_ft_stack *stk, void *data)
{
	t_stack_node	*n;

	if (!stk)
		return (1);
	if (!(n = (t_stack_node *)malloc(sizeof(t_stack_node))))
		return (0);
	n->data = data;
	n->next = stk->top;
	stk->top = n;
	stk->size++;
	return (1);
}

void		*stack_pop(t_ft_stack *stk)
{
	t_stack_node	*tmp;
	void			*data;

	if (!stk || stk->size == 0)
		return (NULL);
	data = stk->top->data;
	tmp = stk->top->next;
	free(stk->top);
	stk->top = tmp;
	stk->size--;
	return (data);
}

void		stack_clear(t_ft_stack *stk)
{
	t_stack_node	*tmp;

	if (!stk)
		return ;
	while (stk->top)
	{
		tmp = stk->top->next;
		free(stk->top);
		stk->top = tmp;
	}
	stk->size = 0;
}

void		stack_free(t_ft_stack *stk)
{
	stack_clear(stk);
	free(stk);
}
