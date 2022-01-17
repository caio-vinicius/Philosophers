/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:11:12 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/16 20:56:20 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	philo_eat_forks_hold(struct s_philosopher *philo)
{
	pthread_mutex_lock(philo->fork_left->lock);
	if (!philo_perform_action(FORK, philo))
		return (0);
	pthread_mutex_lock(philo->fork_left->next->lock);
	if (!philo_perform_action(FORK, philo))
		return (0);
	return (1);
}

static void	philo_eat_forks_release(struct s_philosopher *philo)
{
	pthread_mutex_unlock(philo->fork_left->lock);
	pthread_mutex_unlock(philo->fork_left->next->lock);
}

static int	philo_eat(struct s_philosopher *philo)
{
	philo_eat_forks_hold(philo);
	if (!philo_perform_action(EATING, philo))
		return (0);
	ft_msleep(philo->table->args->time_to_eat);
	philo->last_meal = ft_gettimeofday();
	philo->nbr_of_times_eaten = philo->nbr_of_times_eaten + 1;
	philo_eat_forks_release(philo);
	return (1);
}

static int	philo_sleep(struct s_philosopher *philo)
{
	if (!philo_perform_action(SLEEPING, philo))
		return (0);
	ft_msleep(philo->table->args->time_to_sleep);
	return (1);
}

static int	philo_think(struct s_philosopher *philo)
{
	if (!philo_perform_action(THINKING, philo))
		return (0);
	return (1);
}

void	*philo_simulation(void *arg)
{
	struct s_philosopher *philo;

	philo = (struct s_philosopher*)arg;
	ft_msleep(philo->delay);
	while (philo->table->state == RUNNING)
	{
		if (!philo_eat(philo))
			break ;
		if (!philo_sleep(philo))
			break ; 
		if (!philo_think(philo))
			break ;
	}
	return (NULL);
}
