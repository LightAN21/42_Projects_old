/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:09:42 by jtsai             #+#    #+#             */
/*   Updated: 2019/10/15 15:24:29 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	illegal_option(char c)
{
	ft_printf("ls: illegal option -- %c\n", c);
	ft_printf("usage: ls [-Ralrt] [file ...]\n");
	return (0);
}

int	permission_denied(char *s)
{
	int		i;
	char	*r;

	r = s;
	i = ft_strlen(r) - 1;
	while (i >= 0 && r[i] != '/')
		i--;
	ft_printf("ft_ls: %s: Permission denied\n", r + 1);
	return (0);
}
