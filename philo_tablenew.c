/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tablenew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:08:35 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/16 14:19:30 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_tabledefine_actions(struct s_actions *actions)
{
	actions->messages[0] = "has taken a fork";
	actions->messages[1] = "is eating";
	actions->messages[2] = "is sleeping";
	actions->messages[3] = "is thinking";
	actions->messages[4] = "died";
}

struct s_table	*philo_tablenew(struct s_args *args)
{
	struct s_table *table;
	struct s_philosopher *philo;
	struct s_forks *forks;
	pthread_mutex_t *lock;

	table = malloc(sizeof(*table));
	lock = malloc(sizeof(*lock));
	pthread_mutex_init(lock, NULL);
	// for test purposes
	//pthread_mutex_lock(lock);
	// --
	philo_tabledefine_actions(&table->actions);
	table->lock = lock;
	table->args = args;
	table->state = RUNNING;
	table->start = ft_gettimeofday();
	forks = philo_lforksnew(args->number_of_philosophers);
	philo = philo_llstnew(&philo_simulation,
				forks,
				table,
				args->number_of_philosophers);
	table->philo = philo;
	return (table);
}
