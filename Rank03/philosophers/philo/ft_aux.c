/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:34:26 by isporras          #+#    #+#             */
/*   Updated: 2023/11/22 11:55:10 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int64_t	ft_print_stamp(void)
{
	struct timeval	tv;
	int64_t			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

void print_philo(t_data *data)
{
	printf("n_phi: %d\n", data->total_phi);
	printf("to_die: %" PRId64 "\n", data->to_die);
	printf("to_eat: %" PRId64 "\n", data->to_eat);
	printf("to_sleep: %" PRId64 "\n", data->to_sleep);
	printf("times_eat: %d \n", data->times_eat);
}