/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:06:08 by isporras          #+#    #+#             */
/*   Updated: 2024/01/16 13:50:44 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// void	ft_unlock(t_philo *ph)
// {
// 	int	i;

// 	i = 0;
// 	while (i < ph[0].total_phi)
// 	{
// 		if (ph[i].mutex[i] == 1)
// 			pthread_mutex_unlock(ph[i].forks[i]);
// 		i++;
// 	}
// }

void	*ft_observing(void *arg)
{
	int		i;
	t_philo	*ph;
	t_philo	*obs;

	ph = (t_philo *)arg;
	obs = &ph[ph[0].total_phi];
	while (obs->total_phi != 0 && obs->eaten != obs->total_phi)
	{
		i = 0;
		obs->eaten = 0;
		while (i < obs->total_phi)
		{
			if (ph[i].times_eat >= ph[i].max_eat && ph[i].max_eat != -1)
				obs->eaten += 1;
			if (ft_time() - ph[i].last_eat > obs->to_die && ph[i].to_eat > -1)
			{
				printf("%" PRId64 " %d died\n", ft_stamp(&ph[i]), ph[i].n_phi);
				obs->total_phi = 0;
			}
			i++;
		}
	}
	ft_dead_flag(ph);
	return (NULL);
}

void	ft_eating(t_philo *ph)
{
	if (!ft_mutex_forks(ph))
		return ;
	printf("%" PRId64 " %d is eating\n", ft_stamp(ph), ph->n_phi);
	ph->last_eat = ft_time();
	ft_usleep((ph->to_eat));
	pthread_mutex_unlock(ph->forks[ph->n_phi]);
	ph->mutex[ph->n_phi] = 0;
	pthread_mutex_unlock(ph->forks[ft_next_fork(ph)]);
	ph->mutex[ft_next_fork(ph)] = 0;
	ph->times_eat += 1;
}

void	ft_thinking(t_philo *ph)
{
	printf("%" PRId64 " %d is thinking\n", ft_stamp(ph), ph->n_phi);
}

void	ft_sleeping(t_philo *ph)
{
	printf("%" PRId64 " %d is sleeping\n", ft_stamp(ph), ph->n_phi);
	ft_usleep(ph->to_sleep);
}

void	*ft_routine(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	while (1 && ph->to_eat > 0)
	{
		ft_thinking(ph);
		if (ph->to_eat > 0)
			ft_eating(ph);
		else
			break ;
		if (ph->to_eat > 0)
			ft_sleeping(ph);
		else
			break ;
	}
	return (NULL);
}
