/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:32:55 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/18 23:40:19 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		ft_simple_atoi(char *str);
int		philo_parsing_basic(int argc, char **argv);

void	*return_free(struct s_args *args)
{
	free(args);
	args = NULL;
	return (NULL);
}

struct s_args	*philo_parsing(int argc, char **argv)
{
	struct s_args	*args;

	if (!philo_parsing_basic(argc, ++argv))
		return (NULL);
	args = malloc(sizeof(*args));
	args->number_of_philosophers = ft_simple_atoi(argv[0]);
	if (!args->number_of_philosophers)
		return (return_free(args));
	args->nbr_of_times_each_philo_must_eat = 0;
	if (argv[4])
	{
		args->nbr_of_times_each_philo_must_eat = ft_simple_atoi(argv[4]);
		if (!args->nbr_of_times_each_philo_must_eat)
			return (return_free(args));
	}
	args->time_to_die = ft_simple_atoi(argv[1]);
	args->time_to_eat = ft_simple_atoi(argv[2]);
	if (!args->time_to_eat)
		args->time_to_eat = REPLACE_DELAY_MILISEC;
	args->time_to_sleep = ft_simple_atoi(argv[3]);
	if (!args->time_to_sleep)
		args->time_to_sleep = REPLACE_DELAY_MILISEC;
	return (args);
}
