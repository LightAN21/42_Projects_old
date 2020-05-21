/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 10:19:42 by jtsai             #+#    #+#             */
/*   Updated: 2018/07/16 11:28:34 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*x;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	if (*s == '\0')
		return ((char *)s);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = ft_strlen(s) - 1;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j >= 0)
		j--;
	if (j < 0)
		return (ft_strnew(1));
	x = ft_strsub(s, (unsigned int)i, (size_t)(j - i + 1));
	return (x);
}
