# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 10:17:22 by csouza-f          #+#    #+#              #
#    Updated: 2022/01/19 00:24:31 by csouza-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SOURCES = ./philo
SOURCES_FILES = philo_forksfree.c philo_lstfree.c philo_parsing.c \
		philo_perform_action.c philosophers.c philo_time_utils.c \
		philo_lforksnew.c philo_manager.c philo_parsing_utils.c \
		philo_simulation.c philo_tablefree.c philo_time_utils_utils.c \
		philo_llstnew.c philo_manager_utils.c \
		philo_parsing_utils_utils.c philo_simulation_utils.c \
		philo_tablenew.c
SOURCES_FILES_FULL = $(addprefix $(SOURCES)/,$(SOURCES_FILES))
OBJECTS = ./objects
OBJECTS_FILES = $(patsubst $(SOURCES)/%.c,$(OBJECTS)/%.o,$(SOURCES_FILES_FULL))
INCLUDE = ./include

PTHREAD = -pthread
CCFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS_FILES)
	gcc $(PTHREAD) $^ -o $(SOURCES)/$@

$(OBJECTS)/%.o: $(SOURCES)/%.c
	gcc $(CCFLAGS) -c -I $(INCLUDE) $< -o $@

clean:
	rm -f $(OBJECTS_FILES)

fclean: clean
	rm -f $(SOURCES)/$(NAME)

re: fclean all
