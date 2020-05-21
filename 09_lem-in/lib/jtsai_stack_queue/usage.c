/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 10:38:27 by jtsai             #+#    #+#             */
/*   Updated: 2018/10/29 11:10:43 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack_queue.h"

void	print_stack(t_ft_stack *s)
{
	t_stack_node	*tmp;

	if (!s || !s->top)
	{
		printf("(null)\n");
		return ;
	}
	tmp = s->top;
	while (tmp)
	{
		printf("%s\n", (char *)(tmp->data));
		tmp = tmp->next;
	}
}

void	print_queue(t_ft_queue *q)
{
	t_queue_node	*tmp;

	if (!q || !q->front)
	{
		printf("(null)\n");
		return ;
	}
	tmp = q->front;
	while (tmp)
	{
		printf("%s\n", (char *)(tmp->data));
		tmp = tmp->next;
	}
}

void	test_stack(void)
{
	t_ft_stack	*s;

	s = stack_new();
	printf("stack size = %d\n", s->size);
	print_stack(s);
	printf("-----------------\n");
	stack_push(s, "Miku!");
	stack_push(s, "am");
	stack_push(s, "I");
	stack_push(s, "Hi!");
	printf("stack size = %d\n", s->size);
	print_stack(s);
	printf("-----------------\n");
	printf("%s\n", (char *)stack_pop(s));
	printf("stack size = %d\n", s->size);
	print_stack(s);
	printf("-----------------\n");
	stack_clear(s);
	printf("stack size = %d\n", s->size);
	print_stack(s);
	free(s);
}

void	test_queue(void)
{
	t_ft_queue	*q;

	q = queue_new();
	printf("queue size = %d\n", q->size);
	print_queue(q);
	printf("-----------------\n");
	queue_push(q, "Hi!");
	printf("queue size = %d\n", q->size);
	printf("queue front = %s\n", (char *)q->front->data);
	printf("queue tail = %s\n", (char *)q->tail->data);
	print_queue(q);
	printf("-----------------\n");
	queue_push(q, "I");
	queue_push(q, "am");
	queue_push(q, "Miku!");
	printf("queue size = %d\n", q->size);
	printf("queue front = %s\n", (char *)q->front->data);
	printf("queue tail = %s\n", (char *)q->tail->data);
	print_queue(q);
	printf("-----------------\n");
	queue_clear(q);
	printf("queue size = %d\n", q->size);
	print_queue(q);
	free(q);
}

int		main(void)
{
	test_stack();
	printf("=============================\n");
	test_queue();
	return (0);
}
