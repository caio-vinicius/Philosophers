/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 10:15:27 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/30 11:00:25 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*simulation(void *philosopher)
{
	struct s_philosopher *philo;
	//size_t last_meal;

	philo = (struct s_philosopher*)philosopher;
	pthread_mutex_lock(philo->table->lock);
	// eating
	perform_action(FORK, philo);
	perform_action(EATING, philo);
	ft_msleep(philo->table->args->time_to_eat);
	// sleeping
	perform_action(SLEEPING, philo);
	ft_msleep(philo->table->args->time_to_sleep);
	// thinking
	perform_action(THINKING, philo);
	// died
	perform_action(0, philo);
	pthread_mutex_unlock(philo->table->lock);
	return (NULL);
}

int philosophers(int argc, char **argv)
{
	struct s_args *args;

	if (!*++argv)
	{
		usage();
		return (EXIT_FAILURE);
	}
	args = parsing(argc, argv);
	if (!args)
	{
		error("The arguments are incorrect in some way.");
		return (EXIT_FAILURE);
	}

	struct s_table *table;

	table = philo_tablenew(args);
	//pthread_mutex_unlock(table->lock);
	while (table->philo)
	{
		pthread_join(table->philo->thread, NULL);
		table->philo = table->philo->next;
	}
	free(args);
	return (EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	if (!philosophers(argc, argv))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
