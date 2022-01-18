/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tablenew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:08:35 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/16 22:24:56 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_tabledefine_actions(struct s_table *table)
{
	table->actions[0] = "has taken a fork";
	table->actions[1] = "is eating";
	table->actions[2] = "is sleeping";
	table->actions[3] = "is thinking";
	table->actions[4] = "died";
}

struct s_table	*philo_tablenew(struct s_args *args)
{
	struct s_table *table;
	struct s_forks *forks;

	table = malloc(sizeof(*table));
	philo_tabledefine_actions(table);
	table->args = args;
	table->state = RUNNING;
	table->start = ft_gettimeofday();
	forks = philo_lforksnew(args->number_of_philosophers);
	table->philo = philo_llstnew(&philo_simulation,
				forks,
				table,
				args->number_of_philosophers);
	return (table);
}
