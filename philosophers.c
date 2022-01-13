/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 10:15:27 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/12 21:48:05 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int philosophers(int argc, char **argv)
{
	struct s_args *args;
	struct s_table *table;
	struct s_philosopher *philo;
	
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
	table = philo_tablenew(args);
	//philo_lstdelone(&table->philo, table->philo);
	//pthread_mutex_unlock(table->lock);
	//ft_msleep(5);
	philo_tablenew_manager(table);
	philo_tablenew_controller(table);
	philo = table->philo;
	while (philo)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next;
	}
	pthread_join(table->thread, NULL);
	philo_tablefree(table);		
	return (EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	if (!philosophers(argc, argv))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
