/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_cmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 00:33:00 by jtsai             #+#    #+#             */
/*   Updated: 2019/10/15 02:02:19 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	cmp_data_alpha(t_ls_data a, t_ls_data b)
{
	return (ft_strcmp(a.name, b.name));
}

int	cmp_data_alpha_reverse(t_ls_data a, t_ls_data b)
{
	return (-1 * ft_strcmp(a.name, b.name));
}

int	cmp_data_time(t_ls_data a, t_ls_data b)
{
	long	ta;
	long	tb;
	long	na;
	long	nb;

	ta = a.data.st_mtimespec.tv_sec;
	tb = b.data.st_mtimespec.tv_sec;
	na = a.data.st_mtimespec.tv_nsec;
	nb = b.data.st_mtimespec.tv_nsec;
	if (ta != tb)
		return (tb - ta);
	if (na != nb)
		return (nb - na);
	return (cmp_data_alpha(a, b));
}

int	cmp_data_time_reverse(t_ls_data a, t_ls_data b)
{
	long	ta;
	long	tb;
	long	na;
	long	nb;

	ta = a.data.st_mtimespec.tv_sec;
	tb = b.data.st_mtimespec.tv_sec;
	na = a.data.st_mtimespec.tv_nsec;
	nb = b.data.st_mtimespec.tv_nsec;
	if (ta != tb)
		return (ta - tb);
	if (na != nb)
		return (na - nb);
	return (cmp_data_alpha_reverse(a, b));
}
