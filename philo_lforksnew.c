/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lforksnew.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 20:16:36 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/09 12:10:19 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static struct s_forks *philo_forkslast(struct s_forks *forks)
{
	while (forks)
	{
		if (!forks->next)
			return (forks);
		forks = forks->next;
	}
	return (NULL);
}

static void	philo_forksadd_back(
	struct s_forks **forks,
	struct s_forks *new)
{
	struct s_forks *tmp;

	tmp = philo_forkslast(*forks);
	if (tmp)
	{
		tmp->next = new;
		tmp->next->previous = tmp;
	}
	else
		*forks = new;
}

static struct s_forks	*philo_forksnew(void)
{
	struct s_forks *forks;
	pthread_mutex_t *lock;

	forks = malloc(sizeof(*forks));
	if (!forks)
		return (NULL);
	lock = malloc(sizeof(*lock));
	pthread_mutex_init(lock, NULL);
	forks->lock = lock;
	forks->locked = 0;
	forks->next = NULL;
	forks->previous = NULL;
	return (forks);
}

struct s_forks	*philo_lforksnew(size_t amount)
{
	struct s_forks *forks;
	struct s_forks *new;
	size_t i;
	
	if (amount)
	{
		forks = philo_forksnew();
		i = 1;
	}
	while (i < amount)
	{
		new = philo_forksnew();
		if (!new)
		{
			philo_forksfree(forks);
			return (NULL);
		}
		philo_forksadd_back(&forks, new);
		i++;
		if (i == amount)
		{
			new->next = forks;
			forks->previous = new;
		}
	}
	return (forks);
}
