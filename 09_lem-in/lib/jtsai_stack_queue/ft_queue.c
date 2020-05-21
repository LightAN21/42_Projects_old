/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 09:14:23 by jtsai             #+#    #+#             */
/*   Updated: 2018/10/29 10:53:26 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack_queue.h"

t_ft_queue	*queue_new(void)
{
	t_ft_queue	*new;

	if (!(new = (t_ft_queue *)malloc(sizeof(t_ft_queue))))
		return (NULL);
	new->size = 0;
	new->front = NULL;
	new->tail = NULL;
	return (new);
}

int			queue_push(t_ft_queue *que, void *data)
{
	t_queue_node	*n;

	if (!que)
		return (1);
	if (!(n = (t_queue_node *)malloc(sizeof(t_queue_node))))
		return (0);
	n->data = data;
	n->next = NULL;
	if (que->tail)
	{
		que->tail->next = n;
		que->tail = n;
	}
	else
	{
		que->tail = n;
		que->front = n;
	}
	que->size++;
	return (1);
}

void		*queue_pop(t_ft_queue *que)
{
	t_queue_node	*tmp;
	void			*data;

	if (!que || que->size == 0)
		return (NULL);
	data = que->front->data;
	if (que->size - 1)
	{
		tmp = que->front->next;
		free(que->front);
		que->front = tmp;
	}
	else
	{
		free(que->front);
		que->front = NULL;
		que->tail = NULL;
	}
	que->size--;
	return (data);
}

void		queue_clear(t_ft_queue *que)
{
	t_queue_node	*tmp;

	if (!que || !que->front)
		return ;
	while (que->front)
	{
		tmp = que->front->next;
		free(que->front);
		que->front = tmp;
	}
	que->tail = NULL;
	que->size = 0;
}

void		queue_free(t_ft_queue *que)
{
	queue_clear(que);
	free(que);
}
