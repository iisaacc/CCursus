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

void	ft_eating(t_philo *ph)
{
	pthread_mutex_lock(ph->forks);
	printf("%" PRId64 " Philo %d has taken a fork\n", ft_print_stamp(), ph->n_phi);
	if ((ph + 1)->forks)
	{
		pthread_mutex_lock((ph + 1)->forks);
		printf("%" PRId64 " Philo %d has taken a fork\n", ft_print_stamp(), ph->n_phi);
		printf("%" PRId64 " Philo %d is eating\n", ft_print_stamp(), ph->n_phi);
		usleep(ph->to_eat);
	}
	pthread_mutex_unlock(ph->forks);
	pthread_mutex_unlock(ph->forks);
}

void	ft_thinking(t_philo *ph)
{
	printf("%" PRId64 " Philo %d is thinking\n", ft_print_stamp(), ph->n_phi);
}

void	ft_sleeping(t_philo *ph)
{
	printf("%" PRId64 " Philo %d is sleeping\n", ft_print_stamp(), ph->n_phi);
	usleep(ph->to_sleep);
}

void	*ft_routine(void *arg)
{
	t_philo		*ph;

	ph = (t_philo *)arg;
	while (1)
	{
		ft_thinking(ph);
		ft_eating(ph);
	}
	return (NULL);
}