/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:26:20 by jtsai             #+#    #+#             */
/*   Updated: 2019/11/07 14:04:36 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(void)
{
	write(1, "usage: ./fractal \"fractal name\"\n\n", 33);
	write(1, "fractal name:\n", 14);
	write(1, "Julia\n", 6);
	write(1, "Mandelbort\n", 11);
	write(1, "Tricorn\n", 8);
	write(1, "\n", 1);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "Julia") == 0)
			julia();
		else if (ft_strcmp(av[1], "Mandelbort") == 0)
			mandelbort();
		else if (ft_strcmp(av[1], "Tricorn") == 0)
			tricorn();
		else if (ft_strcmp(av[1], "try1") == 0)
			try_1();
		else
			usage();
	}
	else
		usage();
	return (0);
}
