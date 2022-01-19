/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing_utils_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:36:14 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/18 23:40:01 by csouza-f         ###   ########.fr       */
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
