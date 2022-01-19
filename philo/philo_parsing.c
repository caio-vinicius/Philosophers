/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:32:55 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/18 22:50:35 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

char	*ft_simple_itoa(unsigned int number);
int		ft_simple_atoi(char *str);
int		ft_strcmp(char *str1, char *str2);
int		ft_isdigit(int c);

static int	are_non_negative_numbers(char **numbers)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (numbers[i])
	{
		while (numbers[i][j])
		{
			if (!ft_isdigit(numbers[i][j]))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

static int	are_acceptable_size(char **numbers)
{
	size_t	i;
	char	*str;

	i = 0;
	while (numbers[i])
	{
		str = ft_simple_itoa(ft_simple_atoi(numbers[i]));
		if (!ft_strcmp(str, numbers[i]))
		{
			free(str);
			return (0);
		}
		free(str);
		i++;
	}
	return (1);
}

static int	are_enough(int argc)
{
	if (argc < TOTAL_AMOUNT_ARGUMENTS - 1 || argc > TOTAL_AMOUNT_ARGUMENTS)
		return (0);
	return (1);
}

int	philo_parsing_basic(int argc, char **argv)
{
	if (!*argv)
		return (0);
	if (!are_enough(--argc))
		return (0);
	if (!are_non_negative_numbers(argv))
		return (0);
	if (!are_acceptable_size(argv))
		return (0);
	return (1);
}

struct s_args	*philo_parsing(int argc, char **argv)
{
	struct s_args	*args;

	if (!philo_parsing_basic(argc, ++argv))
		return (NULL);
	args = malloc(sizeof(*args));
	args->number_of_philosophers = ft_simple_atoi(argv[0]);
	if (!args->number_of_philosophers)
	{
		free(args);
		return (NULL);
	}
	args->nbr_of_times_each_philo_must_eat = 0;
	if (argv[4])
	{
		args->nbr_of_times_each_philo_must_eat = ft_simple_atoi(argv[4]);
		if (!args->nbr_of_times_each_philo_must_eat)
		{
			free(args);
			return (NULL);
		}
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
