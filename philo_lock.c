/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 22:22:30 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/11 22:22:38 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_lock(struct s_philosopher *philo)
{
	pthread_mutex_lock(philo->lock);
	philo->locked = 1;
}

void	philo_unlock(struct s_philosopher *philo)
{
	pthread_mutex_unlock(philo->lock);
	philo->locked = 0;
}
