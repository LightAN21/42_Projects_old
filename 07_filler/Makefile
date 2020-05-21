# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtsai <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/18 18:32:31 by jtsai             #+#    #+#              #
#    Updated: 2018/10/05 10:48:49 by jtsai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = jtsai.filler

FLAGS = -Wall -Wextra -Werror

FILES_1_ = main.c get_next_line.c read_info.c prepare.c \
		   strategy.c find_answer.c

DIR_FILLER = src_filler/

FILES_1 = $(addprefix $(DIR_FILLER), $(FILES_1_))

O_FILES = $(FILES_1_:.c=.o)

LIB = lib/libft/libft.a lib/ft_printf/libftprintf.a
MLX = -L./lib/minilibx/ -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	@make -C lib/libft/
	gcc -c $(FLAGS) -I lib/libft -I lib/ft_printf/ $(FILES_1)
	gcc -o $(NAME) $(O_FILES) $(LIB)
	make -C src_visualizer/

clean:
	@make -C lib/libft/ clean
	/bin/rm -f $(O_FILES)
	make -C src_visualizer/ clean

fclean: clean
	@make -C lib/libft/ fclean
	/bin/rm -f $(NAME)
	make -C src_visualizer/ fclean

re: fclean all
