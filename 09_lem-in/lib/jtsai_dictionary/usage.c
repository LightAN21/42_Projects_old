/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 12:50:00 by jtsai             #+#    #+#             */
/*   Updated: 2018/11/06 20:54:39 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_dictionary.h"

int	main(void)
{
	t_ft_dict	*d;
	void		*tmp;

	d = dict_new();
	dict_add(d, "Apple", "13");
	dict_add(d, "Banana", "5");
	dict_add(d, "All", "18");
	tmp = dict_get(d, "Banana");
	printf("%s\n", (char *)tmp);
	printf("%s\n", (char *)dict_get(d, "Orange"));
	printf("%s\n", (char *)dict_get(d, "Apple"));
	printf("%s\n", (char *)dict_get(d, "All"));
	printf("\n");
	dict_remove(d, "Banana");
	printf("%s\n", (char *)dict_get(d, "Apple"));
	printf("%s\n", (char *)dict_get(d, "Banana"));
	printf("%s\n", (char *)dict_get(d, "All"));
	printf("\n");
	dict_remove(d, "All");
	printf("%s\n", (char *)dict_get(d, "Apple"));
	printf("%s\n", (char *)dict_get(d, "Banana"));
	printf("%s\n", (char *)dict_get(d, "All"));
	dict_free(d);
	return (0);
}
