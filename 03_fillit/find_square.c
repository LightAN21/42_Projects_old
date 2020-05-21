/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:16:37 by jtsai             #+#    #+#             */
/*   Updated: 2018/07/26 14:30:31 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		try_position(t_sqr *q, t_trim *t, int n)
{
	int	p;

	p = -1;
	while (++p < q->size)
	{
		if (q->square[p] != '.')
			continue ;
		if (check_trimino(q, t[n], p) == 0)
			continue ;
		put_trimino(q, t[n], p);
		if (n + 1 == q->num)
			return (1);
		if (try_position(q, t, n + 1) == 1)
			return (1);
		erase_trimino(q, t[n], p);
	}
	return (0);
}

int		find_square(t_trim *t, int num)
{
	int		len;
	t_sqr	q;

	len = 1;
	while (len * len < 4 * num)
		len++;
	while (len > 0)
	{
		if (!(q.square = (char *)malloc((len + 1) * (len + 1) * sizeof(char))))
			return (0);
		q.len = len;
		q.size = len * (len + 1);
		q.num = num;
		initialize(q.square, q.len);
		if (try_position(&q, t, 0))
		{
			write(1, q.square, q.size);
			len = -42;
		}
		free(q.square);
		len++;
	}
	return (1);
}
