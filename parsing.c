/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:32:55 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/28 18:33:25 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_putstr(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	usage(void)
{
	printf("\nUsage: philo NUMBER_OF_PHILOSOPHERS" 
	" TIME_TO_DIE TIME_TO_EAT TIME_TO_SLEEP" 
	" [ NUMBER_OF_TIMES_EACH_PHILOSOPHER_MUST_EAT ]\n\n"
	"I’ve never thought philosophy would be so deadly.\n\n"
	"Options:\n\n"
	" NUMBER_OF_PHILOSOPHERS				"
	"Is the number of philosophers and also the number of forks.\n"
	" TIME_TO_DIE					"
	"In milliseconds, if a philosopher doesn’t start eating ’time_to_die’"
	" milliseconds after starting their last meal or the beginning of the"
	" simulation, it dies.\n"
	" TIME_TO_EAT					"
	"Is in milliseconds and is the time it takes for a philosopher to eat."
	" During that time they will need to keep the two forks.\n"
	" TIME_TO_SLEEP					"
	"Is in milliseconds and is the time the philosopher"
	" will spend sleeping.\n"
	" NUMBER_OF_TIMES_EACH_PHILOSOPHER_MUST_EAT	"
	"Argument is optional, if all philosophers eat at least"
	" ’number_of_times_each_philosopher_must_eat’ the simulation will stop."
	" If not specified, the simulation will stop only at the death"
	" of a philosopher.\n");
}

void	error(char *str)
{
	printf("Error: %s", str);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	are_non_negative_numbers(char **numbers)
{
	size_t i;
	size_t j;

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

char	*ft_simple_itoa(unsigned int number)
{
	int digits;
	unsigned int n;
	char *str;
	
	digits = 0;
	n = number;
	while (n)
	{
		n /= 10;
		digits++;
	}
	str = malloc(digits + 1);
	str[digits--] = 0;
	while (number)
	{
		str[digits] = (number % 10) + '0';
		number /= 10;
		digits--;
	}
	return (str);
}

int	ft_simple_atoi(char *str)
{
	int i;
	unsigned int number;
	
	i = 0;
	number = 0;
	while (str[i])
	{
		number = (number * 10) + str[i] - '0';
		i++;
	}
	return (number);
}

int	ft_strcmp(char *str1, char *str2)
{
	size_t i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

int	are_acceptable_size(char **numbers)
{
	size_t i;
	char *str;

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

int	are_enough(int argc)
{
	#define TOTAL_AMOUNT_ARGUMENTS 5
	if (argc < TOTAL_AMOUNT_ARGUMENTS - 1 || argc > TOTAL_AMOUNT_ARGUMENTS)
		return (0);
		// NOT GOOD ENOUGH! I HAVE A LAUNDRY MACHINE |o|
	return (1);
}

struct s_args *parsing(int argc, char **argv)
{
	struct s_args *args;

	if (!are_enough(--argc))
		return (NULL);
	if (!are_non_negative_numbers(argv))
		return (NULL);
	if (!are_acceptable_size(argv))
		return (NULL);
	args = malloc(sizeof(*args));
	args->number_of_philosophers = ft_simple_atoi(argv[0]);
	args->time_to_die = ft_simple_atoi(argv[1]);
	args->time_to_eat = ft_simple_atoi(argv[2]);
	args->time_to_sleep = ft_simple_atoi(argv[3]);
	args->number_of_times_each_philosopher_must_eat = 0;
	if (argv[4])
		args->number_of_times_each_philosopher_must_eat = ft_simple_atoi(argv[4]);
	return (args);
}
