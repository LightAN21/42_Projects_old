/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 09:33:01 by jtsai             #+#    #+#             */
/*   Updated: 2019/10/15 01:43:50 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*x;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	x = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (x == NULL)
		return (NULL);
	x = ft_strcpy(x, s1);
	x = ft_strcat(x, s2);
	return (x);
}

char	*ft_strjoin_c(char const *s1, char const *s2, char c)
{
	int		i;
	int		j;
	char	*x;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (char *)s2;
	x = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (x == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		x[i] = s1[i];
	x[i++] = c;
	j = -1;
	while (s2[++j])
		x[i + j] = s2[j];
	x[i + j] = 0;
	return (x);
}
