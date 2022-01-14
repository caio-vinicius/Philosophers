/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 22:24:07 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/13 21:37:04 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//already defined in philo_llstnew.c
//using again
static struct s_philosopher *philo_lstlast(struct s_philosopher *philo)
{
	while (philo)
	{
		if (!philo->next)
			return (philo);
		philo = philo->next;
	}
	return (NULL);
}

size_t	philo_lstsize(struct s_philosopher *philo)
{
	size_t i;

	i = 0;
	while (philo)
	{
		i++;
		philo = philo->next;
	}
	return (i);
}

# define EVEN 0
# define ODD 1

struct s_philosophers *get_philos_by_parity(
	struct s_philosopher *philo,
	unsigned int parity)
{
	struct s_philosophers *selected;
	size_t i;
	//parity:
	//0 == odd
	//1 == even
	// number_of_philosophers in args struct
	selected = malloc(sizeof(*selected));
	i = philo_lstsize(philo);
	if (i % 2)
	{
		if (parity == ODD)
			selected->philos = malloc(sizeof(*selected->philos) * ((i / 2)));
		else if (parity == EVEN)
			selected->philos = malloc(sizeof(*selected->philos) * ((i / 2) + 1));
	}
	else
		selected->philos = malloc(sizeof(*selected->philos) * (i / 2));
	i = 0;
	while (philo)
	{
		if (philo->id % 2 == parity)
		{
			selected->philos[i] = philo;
			i++;
		}	 
		philo = philo->next;
	}
	selected->amount = i;
	return (selected);	
}

void	philo_unlock_selected(struct s_philosophers *selected)
{
	size_t i;

	i = 0;
	while (selected->amount > i)
	{
		philo_unlock(selected->philos[i]);
		i++;
	}
}

void	print_selected(struct s_philosophers *selected)
{
	size_t i;

	i = 0;
	printf("SELECTED: ");
	while (selected->amount > i)
	{
		printf("%ld ", selected->philos[i]->id);
		i++;
	}
	printf("\n");
}

void	*controller(void *arg)
{
	struct s_table *table;
	struct s_philosopher *philo;
	struct s_philosophers *selected_philo;
	unsigned int parity;
	
	table = (struct s_table*)arg;
	philo = table->philo;
	parity = 0;
	printf("[CONTROLLER] Starting\n");
	while (philo) {
		selected_philo = get_philos_by_parity(table->philo, parity);
		print_selected(selected_philo);
		philo_unlock_selected(selected_philo);
		ft_msleep(table->args->time_to_eat);
		parity = !parity;
		if (philo->next)
			philo = philo->next;
		else
		{
			philo = table->philo;
		}
	}
	return (NULL);
}

void	philo_tablenew_controller(struct s_table *table)
{
	//pthread_t thread;
	
	controller(table);
	//pthread_create(&thread, NULL, &controller, table);
	//table->thread = thread;
}
