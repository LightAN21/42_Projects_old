/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 17:38:21 by jtsai             #+#    #+#             */
/*   Updated: 2018/07/21 14:21:54 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_near(char *s, int i)
{
	int	n;

	n = 0;
	if (i - 1 >= 0 && s[i - 1] == '#')
		n++;
	if (i - 5 >= 0 && s[i - 5] == '#')
		n++;
	if (i + 1 < 20 && s[i + 1] == '#')
		n++;
	if (i + 5 < 20 && s[i + 5] == '#')
		n++;
	return (n);
}

int	check_block(char *s)
{
	int	i;
	int num;
	int	near;

	i = -1;
	num = 0;
	near = 0;
	while (++i < 20)
	{
		if ((i % 5 == 4 && s[i] != '\n') ||
				(i % 5 != 4 && s[i] != '.' && s[i] != '#'))
			return (0);
		if (s[i] == '#')
		{
			num++;
			near += num_near(s, i);
		}
	}
	if (num != 4 || near < 6)
		return (0);
	return (1);
}

int	checkvalid(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (check_block(s + i) == 0)
			return (0);
		i += 20;
		if (s[i] != '\n' && s[i] != '\0')
			return (0);
		if (s[i] == '\n')
		{
			if (s[i + 1] == '\0')
				return (0);
			i++;
		}
	}
	return (1);
}
