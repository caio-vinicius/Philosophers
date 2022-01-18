/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 11:00:06 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/18 20:33:46 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_miliseconds	sec_to_milisec(unsigned int seconds);
unsigned int	milisec_to_usec(unsigned int miliseconds);
t_miliseconds	usec_to_milisec(unsigned int usec);
size_t			sec_to_usec(size_t seconds);

void	ft_sleep(unsigned int seconds)
{
	usleep(sec_to_usec(seconds));
}

void	ft_msleep(t_miliseconds ms)
{
	usleep(milisec_to_usec(ms));
}

t_miliseconds	ft_gettimeofday(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (sec_to_milisec(current_time.tv_sec) + \
		usec_to_milisec(current_time.tv_usec));
}

t_miliseconds	ft_gettimeofday_relative(t_miliseconds start)
{
	return (ft_gettimeofday() - start);
}
