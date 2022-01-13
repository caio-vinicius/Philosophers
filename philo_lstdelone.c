/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lstdelone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 22:40:54 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/12 21:29:17 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	lstdel_first_or_last_philo(
	struct s_philosopher **philos,
	struct s_philosopher *lst)
{
	if (!lst->previous && !lst->next)
		*philos = NULL;
	else if (!lst->previous)
	{
		*philos = lst->next;
		(*philos)->previous = NULL;
		lst->next = NULL;
	}
	else if (!lst->next)
	{
		lst->previous->next = NULL;
		lst->previous = NULL;
	}
	free(lst);
}

void	philo_lstdelone(
	struct s_philosopher **philos,
	struct s_philosopher *philo)
{
	struct s_philosopher *lst;

	if (!philo->previous || !philo->next)
	{	
		lstdel_first_or_last_philo(philos, philo);
		return ;
	}
	lst = *philos;
	while (lst) {
		if (lst == philo)
		{
			lst->previous->next = lst->next;
			lst->next->previous = lst->previous;
			lst->next = NULL;
			lst->previous = NULL;
			free(lst);
			break ;
		}
		lst = lst->next;
	}
}
