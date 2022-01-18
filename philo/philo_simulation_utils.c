/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:35:42 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/17 22:40:14 by csouza-f         ###   ########.fr       */
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

int	philo_eat(struct s_philosopher *philo)
{
	philo_eat_forks_hold(philo);
	if (!philo_perform_action(EATING, philo))
		return (0);
	philo->nbr_of_times_eaten = philo->nbr_of_times_eaten + 1;
	ft_msleep(philo->table->args->time_to_eat);
	philo->last_meal = ft_gettimeofday();
	philo_eat_forks_release(philo);
	return (1);
}

int	philo_sleep(struct s_philosopher *philo)
{
	if (!philo_perform_action(SLEEPING, philo))
		return (0);
	ft_msleep(philo->table->args->time_to_sleep);
	return (1);
}

int	philo_think(struct s_philosopher *philo)
{
	if (!philo_perform_action(THINKING, philo))
		return (0);
	return (1);
}
