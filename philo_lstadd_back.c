/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lstadd_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:30:55 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/28 18:31:06 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_lstadd_back(struct s_philosopher **philo, struct s_philosopher *new)
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
