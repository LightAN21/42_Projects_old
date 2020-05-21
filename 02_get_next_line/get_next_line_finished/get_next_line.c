/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 10:19:32 by jtsai             #+#    #+#             */
/*   Updated: 2018/07/30 15:07:35 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*new_file(int const fd, t_list **files)
{
	t_list	*t;
	t_list	*w;

	t = ft_lstnew(NULL, fd);
	if (t == NULL)
		return (NULL);
	t->content_size = fd;
	if (*files != NULL)
	{
		w = *files;
		while (w->next)
			w = w->next;
		w->next = t;
	}
	else
		*files = t;
	return (t);
}

t_list	*which_file(int const fd, t_list **files)
{
	t_list	*t;

	t = *files;
	while (t)
	{
		if ((int)t->content_size == fd)
			return (t);
		t = t->next;
	}
	return (new_file(fd, files));
}

int		read_file(int fd, t_list *now, int n, int m)
{
	int		k;
	char	buff[BUFF_SIZE + 1];
	char	*t;

	if ((t = ft_strstr(now->content + n, "\n")) != NULL)
		return ((int)(t - (char *)now->content) / sizeof(char));
	if ((k = read(fd, buff, BUFF_SIZE)) < 0)
		return (-2);
	else if (k == 0 && now->content == NULL)
		return (-1);
	else if (k == 0 && *((char *)now->content) == '\0')
		return (-1);
	else if (k == 0)
		return (n + m);
	buff[k] = '\0';
	if (now->content == NULL)
		now->content = ft_strnew(1);
	if (now->content == NULL)
		return (-2);
	if (!(t = ft_strjoin(now->content, buff)))
		return (-2);
	free(now->content);
	now->content = t;
	return (read_file(fd, now, n + m, k));
}

int		get_next_line(const int fd, char **line)
{
	int				n;
	int				len;
	char			*t;
	static t_list	*file;
	t_list			*now;

	if (fd < 0 || line == NULL)
		return (-1);
	now = which_file(fd, &file);
	n = read_file(fd, now, 0, 0);
	if (n < 0)
		return (n + 1);
	t = (char *)now->content;
	len = ft_strlen(t);
	if (!(*line = ft_strsub(t, 0, (t[n] == '\n') ? n : len)))
		return (-1);
	if ((n > 0 && t[n] == '\n') || (t[0] == '\n' && len > 1))
		now->content = ft_strsub((char *)t, n + 1, len - n - 1);
	else
		now->content = ft_strnew(0);
	if (now->content == NULL)
		return (-1);
	free(t);
	return (1);
}
