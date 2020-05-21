# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtsai <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/02 12:28:25 by jtsai             #+#    #+#              #
#    Updated: 2018/08/11 21:20:45 by jtsai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror

FILES = main.c get_next_line.c read_fdf.c fix_colors.c window_fdf.c \
		draw_fdf.c draw_fdf_w.c draw_line.c  colors.c messages.c

OFILES = $(FILES:.c=.o)

MLX = -L./minilibx/ -lmlx -framework OpenGL -framework AppKit

LIBFT = -L./libft -lft

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -g $(FLAGS) -I libft/includes/ -c $(FILES)
	gcc -g -o $(NAME) $(OFILES) $(LIBFT) $(MLX)

clean:
	/bin/rm -f $(OFILES)
	make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./libft fclean

re: fclean all
