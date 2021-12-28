# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 10:17:22 by csouza-f          #+#    #+#              #
#    Updated: 2021/12/27 21:43:55 by csouza-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SOURCES = ./
SOURCES_FILES = $(wildcard $(SOURCES)/*.c)
OBJECTS = ./objects
OBJECTS_FILES = $(patsubst $(SOURCES)/%.c,$(OBJECTS)/%.o,$(SOURCES_FILES))
INCLUDE = ./include

PTHREAD = -pthread
CCFLAGS = -Wall -Wextra -g
SANITIZE = -fsanitize=address

all: $(NAME)

$(NAME): $(OBJECTS_FILES)
	gcc $(PTHREAD) $< -o $@
#	gcc $(SANITIZE) $< -o $@

$(OBJECTS)/%.o: $(SOURCES_FILES)
	gcc $(CCFLAGS) $(PTHREAD) -c -I $(INCLUDE) $< -o $@

clean:
	rm $(OBJECTS)/*.o

fclean: clean
	rm $(NAME)

re: clean fclean all
