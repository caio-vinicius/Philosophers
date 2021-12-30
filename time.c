/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 11:00:06 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/30 11:00:28 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned int sec_to_usec(unsigned int seconds)
{
	return (seconds * 1000000);
}

unsigned int milisec_to_usec(unsigned int miliseconds)
{
	return (miliseconds * 1000);
}

unsigned int usec_to_milisec(unsigned int usec)
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

size_t	get_current_milisecond(void)
{
	struct timeval current_time;
	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000);
}

size_t	get_current_relative_milisecond(void)
{
	static struct timeval tv1;
	struct timeval tv2;
	
	if (!tv1.tv_usec)
	{
		gettimeofday(&tv1, NULL);
		return (0);
	}
	gettimeofday(&tv2, NULL);
	//printf("subtraction: %ld - %ld = %ld\n", tv2.tv_usec, tv1.tv_usec, tv2.tv_usec - tv1.tv_usec);
	return (usec_to_milisec(tv2.tv_usec - tv1.tv_usec));
	//return (tv2.tv_usec - tv1.tv_usec);
}

void	perform_action(unsigned int action, struct s_philosopher *philo)
{
	char *str;

	if (action == EATING)
		str = "is eating";
	else if (action == SLEEPING)
		str = "is sleeping";
	else if (action == THINKING)
		str = "is thinking";
	else if (action == FORK)
		str = "has taken a fork";
	else
		str = "died";
	printf("%6ld %d %s\n", get_current_relative_milisecond(), philo->id, str);
}
