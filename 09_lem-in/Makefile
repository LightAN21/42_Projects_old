# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtsai <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/18 18:32:31 by jtsai             #+#    #+#              #
#    Updated: 2019/11/16 16:09:34 by jtsai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Wextra -Werror

FILES_1_ = lem_in.c get_arguments.c check_info.c tools.c \
			make_roomlist.c  sort_roomlist.c \
			find_flows_by_edmonds_karp.c find_flows_new_combiniation.c \
		    sort_flows.c print_flows.c print_info.c \
			find_solution.c move_ants.c

DIR_FILLER = src/

FILES_1 = $(addprefix $(DIR_FILLER), $(FILES_1_))

O_FILES = $(FILES_1_:.c=.o)

LIB = lib/libft/libft.a lib/ft_printf/libftprintf.a \
	  lib/jtsai_dictionary/ft_dictionary.a \
	  lib/jtsai_stack_queue/ft_stack_queue.a

all: $(NAME)

$(NAME):
	make -C lib/libft/
	make -C lib/jtsai_dictionary/
	make -C lib/jtsai_stack_queue/
	gcc -c $(FLAGS) -I lib/libft -I lib/ft_printf/ $(FILES_1)
	gcc -o $(NAME) $(O_FILES) $(LIB)

clean:
	make -C lib/libft/ clean
	make -C lib/jtsai_dictionary/ clean
	make -C lib/jtsai_stack_queue/ clean
	/bin/rm -f $(O_FILES)

fclean: clean
	make -C lib/libft/ fclean
	make -C lib/jtsai_dictionary/ fclean
	make -C lib/jtsai_stack_queue/ fclean
	/bin/rm -f $(NAME)

debug: fclean
	make -C lib/libft/
	make -C lib/jtsai_dictionary/
	make -C lib/jtsai_stack_queue/
	gcc -g src/*.c $(LIB)

re: fclean all
