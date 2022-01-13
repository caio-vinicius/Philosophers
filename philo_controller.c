/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 22:24:07 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/12 22:05:39 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*controller(void *arg)
{
	struct s_table *table;
	struct s_philosopher *philo;
	unsigned int toggle;
	
	table = (struct s_table*)arg;
	philo = table->philo;
	toggle = 0;
	printf("[CONTROLLER] Starting\n");
	while (philo) {
		if (philo->id % 2 == toggle)
		{
			if (philo->locked)
				philo_unlock(philo);
		}
		if (philo->next)
			philo = philo->next;
		else
		{
			philo = table->philo;
			//toggle = !toggle;
		}
	}
	return (NULL);
}

void	philo_tablenew_controller(struct s_table *table)
{
	pthread_t thread;

	pthread_create(&thread, NULL, &controller, table);
	table->thread = thread;
}
