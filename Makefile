# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 10:17:22 by csouza-f          #+#    #+#              #
#    Updated: 2021/12/26 10:51:05 by csouza-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SOURCES = ./
OBJECTS = ./objects
INCLUDE = ./include

CCFLAGS = -Wall -Wextra -Werror
SANITIZE = -fsanitize=address

all: $(NAME)

$(NAME): ./objects/main.o
	gcc $(SANITIZE) $< -o $@

$(OBJECTS)/%.o: $(SOURCES)/%.c
	gcc $(CCFLAGS) -c -I $(INCLUDE) $< -o $@

clean:
	rm $(OBJECTS)/*.o

fclean: clean
	rm $(NAME)

re: clean fclean all
