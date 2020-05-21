/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 10:15:01 by jtsai             #+#    #+#             */
/*   Updated: 2018/07/13 14:31:19 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *)dst;
	s = (char *)src;
	i = -1;
	if (s >= d)
	{
		while (++i < len)
			d[i] = s[i];
	}
	else
	{
		while (len - (++i))
			d[len - i - 1] = s[len - i - 1];
	}
	return (dst);
}
