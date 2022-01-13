/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 21:20:10 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/12 21:33:02 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	all_dead(struct s_philosopher *philo)
{
	while (philo)
	{
		if (philo->state != DEAD)
			return (0);
		philo = philo->next;
	}
	return (1);
}

void	*manager(void *arg)
{
	struct s_philosopher *philo;
	struct s_table *table;
	miliseconds_t current;
	miliseconds_t start;
	
	printf("[MANAGER] Starting\n");
	table = (struct s_table*)arg;
	philo = table->philo;
	while (!all_dead(table->philo))
	{
		ft_msleep(1);
		//printf("===================== verifying philo %ld\n", philo->id);
		current = ft_gettimeofday();
		//printf("%ld | %ld\n", current, philo->last_meal);
		//printf("%ld | %ld\n", tv.tv_sec, sec_to_usec(tv.tv_sec));
		start = philo->start;
		if (philo->last_meal)
			start = philo->last_meal;
		if ((current - start) >= philo->table->args->time_to_die && philo->state != EATING)
		{
			if (philo->state != DEAD)
			{
				//printf("state: %d\n", philo->state);
				//printf("start: %ld last_meal: %ld\n", philo->start, philo->last_meal);
				//printf("%ld - %ld = %ld\n", current, start, current - start);
				philo_perform_action(DEAD, philo);
				philo_lstdelone(&table->philo, philo);
				pthread_detach(philo->thread);
			}
		}
		if (philo->next)
			philo = philo->next;
		else
			philo = table->philo;
	}
	return (NULL);
}

void	philo_tablenew_manager(struct s_table *table)
{
	pthread_t thread;

	pthread_create(&thread, NULL, &manager, table);
	table->thread = thread;
}
