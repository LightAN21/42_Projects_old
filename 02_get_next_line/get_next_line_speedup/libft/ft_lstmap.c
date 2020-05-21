/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:47:44 by jtsai             #+#    #+#             */
/*   Updated: 2018/07/17 16:49:58 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ans;
	t_list	*t;

	if (lst == NULL)
		return (NULL);
	ans = f(lst);
	t = ans;
	while (lst->next)
	{
		lst = lst->next;
		ans->next = f(lst);
		ans = ans->next;
	}
	ans->next = NULL;
	return (t);
}
