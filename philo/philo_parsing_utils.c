/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:45:00 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/18 22:33:46 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

char	*ft_simple_itoa(unsigned int number)
{
	unsigned int	n;
	int				digits;
	char			*str;

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
	unsigned int	number;
	int				i;

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
	size_t	i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
