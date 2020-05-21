/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 11:00:47 by jtsai             #+#    #+#             */
/*   Updated: 2018/07/26 14:41:36 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	make_str(int size, char *filepath)
{
	int		file;
	char	*str;

	file = open(filepath, O_RDONLY);
	if (file == -1)
		return (0);
	if ((str = (char *)malloc(sizeof(char) * size + 1)) == 0)
	{
		close(file);
		return (0);
	}
	size = read(file, str, size + 1);
	if (size == -1)
		return (0);
	str[size] = '\0';
	if (!(ft_fillit(str, size)))
		return (0);
	free(str);
	if (close(file) == -1)
		return (0);
	return (1);
}

int	readfile(char *filepath)
{
	int		file;
	int		size;
	int		tmp;
	char	c;

	file = open(filepath, O_RDONLY);
	if (file == -1)
		return (0);
	size = 0;
	while ((tmp = read(file, &c, 1)))
	{
		if (tmp == -1)
			return (0);
		size++;
	}
	if (size < 20)
		return (0);
	if (close(file) == -1)
		return (0);
	if (make_str(size, filepath) == 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		return (0);
	}
	if (readfile(argv[1]) == 0)
		write(1, "error\n", 6);
	return (0);
}
