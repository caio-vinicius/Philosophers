/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tablefree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 11:58:21 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/30 16:30:36 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_tablefree(struct s_table *table)
{
	if (table->philo)
		philo_lstfree(table->philo);
	if (table->args)
		free(table->args);
	pthread_mutex_destroy(table->lock);
	free(table->lock);
	free(table);	
}
