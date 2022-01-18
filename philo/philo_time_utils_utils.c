/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time_utils_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:22:15 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/18 20:34:08 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	sec_to_usec(size_t seconds)
{
	return (seconds * 1000000);
}

t_miliseconds	sec_to_milisec(unsigned int seconds)
{
	return (seconds * 1000);
}

unsigned int	milisec_to_usec(unsigned int miliseconds)
{
	return (miliseconds * 1000);
}

t_miliseconds	usec_to_milisec(unsigned int usec)
{
	return (usec * 0.001);
}
