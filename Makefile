# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 10:17:22 by csouza-f          #+#    #+#              #
#    Updated: 2021/12/28 18:58:54 by csouza-f         ###   ########.fr        #
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
	gcc $(PTHREAD) $^ -o $@

$(OBJECTS)/%.o: $(SOURCES)/%.c
	gcc $(CCFLAGS) $(PTHREAD) -c -I $(INCLUDE) $< -o $@

clean:
	rm $(OBJECTS_FILES)

fclean: clean
	rm $(NAME)

re: fclean all
