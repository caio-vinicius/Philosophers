/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_forksfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 20:42:10 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/16 22:07:48 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_forksfree(struct s_forks *forks, unsigned int amount)
{
	struct s_forks *tmp;

	while (amount)
	{
		tmp = forks;
		forks = forks->next;
		free(tmp->lock);
		free(tmp);
		amount--;
	}
}
