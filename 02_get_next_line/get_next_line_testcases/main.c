/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 17:24:26 by jtsai             #+#    #+#             */
/*   Updated: 2018/08/03 09:47:10 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>

void	line(int file, int k, char *s)
{
	int	i;

	i = get_next_line(file, &s);	
	if (i == 0)
	{
		printf("-----------------------\n");
		printf("==============================\n");
		printf("file %d, end\n", file);
		printf("==============================\n");
	}
	else if (i == -1)
	{
		printf("-----------------------\n");
		printf("==============================\n");
		printf("file %d error\n", file);
		printf("==============================\n");
	}
	else
	{
		printf("-----------------------\n");
		printf("==============================\n");
		printf("file %d, line %d:\n%s\n", file, k, s);
		printf("==============================\n");
	}
}

int		main(int ac, char **av)
{
	int		file[10] = {0};
	int		i;
	int		k[10] = {0};
	char	*s;

	if (ac > 1)
	{
		i = 0;
		while (++i < ac)
		{
			if ((file[i] = open(av[i], O_RDONLY)) == -1)
				return (0);
		}

		line(file[1], ++(k[1]), s);
		line(file[1], ++(k[1]), s);
		line(file[1], ++(k[1]), s);
		line(file[1], ++(k[1]), s);
		line(file[1], ++(k[1]), s);
		line(file[1], ++(k[1]), s);

		if (ac > 2)
		{
			line(file[2], ++(k[2]), s);
			line(file[2], ++(k[2]), s);
			line(file[2], ++(k[2]), s);
		}
		if (ac > 3)
		{
			line(file[3], ++(k[3]), s);
			line(file[3], ++(k[3]), s);
			line(file[3], ++(k[3]), s);

			line(file[1], ++(k[1]), s);
			line(file[1], ++(k[1]), s);
			line(file[1], ++(k[1]), s);

			line(file[3], ++(k[3]), s);
			line(file[3], ++(k[3]), s);

			line(file[2], ++(k[2]), s);
			line(file[2], ++(k[2]), s);

			line(file[1], ++(k[1]), s);
			line(file[1], ++(k[1]), s);
			line(file[1], ++(k[1]), s);
			line(file[1], ++(k[1]), s);
			line(file[1], ++(k[1]), s);
			line(file[1], ++(k[1]), s);
			line(file[1], ++(k[1]), s);
		}
		i = 0;
		while (++i < ac)
			close(file[i]);
	}
	return (0);
}
