/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:45:00 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/17 23:53:33 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
