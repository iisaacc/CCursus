/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:06:08 by isporras          #+#    #+#             */
/*   Updated: 2023/11/22 12:11:34 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *arg)
{
	t_thr_ph	*thr_ph;
	t_philo		*ph;

	thr_ph = (t_thr_ph *)arg;
	ph = thr_ph->ph;
	while (1)
	{
		printf("%" PRId64 " Philo %d is thinking\n", ft_print_stamp(), ph->n_phi);
		usleep(thr_ph->data->to_sleep);

		pthread_mutex_lock(ph->forks);
		printf("%" PRId64 " Philo %d is eating\n", ft_print_stamp(), ph->n_phi);
		usleep(thr_ph->data->to_eat);
		pthread_mutex_unlock(ph->forks);

		printf("%" PRId64 " Philo %d is sleeping\n", ft_print_stamp(), ph->n_phi);
		usleep(thr_ph->data->to_sleep);
	}
	return (NULL);
}