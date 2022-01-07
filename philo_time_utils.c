/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 11:00:06 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/02 21:16:08 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t sec_to_usec(size_t seconds)
{
	return (seconds * 1000000);
}

miliseconds_t sec_to_milisec(unsigned int seconds)
{
	return (seconds * 1000);
}

unsigned int milisec_to_usec(unsigned int miliseconds)
{
	return (miliseconds * 1000);
}

miliseconds_t usec_to_milisec(unsigned int usec)
{
	return (usec / 1000);
}

void	ft_sleep(unsigned int seconds)
{
	usleep(sec_to_usec(seconds));
}

void	ft_msleep(unsigned int miliseconds)
{
	usleep(milisec_to_usec(miliseconds));
}

miliseconds_t	ft_gettimeofday(void)
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	return (sec_to_milisec(current_time.tv_sec) + usec_to_milisec(current_time.tv_usec));
}

miliseconds_t	ft_gettimeofday_relative(miliseconds_t start)
{
	return (ft_gettimeofday() - start);
}
