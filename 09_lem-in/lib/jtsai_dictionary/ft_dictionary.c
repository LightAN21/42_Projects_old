/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 12:41:21 by jtsai             #+#    #+#             */
/*   Updated: 2018/11/06 20:54:35 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dictionary.h"

int			dict_hash_function(char *key)
{
	int	i;
	int	sum;

	sum = 0;
	i = -1;
	while (key[++i])
		sum += (int)key[i] * HASH_NUM + i;
	return (sum % DICT_SIZE);
}

t_ft_dict	*dict_new(void)
{
	int			i;
	t_ft_dict	*d;

	d = (t_ft_dict *)malloc(sizeof(t_ft_dict));
	if (!d)
		return (NULL);
	d->element = (t_dict_list **)malloc((DICT_SIZE + 1) * \
			sizeof(t_dict_list *));
	if (!d->element)
	{
		free(d);
		return (NULL);
	}
	i = -1;
	while (++i <= DICT_SIZE)
		d->element[i] = NULL;
	return (d);
}

void		dict_add(t_ft_dict *dict, char *key, void *data)
{
	t_dict_list *new;
	int			hash;
	int			len;
	int			i;

	if (!dict || !key)
		return ;
	new = dict_get(dict, key);
	if (new)
		return ;
	new = (t_dict_list *)malloc(sizeof(t_dict_list));
	len = 0;
	while (key[len])
		len++;
	new->key = (char *)malloc((len + 1) * sizeof(char));
	i = -1;
	while (++i < len)
		new->key[i] = key[i];
	new->key[i] = '\0';
	new->data = data;
	new->mark = 0;
	hash = dict_hash_function(key);
	new->next = dict->element[hash];
	dict->element[hash] = new;
}

void		dict_free(t_ft_dict *dict)
{
	int			i;
	t_dict_list *tmp;
	t_dict_list *tmp_2;

	i = -1;
	while (++i <= DICT_SIZE)
	{
		tmp = dict->element[i];
		while (tmp)
		{
			tmp_2 = tmp->next;
			free(tmp->key);
			free(tmp);
			tmp = tmp_2;
		}
	}
	free(dict->element);
	free(dict);
}
