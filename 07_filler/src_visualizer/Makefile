# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtsai <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/27 10:15:17 by jtsai             #+#    #+#              #
#    Updated: 2018/10/06 08:39:43 by jtsai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visualizer

FLAGS = -Wall -Wextra -Werror

FILES = main.c get_next_line.c read_info.c draw.c

O_FILES = $(FILES:.c=.o)


LIB = ../lib/libft/libft.a ../lib/ft_printf/libftprintf.a
MLX = -L../lib/minilibx/ -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(FILES)
	gcc -o $(NAME) $(O_FILES) $(LIB) $(MLX)

clean:
	/bin/rm -f $(O_FILES)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
