/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 10:15:27 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/17 23:39:39 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

struct s_table	*philo_tablenew(struct s_args *args);
void			philo_tablefree(struct s_table *table);
void			philo_tablenew_manager(struct s_table *table);

struct s_args	*philo_parsing(int argc, char **argv);
void			usage(void);

static int	philosophers(int argc, char **argv)
{
	struct s_philosopher	*philo;
	struct s_args			*args;
	struct s_table			*table;

	if (!*++argv)
	{
		usage();
		return (EXIT_FAILURE);
	}
	args = philo_parsing(argc, argv);
	if (!args)
	{
		printf("Error: %s", "The arguments are incorrect in some way.");
		return (EXIT_FAILURE);
	}
	table = philo_tablenew(args);
	philo_tablenew_manager(table);
	philo = table->philo;
	while (philo)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next;
	}
	pthread_join(table->thread, NULL);
	philo_tablefree(table);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	if (!philosophers(argc, argv))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
