/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:11:12 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/11 22:22:28 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_forkslock(struct s_forks *forks)
{
	pthread_mutex_lock(forks->lock);
	forks->locked = 1;
}

void	philo_forksunlock(struct s_forks *forks)
{
	pthread_mutex_unlock(forks->lock);
	forks->locked = 0;
}

void	philo_eat_forks_hold(struct s_philosopher *philo)
{
	philo_forkslock(philo->fork_left);
	philo_perform_action(FORK, philo);
	philo_forkslock(philo->fork_left->next);
	philo_perform_action(FORK, philo);
}

void	philo_eat_forks_release(struct s_philosopher *philo)
{
	philo_forksunlock(philo->fork_left);
	philo_forksunlock(philo->fork_left->next);
}

static void	philo_eat(struct s_philosopher *philo)
{
	philo_eat_forks_hold(philo);
	philo_perform_action(EATING, philo);
	ft_msleep(philo->table->args->time_to_eat);
	philo->last_meal = ft_gettimeofday();
	philo_eat_forks_release(philo);
	//philo_change_state(WAITING, philo);
}

static void	philo_sleep(struct s_philosopher *philo)
{
	philo_perform_action(SLEEPING, philo);
	ft_msleep(philo->table->args->time_to_sleep);
	//philo_change_state(WAITING, philo);
}

static void	philo_think(struct s_philosopher *philo)
{
	philo_perform_action(THINKING, philo);
}

void	*philo_simulation(void *arg)
{
	struct s_philosopher *philo;

	philo = (struct s_philosopher*)arg;
	//ft_msleep(5);
	philo->start = ft_gettimeofday();
	while (philo->state != DEAD)
	{
		philo_lock(philo);
		//printf("philo %ld %d\n", philo->id, philo->state);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		//pthread_mutex_unlock(philo->table->lock);
	}
	return (NULL);
}
