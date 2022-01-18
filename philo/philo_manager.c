/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 21:20:10 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/17 23:58:02 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_forks_release_all(struct s_philosopher *philo)
{
	while (philo)
	{
		pthread_mutex_unlock(philo->fork_left->lock);
		philo = philo->next;
	}
}

static int	didnt_eat_on_time(struct s_philosopher *philo)
{
	miliseconds_t	time_to_die;

	time_to_die = philo->table->args->time_to_die;
	if ((ft_gettimeofday() - philo->last_meal) >= time_to_die)
		if (philo->state != EATING)
			return (1);
	return (0);
}

#define LOOP_DELAY_USEC 5

void	*run_didnt_eat_on_time(void *arg)
{
	struct s_philosopher	*philo;
	struct s_table			*table;

	table = (struct s_table *)arg;
	philo = table->philo;
	while (table->state == RUNNING)
	{
		usleep(LOOP_DELAY_USEC);
		if (didnt_eat_on_time(philo))
		{
			philo_perform_action(DEAD, philo);
			table->state = NOT_RUNNING;
			philo_forks_release_all(table->philo);
			break ;
		}
		if (philo->next)
			philo = philo->next;
		else
			philo = table->philo;
	}
	return (NULL);
}

static int	ate_more_than_enough(struct s_table *table)
{
	struct s_philosopher	*philo;
	size_t					i;
	size_t					j;

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

void	*run_ate_more_than_enough(void *arg)
{
	struct s_table	*table;

	table = (struct s_table *)arg;
	if (!table->args->nbr_of_times_each_philo_must_eat)
		return (NULL);
	while (table->state == RUNNING)
	{
		usleep(LOOP_DELAY_USEC);
		if (ate_more_than_enough(table))
		{
			table->state = NOT_RUNNING;
			philo_forks_release_all(table->philo);
			break ;
		}
	}
	return (NULL);
}

void	*manager(void *arg)
{
	pthread_t	first;
	pthread_t	second;

	pthread_create(&first, NULL, &run_didnt_eat_on_time, arg);
	pthread_create(&second, NULL, &run_ate_more_than_enough, arg);
	pthread_join(first, NULL);
	pthread_join(second, NULL);
	return (NULL);
}

void	philo_tablenew_manager(struct s_table *table)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, &manager, table);
	table->thread = thread;
}
