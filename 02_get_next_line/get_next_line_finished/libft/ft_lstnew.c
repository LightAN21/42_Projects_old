/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 13:35:44 by jtsai             #+#    #+#             */
/*   Updated: 2018/07/17 16:52:18 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*t;

	if (!(t = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		t->content = NULL;
		t->content_size = 0;
	}
	else
	{
		if (!(t->content = (void *)malloc(content_size + 1)))
			return (NULL);
		ft_memcpy(t->content, content, content_size);
		t->content_size = content_size;
	}
	t->next = NULL;
	return (t);
}
