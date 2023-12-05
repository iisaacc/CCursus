/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:06:08 by isporras          #+#    #+#             */
/*   Updated: 2023/12/05 16:58:31 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eating(t_philo *ph)
{
	pthread_mutex_t	*next_fork;

	pthread_mutex_lock(ph->forks[ph->n_phi]);
	printf("%" PRId64 " %d has taken a fork\n", ft_stamp(ph), ph->n_phi);
	if (ph->n_phi == (ph->total_phi - 1) && ph->total_phi > 1)
		next_fork = ph->forks[0];
	else
		next_fork = ph->forks[ph->n_phi + 1];
	pthread_mutex_lock(next_fork);
	printf("%" PRId64 " %d has taken a fork\n", ft_stamp(ph), ph->n_phi);
	printf("%" PRId64 " %d is eating\n", ft_stamp(ph), ph->n_phi);
	usleep(ph->to_eat * 1000);
	pthread_mutex_unlock(ph->forks[ph->n_phi]);
	pthread_mutex_unlock(next_fork);
}

void	ft_thinking(t_philo *ph)
{
	printf("%" PRId64 " %d is thinking\n", ft_stamp(ph), ph->n_phi);
}

void	ft_sleeping(t_philo *ph)
{
	printf("%" PRId64 " %d is sleeping\n", ft_stamp(ph), ph->n_phi);
	usleep(ph->to_sleep * 1000);
}

void	*ft_routine(void *arg)
{
	t_philo		*ph;

	ph = (t_philo *)arg;
	while (1)
	{
		ft_thinking(ph);
		ft_eating(ph);
		ft_sleeping(ph);
	}
	return (NULL);
}
