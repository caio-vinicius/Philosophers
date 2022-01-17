/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_llstnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:29:35 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/16 22:25:25 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

static void	philo_lstadd_back(
	struct s_philosopher **philo,
	struct s_philosopher *new)
{
	struct s_philosopher *tmp;

	tmp = philo_lstlast(*philo);
	if (tmp)
	{
		tmp->next = new;
		tmp->next->previous = tmp;	
	}
	else
		*philo = new;
}

static struct s_philosopher	*philo_lstnew(
	void *(*f)(void*),
	struct s_forks *fork_left,
	struct s_table *table,
	unsigned int id)
{
	struct s_philosopher *philosopher;
	pthread_t thread;

	philosopher = malloc(sizeof(*philosopher));
	if (!philosopher)
		return (NULL);
	philosopher->id = id;
	if (id % 2)
		philosopher->delay = 5;
	else
		philosopher->delay = 0;
	philosopher->state = NOT_RUNNING;
	philosopher->nbr_of_times_eaten = 0;
	philosopher->table = table;
	philosopher->fork_left = fork_left;
	philosopher->next = NULL;
	philosopher->previous = NULL;
	pthread_create(&thread, NULL, f, philosopher);
	philosopher->thread = thread;
	philosopher->last_meal = ft_gettimeofday();
	return (philosopher);
}

struct s_forks	*philo_forks_get(struct s_forks *forks, int position)
{
	while (position)
	{
		if (position < 0)
		{
			forks = forks->previous;
			position++;
		}
		else
		{
			forks = forks->next;
			position--;
		}
	}
	return (forks);	
}

struct s_philosopher	*philo_llstnew(
	void *(*f)(void*),
	struct s_forks *forks,
	struct s_table *table,
	size_t amount)
{
	struct s_philosopher *philo;
	struct s_philosopher *new;
	struct s_forks *fork_left;
	size_t i;

	fork_left = philo_forks_get(forks, (0 - 1));
	philo = philo_lstnew(f, fork_left, table, 0);
	i = 1;
	while (i < amount)
	{
		fork_left = philo_forks_get(forks, (i - 1));
		new = philo_lstnew(f, fork_left, table, i);
		if (!new)
		{
			philo_lstfree(philo);
			return (NULL);
		}
		philo_lstadd_back(&philo, new);
		i++;
	}
	return (philo);
}
