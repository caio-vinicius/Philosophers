/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_llstnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:29:35 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/30 10:53:32 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

struct s_philosopher	*philo_llstnew(
	void *(*f)(void*),
	struct s_table *table,
	size_t amount)
{
	struct s_philosopher *philo;
	struct s_philosopher *new;
	size_t i;

	philo = philo_lstnew(f, table, 0);
	i = 1;
	while (i < amount)
	{
		new = philo_lstnew(f, table, i);
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
