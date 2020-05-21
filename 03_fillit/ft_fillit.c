/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 17:26:47 by jtsai             #+#    #+#             */
/*   Updated: 2018/07/26 12:47:57 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	copy_blocks(char *s, t_trim *t, int c)
{
	int	i;
	int n;

	i = -1;
	n = 0;
	while (++i < 20)
	{
		if (s[i] == '#')
		{
			t->po[n] = i;
			n++;
		}
	}
	t->id = c;
}

int		ft_fillit(char *s, int size)
{
	t_trim	*t;
	int		i;
	int		num;
	int		id;

	if (checkvalid(s) == 0)
		return (0);
	if (!(t = (t_trim *)malloc(((size + 1) / 21 + 1) * sizeof(t_trim))))
		return (0);
	i = 0;
	num = 0;
	id = 0;
	while (i < size)
	{
		copy_blocks(s + i, &(t[num++]), id++);
		i += 21;
	}
	if (!(find_square(t, (size + 1) / 21)))
		return (0);
	free(t);
	return (1);
}
