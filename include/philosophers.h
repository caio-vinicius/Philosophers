/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 10:16:18 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/11 23:20:15 by csouza-f         ###   ########.fr       */
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

# define AMOUNT_ACTIONS 5

# define FORK 0
# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define DEAD 4

# define WAITING 5
# define NOT_STARTED 6
# define RUNNING 7

typedef size_t miliseconds_t; 

struct s_args {
	unsigned int number_of_philosophers;
	miliseconds_t time_to_die;
	miliseconds_t time_to_eat;
	miliseconds_t time_to_sleep;
	unsigned int number_of_times_each_philosopher_must_eat;
};

struct s_actions {
	const char *messages[AMOUNT_ACTIONS];
};

struct s_forks {
	pthread_mutex_t *lock;
	unsigned int locked;
	struct s_forks *next;
	struct s_forks *previous;
};

struct s_philosopher {
	size_t id;
	unsigned int state;
	miliseconds_t start;
	miliseconds_t last_meal;
   	pthread_t thread;
	pthread_mutex_t *lock;
	unsigned int locked;
	struct s_table *table;
	struct s_forks *fork_left;
	struct s_philosopher *next;
	struct s_philosopher *previous;
};

struct s_table {
	struct s_philosopher *philo;
	struct s_args *args;
	miliseconds_t start;
   	pthread_t thread;
	pthread_mutex_t *lock;
	struct s_actions actions;
};

// PHILO LIST

struct s_philosopher	*philo_llstnew(
	void *(*f)(void*),
	struct s_forks *forks,
	struct s_table *table,
	size_t amount);
struct s_forks		*philo_lforksnew(size_t amount);
void			philo_lstfree(struct s_philosopher *philo);
//void	philo_lstadd_back(struct s_philosopher **philo, struct s_philosopher *new);
//struct s_philosopher *philo_lstlast(struct s_philosopher *philo);
//struct s_philosopher	*philo_lstnew(
//	void *(*f)(void*),
//	struct s_table *table,
//	unsigned int id);

// PHILO FORKS

void	philo_forksfree(struct s_forks *forks);

// PHILO PARSING

struct s_args 	*parsing(int argc, char **argv);
void		usage(void);
void		error(char *str);

// PHILO ?

void		*philo_simulation(void *arg);
struct s_table	*philo_tablenew(struct s_args *args);
void		philo_tablefree(struct s_table *table);
void		philo_tablenew_manager(struct s_table *table);

void		philo_tablenew_controller(struct s_table *table);

void		philo_lock(struct s_philosopher *philo);
void		philo_unlock(struct s_philosopher *philo);

void	philo_perform_action(unsigned int action, struct s_philosopher *philo);

// PHILO TIME


miliseconds_t	ft_gettimeofday_relative(miliseconds_t start);
miliseconds_t	ft_gettimeofday(void);
size_t		sec_to_usec(size_t seconds);
miliseconds_t	sec_to_milisec(unsigned int seconds);
unsigned int	milisec_to_usec(unsigned int miliseconds);
miliseconds_t	usec_to_milisec(unsigned int usec);
void		ft_sleep(unsigned int seconds);
void		ft_msleep(unsigned int miliseconds);

void		philo_lstdelone(struct s_philosopher **philos,
				struct s_philosopher *philo);

#endif
