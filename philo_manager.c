/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 21:20:10 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/16 20:58:35 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	didnt_eat_on_time(struct s_philosopher *philo)
{
	miliseconds_t time_to_die;

	time_to_die = philo->table->args->time_to_die;	
	
	if ((ft_gettimeofday() - philo->last_meal) >= time_to_die)
		if (philo->state != EATING)
			return (1);
	return (0);
}

static int	ate_more_than_enough(struct s_table *table)
{
	struct s_philosopher *philo;
	size_t i;
	size_t j;
	
	if (!table->args->nbr_of_times_each_philo_must_eat)
		return (0);
	philo = table->philo;
	i = 0;
	j = 0;
	while (philo)
	{
		if (philo->nbr_of_times_eaten >= \
			table->args->nbr_of_times_each_philo_must_eat)
			i++;
		j++;
		philo = philo->next;
	}
	if (i == j)
		return (1);
	return (0);
}

static void	philo_forks_release_all(struct s_philosopher *philo)
{
	while (philo)
	{
		pthread_mutex_unlock(philo->fork_left->lock);
		philo = philo->next;
	}
}

void	*manager(void *arg)
{
	struct s_philosopher *philo;
	struct s_table *table;

	//printf("[MANAGER] Starting\n");
	table = (struct s_table*)arg;
	philo = table->philo;
	while (1)
	{
		// maybe?
		// do not let processor burn
		usleep(10);
		if (didnt_eat_on_time(philo) || ate_more_than_enough(table))
		{
			philo_perform_action(DEAD, philo);
			philo->table->state = NOT_RUNNING;
			philo_forks_release_all(table->philo);
			break ;
		} 
		if (philo->next)
			philo = philo->next;
		else
			philo = table->philo;
	}
	//printf("[MANAGER] Finished\n");
	return (NULL);
}

void	philo_tablenew_manager(struct s_table *table)
{
	pthread_t thread;

	pthread_create(&thread, NULL, &manager, table);
	table->thread = thread;
}
