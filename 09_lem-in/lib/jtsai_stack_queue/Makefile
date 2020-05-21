# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtsai <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/25 17:27:07 by jtsai             #+#    #+#              #
#    Updated: 2018/10/29 11:17:15 by jtsai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_stack_queue.a

CFILES = ft_stack.c ft_queue.c

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(CFILES)
	@ar rc $(NAME) $(OFILES)
	@ranlib $(NAME)

usage:
	gcc -Wall -Wextra -Werror usage.c ft_stack.c ft_queue.c

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all
