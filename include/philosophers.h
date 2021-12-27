/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 10:16:18 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/26 22:23:26 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct s_args {
	unsigned int number_of_philosophers;
	unsigned int time_to_die;
	unsigned int time_to_eat;
	unsigned int time_to_sleep;
	unsigned int number_of_times_each_philosopher_must_eat;
};

#endif
