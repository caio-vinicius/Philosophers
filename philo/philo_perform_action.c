/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_perform_action.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:27:35 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/16 21:52:25 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_perform_action(unsigned int action, struct s_philosopher *philo)
{
	if (philo->state == DEAD || philo->table->state == NOT_RUNNING)
		return (0);
	philo->state = action;
	printf("%6ld %ld %s\n",
		ft_gettimeofday_relative(philo->table->start),
		philo->id,
		philo->table->actions[action]);
	return (1);
}
