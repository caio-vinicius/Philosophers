/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 10:16:18 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/30 11:01:51 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <pthread.h>
#include <sys/time.h>

// PHILOSOPHER POSSIBLE STATE

# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define WAITING 4
# define FORK 5

struct s_args {
	unsigned int number_of_philosophers;
	unsigned int time_to_die;
	unsigned int time_to_eat;
	unsigned int time_to_sleep;
	unsigned int number_of_times_each_philosopher_must_eat;
};

struct s_philosopher {
	unsigned int id;
	unsigned int state;
   	pthread_t thread;
	struct s_table *table;
	struct s_philosopher *next;
	struct s_philosopher *previous;
};

struct s_table {
	struct s_philosopher *philo;
	struct s_args *args;
	size_t forks;
	pthread_mutex_t *lock;
};

// PHILO LIST

struct s_philosopher	*philo_llstnew(
	void *(*f)(void*),
	struct s_table *table,
	size_t amount);
void	philo_lstfree(struct s_philosopher *philo);
void	philo_lstadd_back(struct s_philosopher **philo, struct s_philosopher *new);
struct s_philosopher *philo_lstlast(struct s_philosopher *philo);
struct s_philosopher	*philo_lstnew(
	void *(*f)(void*),
	struct s_table *table,
	unsigned int id);

// PHILO PARSING

struct s_args *parsing(int argc, char **argv);
void	usage(void);
void	error(char *str);

// PHILO ?

void	*simulation(void *arg);
struct s_table	*philo_tablenew(struct s_args *args);

// PHILO TIME


void	perform_action(unsigned int action, struct s_philosopher *philo);
size_t	get_current_relative_milisecond(void);
size_t	get_current_milisecond(void);
void	ft_msleep(unsigned int miliseconds);
void	ft_sleep(unsigned int seconds);
unsigned int usec_to_milisec(unsigned int usec);
unsigned int milisec_to_usec(unsigned int miliseconds);
unsigned int sec_to_usec(unsigned int seconds);

#endif
