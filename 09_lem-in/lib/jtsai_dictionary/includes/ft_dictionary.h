/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionry.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 11:51:05 by jtsai             #+#    #+#             */
/*   Updated: 2018/10/25 16:56:02 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICTIONARY_H
# define FT_DICTIONARY_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define DICT_SIZE 1000

typedef struct			s_dict_list
{
	char				*key;
	void				*data;
	struct s_dict_list	*next;
}						t_dict_list;

typedef struct			s_ft_dict
{
	t_dict_list			**element;
}						t_ft_dict;

int						hash_function(char *key);
t_ft_dict				*dict_new();
void					dict_add(t_ft_dict *dict, char *key, void *data);

int						dict_str_compare(char *s1, char *s2);
void					*dict_get(t_ft_dict *dict, char *key);
void					*dict_element(t_ft_dict *dict, char *key);
void					dict_remove(t_ft_dict *dict, char *key);
void					dict_free(t_ft_dict *dict);

#endif
