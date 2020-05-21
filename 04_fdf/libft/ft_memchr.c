/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 23:34:03 by jtsai             #+#    #+#             */
/*   Updated: 2018/07/13 14:31:34 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*x;

	x = (unsigned char *)s;
	i = -1;
	while (++i < n)
	{
		if (x[i] == (unsigned char)c)
			return ((void *)(x + i));
	}
	return (NULL);
}
