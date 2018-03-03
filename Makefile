# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrown <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/01 21:05:55 by jbrown            #+#    #+#              #
#    Updated: 2018/03/01 22:32:42 by jbrown           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line
RM = /bin/rm -f

FUNCTS = get_next_line main
FLAGS = -Wall -Wextra -Werror

CFILES = $(patsubst %, %.c, $(FUNCTS))
OBJECTS = $(patsubst %, %.o, $(FUNCTS))

LIBDIR = ./libft
LIB = libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(LIBDIR)/$(LIB):
	@cd libft && make

$(OBJECTS):
	@gcc $(FLAGS) -c $(CFILES)

$(NAME): $(OBJECTS) $(LIBDIR)/$(LIB)
	@gcc $(FLAGS) $(OBJECTS) $(LIBDIR)/$(LIB) -o $(NAME)

clean:
	@$(RM) $(OBJECTS)
	@cd libft && make clean

fclean: clean
	@$(RM) $(NAME)
	@cd libft && make fclean

re: fclean all
