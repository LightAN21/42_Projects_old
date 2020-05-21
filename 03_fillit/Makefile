# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtsai <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/19 19:06:00 by jtsai             #+#    #+#              #
#    Updated: 2018/07/23 17:01:26 by jtsai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

FILES = main.c checkvalid.c ft_fillit.c find_square.c \
		initialize.c check_trimino.c put_trimino.c erase_trimino.c
OFILES = $(FILES:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(FILES)
	@gcc $(OFILES) -o $(NAME)

clean:
	@/bin/rm -f $(OFILES)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
