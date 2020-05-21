/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 18:18:15 by jtsai             #+#    #+#             */
/*   Updated: 2018/07/31 16:03:23 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include "libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define BUFF_SIZE 500

int					get_next_line(const int fd, char **line);

#endif
