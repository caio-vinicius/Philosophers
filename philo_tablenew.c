/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tablenew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:08:35 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/30 10:56:23 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

struct s_table	*philo_tablenew(struct s_args *args)
{
	struct s_table *table;
	struct s_philosopher *philo;
	pthread_mutex_t *lock;
	
	table = malloc(sizeof(*table));
	lock = malloc(sizeof(*lock));
	pthread_mutex_init(lock, NULL);
	//pthread_mutex_lock(lock);
	table->lock = lock;
	table->args = args;
	table->forks = args->number_of_philosophers;
	philo = philo_llstnew(&simulation, table, args->number_of_philosophers);
	table->philo = philo;
	return (table);
}
