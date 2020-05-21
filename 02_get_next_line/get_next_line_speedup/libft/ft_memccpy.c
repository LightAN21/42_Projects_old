/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 09:13:45 by jtsai             #+#    #+#             */
/*   Updated: 2018/07/13 14:30:31 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst,
		const void *restrict src, int c, size_t n)
{
	char	*d;
	char	*s;
	char	x;
	size_t	i;

	d = (char *)dst;
	s = (char *)src;
	x = (unsigned char)c;
	i = -1;
	while (++i < n)
	{
		d[i] = s[i];
		if (s[i] == x)
			return (dst + i + 1);
	}
	return (NULL);
}
