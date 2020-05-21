/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:26:32 by jtsai             #+#    #+#             */
/*   Updated: 2018/08/12 19:02:07 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	base(char c)
{
	if ('0' <= c && c <= '9')
		return (c - '0');
	else if ('A' <= c && c <= 'F')
		return (10 + c - 'A');
	else if ('a' <= c && c <= 'f')
		return (10 + c - 'a');
	return (-42);
}

int	color_num(char *s, int i)
{
	int	j;
	int	color;

	if (s[i + 1] != '0' || s[i + 2] != 'x' || s[i + 3] == '\0')
		return (-42);
	color = 0;
	i += 2;
	j = 0;
	while (++j <= 6 && s[i + j] != '\0')
	{
		if (base(s[i + j]) == -42)
			return (-42);
		color = 16 * color + base(s[i + j]);
	}
	if (s[i + j])
		return (-42);
	return (color);
}

int	fix_colors(char *s)
{
	int	i;

	if ((s[0] < '0' || s[0] > '9') && s[0] != '-' && s[0] != '+')
		return (-42);
	if ((s[0] == '-' || s[0] == '+') && (s[1] < '0' || s[1] > '9'))
		return (-42);
	i = 0;
	while (s[i] == '-' || s[i] == '+')
		i++;
	while ('0' <= s[i] && s[i] <= '9')
		i++;
	if (s[i] == '\0')
		return (0);
	if (s[i] == ',')
		return (color_num(s, i));
	return (-42);
}
