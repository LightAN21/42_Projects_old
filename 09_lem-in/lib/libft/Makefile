# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtsai <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/11 16:12:19 by jtsai             #+#    #+#              #
#    Updated: 2019/11/15 07:52:23 by jtsai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFILES = ft_atoi.c ft_strcat.c ft_strcpy.c ft_strjoin.c ft_strlen.c ft_itoa.c \
		 ft_strnew.c ft_strstr.c ft_strsub.c ft_strchr.c ft_strcmp.c \
		 ft_strsplit.c ft_letters.c ft_words.c ft_isnum.c ft_countchar.c \
		 get_next_line.c ft_memset.c

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(CFILES) -I includes/
	@ar rc $(NAME) $(OFILES)
	@ranlib $(NAME)

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all
