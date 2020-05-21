/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 11:13:01 by jtsai             #+#    #+#             */
/*   Updated: 2018/08/12 19:11:01 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	special_map(void)
{
	ft_putstr("===============================================\n");
	ft_putstr("Warning! (Special Map)\n");
	ft_putstr("The base of the map is not a rectangle, ");
	ft_putstr("or\nthe map has empty lines.\n");
	ft_putstr("===============================================\n");
}

int		error(int e)
{
	if (e == 'o')
		ft_putstr("Error: open() failed.\n");
	else if (e == 'c')
		ft_putstr("Error: close() failed.\n");
	else if (e == 'm')
		ft_putstr("Error: malloc() failed.\n");
	else if (e == 'g')
		ft_putstr("Error: read() failed or malloc() failed.\n");
	else if (e == 'i')
		ft_putstr("Error: mlx_init() failed.\n");
	else if (e == 'w')
		ft_putstr("Error: mlx_new_window() failed.\n");
	else if (e == 'e')
	{
		ft_putstr("Error: empty file or the map in the ");
		ft_putstr("source file end with an empty line(invalid map).\n");
	}
	else if (e == -42)
		ft_putstr("Error: the map in the source file is invalid.\n");
	else if (e == -100)
		special_map();
	return (-1);
}

void	messages(t_fdf *p)
{
	int	n;

	n = 0;
	if (p->invalid == 1)
	{
		mlx_string_put(p->mlx, p->win, 4, 5, 0xFF5500,
				"Warning! (Special Map)");
		mlx_string_put(p->mlx, p->win, 4, 25, 0xFF5500,
				"The base of the map is not a rectangle,");
		mlx_string_put(p->mlx, p->win, 4, 45, 0xFF5500,
				"or the map has empty lines.");
		n = 60;
	}
	mlx_string_put(p->mlx, p->win, 4, 5 + n, 0x66C2FF, "[ esc ] : Exit");
	mlx_string_put(p->mlx, p->win, 4, 25 + n, 0x66C2FF,
			"[ arrow keys ] : Rotation");
	mlx_string_put(p->mlx, p->win, 4, 45 + n, 0x66C2FF,
			"[ a, s, d, w ] : Move");
	mlx_string_put(p->mlx, p->win, 4, 65 + n, 0x66C2FF, "[ +, - ] : Zoom");
	mlx_string_put(p->mlx, p->win, 4, 85 + n, 0x66C2FF,
			"[ i, k ] : Change hight");
	mlx_string_put(p->mlx, p->win, 4, 105 + n, 0x66C2FF, "[ space ] : Reset");
}
