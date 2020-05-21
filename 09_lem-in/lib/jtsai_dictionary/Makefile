# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtsai <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/25 17:27:07 by jtsai             #+#    #+#              #
#    Updated: 2018/10/29 08:39:12 by jtsai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_dictionary.a

CFILES = ft_dictionary.c ft_dictionary_2.c

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(CFILES) -I includes/
	@ar rc $(NAME) $(OFILES)
	@ranlib $(NAME)

usage:
	gcc -Wall -Wextra -Werror usage.c ft_dictionary.c ft_dictionary_2.c

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all
