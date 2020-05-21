# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtsai <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 16:32:06 by jtsai             #+#    #+#              #
#    Updated: 2019/10/15 01:32:31 by jtsai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

FLAGS = -Wall -Wextra -Werror

FILES_0 = main.c messages.c string_sort.c ls_init.c\
		ls_first_step.c ls.c ls_sprint.c ls_sprint_2.c data_cmp.c

FILES_LS = $(addprefix src_ft_ls/, $(FILES_0))

O_FILES = $(FILES_0:.c=.o)

LIB = lib/libft/libft.a lib/ft_printf/libftprintf.a

HEADER = -I lib/libft/ -I lib/ft_printf/

all: $(NAME)

$(NAME):
	make -C lib/libft/
	make -C lib/ft_printf/
	gcc -c $(FLAGS) $(HEADER) $(FILES_LS)
	gcc -o $(NAME) $(O_FILES) $(LIB)

clean:
	make -C lib/libft/ clean
	make -C lib/ft_printf/ clean
	/bin/rm -f $(O_FILES)

fclean: clean
	make -C lib/libft/ fclean
	make -C lib/ft_printf/ fclean
	/bin/rm -f $(NAME)

re: fclean all
