/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 10:16:18 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/18 20:55:42 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include <pthread.h>
# include <sys/time.h>

# define LOOP_DELAY_USEC 5
# define TOTAL_AMOUNT_ARGUMENTS 5
# define AMOUNT_ACTIONS 5

# define FORK 0
# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define DEAD 4

# define NOT_RUNNING 5
# define RUNNING 6

typedef size_t	t_miliseconds;

struct s_args {
	unsigned int	number_of_philosophers;
	t_miliseconds	time_to_die;
	t_miliseconds	time_to_eat;
	t_miliseconds	time_to_sleep;
	unsigned int	nbr_of_times_each_philo_must_eat;
};

struct s_forks {
	pthread_mutex_t	*lock;
	struct s_forks	*next;
	struct s_forks	*previous;
};

struct s_philosopher {
	struct s_philosopher	*next;
	struct s_philosopher	*previous;
	size_t					id;
	pthread_t				thread;
	unsigned int			state;
	t_miliseconds			last_meal;
	t_miliseconds			delay;
	unsigned int			nbr_of_times_eaten;
	struct s_table			*table;
	struct s_forks			*fork_left;
};

struct s_table {
	struct s_philosopher	*philo;
	struct s_args			*args;
	t_miliseconds			start;
	unsigned int			state;
	pthread_t				thread;
	const char				*actions[AMOUNT_ACTIONS];
};

t_miliseconds	ft_gettimeofday(void);
void			philo_lstfree(struct s_philosopher *philo);
void			philo_forksfree(struct s_forks *forks,
					unsigned int amount);
void			ft_msleep(t_miliseconds ms);
int				philo_perform_action(unsigned int action,
					struct s_philosopher *philo);

#endif
