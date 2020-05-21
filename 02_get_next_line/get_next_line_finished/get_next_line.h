/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 18:18:15 by jtsai             #+#    #+#             */
/*   Updated: 2018/07/30 15:45:03 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/includes/libft.h"
# include <stdlib.h>
# include <string.h>

# define BUFF_SIZE 32

int					get_next_line(const int fd, char **line);

#endif
