/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 15:59:11 by jtsai             #+#    #+#             */
/*   Updated: 2018/07/12 17:13:06 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst,
		const char *restrict src, size_t dstsize)
{
	size_t	ld;
	size_t	ls;
	size_t	i;

	ld = ft_strlen(dst);
	ls = ft_strlen(src);
	if (dstsize == 0 || ld > dstsize - 1)
		return (dstsize + ls);
	i = 0;
	while (i < dstsize - ld - 1)
	{
		dst[ld + i] = src[i];
		i++;
	}
	dst[ld + i] = '\0';
	return (ld + ls);
}
