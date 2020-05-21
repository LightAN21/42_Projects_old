/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 11:03:46 by jtsai             #+#    #+#             */
/*   Updated: 2018/07/26 12:49:42 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>

typedef struct	s_trim
{
	int			id;
	int			po[4];
}				t_trim;

typedef struct	s_sqr
{
	int			len;
	int			size;
	char		*square;
	int			num;
}				t_sqr;

int				ft_fillit(char *s, int size);
int				checkvalid(char *s);
int				find_square(t_trim *t, int num);
void			initialize(char *s, int len);
int				check_trimino(t_sqr *q, t_trim t, int p);
void			put_trimino(t_sqr *q, t_trim t, int p);
void			erase_trimino(t_sqr *q, t_trim t, int p);

#endif
