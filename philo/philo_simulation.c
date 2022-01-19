/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:11:12 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/18 22:07:37 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_eat(struct s_philosopher *philo);
int	philo_sleep(struct s_philosopher *philo);
int	philo_think(struct s_philosopher *philo);

void	*philo_simulation(void *arg)
{
	struct s_philosopher	*philo;

	philo = (struct s_philosopher *)arg;
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
