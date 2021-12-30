/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lstnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:32:14 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/30 10:53:16 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

struct s_philosopher	*philo_lstnew(
	void *(*f)(void*),
	struct s_table *table,
	unsigned int id)
{
	struct s_philosopher *philosopher;
	pthread_t thread;

	philosopher = malloc(sizeof(*philosopher));
	if (!philosopher)
		return (NULL);
	philosopher->id = id;
	philosopher->state = 0;
	philosopher->table = table;
	philosopher->next = NULL;
	philosopher->previous = NULL;
	pthread_create(&thread, NULL, f, philosopher);
	philosopher->thread = thread;
	return (philosopher);
}
