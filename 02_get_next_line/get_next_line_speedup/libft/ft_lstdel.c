/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:10:44 by jtsai             #+#    #+#             */
/*   Updated: 2018/07/17 15:26:12 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*t;

	if (del && alst)
	{
		while (*alst)
		{
			t = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = t;
		}
	}
}
