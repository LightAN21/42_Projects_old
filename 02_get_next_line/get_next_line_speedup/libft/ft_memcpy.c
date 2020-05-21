/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 07:31:23 by jtsai             #+#    #+#             */
/*   Updated: 2018/07/13 14:30:14 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*s;
	char	*x;
	size_t	i;

	s = (char *)dst;
	x = (char *)src;
	i = -1;
	while (++i < n)
		s[i] = x[i];
	return (dst);
}
