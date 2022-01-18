/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_manager_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:26:33 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/18 20:33:58 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	didnt_eat_on_time(struct s_philosopher *philo)
{
	t_miliseconds	time_to_die;

	time_to_die = philo->table->args->time_to_die;
	if ((ft_gettimeofday() - philo->last_meal) >= time_to_die)
		if (philo->state != EATING)
			return (1);
	return (0);
}

int	ate_more_than_enough(struct s_table *table)
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
