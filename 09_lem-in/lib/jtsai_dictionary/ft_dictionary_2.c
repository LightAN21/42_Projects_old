/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:05:28 by jtsai             #+#    #+#             */
/*   Updated: 2018/10/29 08:51:29 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dictionary.h"

int			dict_str_compare(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] || s2[i])
		return (0);
	return (1);
}

void		*dict_get(t_ft_dict *dict, char *key)
{
	t_dict_list *tmp;

	if (!dict || !key)
		return (NULL);
	tmp = dict->element[dict_hash_function(key)];
	while (tmp)
	{
		if (dict_str_compare(key, tmp->key) == 0)
			tmp = tmp->next;
		else
			return (tmp->data);
	}
	return (NULL);
}

void		*dict_element(t_ft_dict *dict, char *key)
{
	t_dict_list *tmp;

	if (!dict || !key)
		return (NULL);
	tmp = dict->element[dict_hash_function(key)];
	while (tmp)
	{
		if (dict_str_compare(key, tmp->key) == 0)
			tmp = tmp->next;
		else
			return (tmp);
	}
	return (NULL);
}

void		dict_remove(t_ft_dict *dict, char *key)
{
	t_dict_list *tmp;
	t_dict_list *tmp_pre;

	if (!dict || !key)
		return ;
	tmp = dict->element[dict_hash_function(key)];
	tmp_pre = NULL;
	while (tmp)
	{
		if (dict_str_compare(key, tmp->key) == 0)
		{
			tmp_pre = tmp;
			tmp = tmp->next;
		}
		else
			break ;
	}
	if (!tmp)
		return ;
	if (!tmp_pre)
		dict->element[dict_hash_function(key)] = tmp->next;
	else
		tmp_pre->next = tmp->next;
	free(tmp->key);
	free(tmp);
}
