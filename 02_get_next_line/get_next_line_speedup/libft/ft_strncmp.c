/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 03:38:36 by jtsai             #+#    #+#             */
/*   Updated: 2018/07/13 13:57:56 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*a;
	char	*b;
	size_t	i;

	a = (char *)s1;
	b = (char *)s2;
	i = 0;
	while (i < n && a[i] != '\0' && b[i] != '\0')
	{
		if (a[i] != b[i])
			return ((unsigned char)a[i] - (unsigned char)b[i]);
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)a[i] - (unsigned char)b[i]);
}
