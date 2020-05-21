/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_trimino.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:22:05 by jtsai             #+#    #+#             */
/*   Updated: 2018/07/26 12:48:28 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_trimino(t_sqr *q, t_trim t, int p)
{
	int	i;
	int	k;
	int	start;

	start = t.po[0];
	i = -1;
	while (++i < 4)
	{
		k = p + (t.po[i] / 5 - start / 5) * (q->len + 1);
		k += (t.po[i] % 5 - start % 5);
		if (q->square[k] != '.')
			return (0);
	}
	return (1);
}
