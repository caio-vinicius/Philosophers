/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_perform_action.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:27:35 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/09 18:53:17 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_perform_action(unsigned int action, struct s_philosopher *philo)
{
	if (philo->state == DEAD)
		return ;
	philo->state = action;
	printf("%6ld %ld %s\n",
		ft_gettimeofday_relative(philo->table->start),
		philo->id,
		philo->table->actions.messages[action]);
}
