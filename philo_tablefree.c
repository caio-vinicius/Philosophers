/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tablefree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 11:58:21 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/16 22:51:50 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_tablefree(struct s_table *table)
{
	if (table->philo->fork_left)
		philo_forksfree(table->philo->fork_left,
				table->args->number_of_philosophers);
	if (table->philo)
		philo_lstfree(table->philo);
	if (table->args)
		free(table->args);
	free(table);	
}
