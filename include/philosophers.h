/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 10:16:18 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/28 11:42:29 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// PHILOSOPHER POSSIBLE STATE

# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define WAITING 4

struct s_args {
	unsigned int number_of_philosophers;
	unsigned int time_to_die;
	unsigned int time_to_eat;
	unsigned int time_to_sleep;
	unsigned int number_of_times_each_philosopher_must_eat;
};

struct s_philosopher {
	unsigned int state;
   	pthread_t thread;
	struct s_args *args;
	struct s_philosopher *next;
	struct s_philosopher *previous;
};

#endif
