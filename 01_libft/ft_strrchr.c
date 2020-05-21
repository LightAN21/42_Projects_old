/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 19:44:09 by jtsai             #+#    #+#             */
/*   Updated: 2018/07/12 20:23:45 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*x;
	int		len;
	int		i;

	x = (char *)s;
	len = ft_strlen(s);
	if (len == 0 && c == 0)
		return (x);
	i = 0;
	while (x[len - i] != (char)c)
	{
		if (i == len)
			return (NULL);
		i++;
	}
	return (x + len - i);
}
