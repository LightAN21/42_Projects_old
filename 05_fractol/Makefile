# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtsai <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/02 12:28:25 by jtsai             #+#    #+#              #
#    Updated: 2019/11/07 13:54:51 by jtsai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -Wall -Wextra -Werror

FILES_0 = main.c hook.c julia.c mandelbort.c tricorn.c color.c try_1.c

FILES = $(addprefix src/, $(FILES_0))

OFILES = $(FILES_0:.c=.o)

MLX = -L./minilibx/ -lmlx -framework OpenGL -framework AppKit

LIBFT = -L./lib/libft -lft

all: $(NAME)

$(NAME):
	make -C ./lib/libft/
	gcc $(FLAGS) -I ./lib/libft/includes/ -c $(FILES)
	gcc -o $(NAME) $(OFILES) $(LIBFT) $(MLX)

test:
	make -C ./minilibx/
	gcc $(FLAGS) ./src/test.c $(MLX)

clean:
	/bin/rm -f $(OFILES)
	make -C ./lib/libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./lib/libft fclean

re: fclean all
