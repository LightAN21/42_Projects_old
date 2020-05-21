/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 13:53:02 by jtsai             #+#    #+#             */
/*   Updated: 2018/07/16 21:56:12 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		len;
	int		sign;

	sign = (n < 0) ? -1 : 1;
	i = n;
	len = 0;
	while (i && ++len)
		i = i / 10;
	i = (n > 0) ? (len + 1) : (len + 2);
	if (!(s = (char *)malloc(i * sizeof(char))))
		return (NULL);
	s[--i] = '\0';
	while (--i)
	{
		s[i] = '0' + sign * (n % 10);
		n /= 10;
	}
	s[0] = (sign < 0) ? '-' : '0' + n;
	return (s);
}
