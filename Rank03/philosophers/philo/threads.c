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

void	ft_unlock(t_philo *ph)
{
	int	i;

	i = 0;
	while (i < ph[0].total_phi)
	{
		pthread_mutex_unlock(ph[0].forks[i]);
		i++;
	}
}

void	*ft_observing(void *arg)
{
	int		i;
	t_philo *ph;
	t_philo	*obs;

	ph = (t_philo *)arg;
	obs = &ph[ph[0].total_phi];
	i = 0;
	while (obs->total_phi != 0 && obs->eaten != obs->total_phi)
	{
		i = 0;
		obs->eaten = 0;
		while (i < obs->total_phi)
		{
			if (ph[i].times_eat >= ph[i].max_eat && ph[i].max_eat != -1)
				obs->eaten += 1;
			if ((ft_time() - ph[i].last_eat) >= obs->to_die && ph[i].to_eat > -1)
			{
				printf("%" PRId64 " %d died\n", ft_stamp(&ph[i]), ph[i].n_phi);
				obs->total_phi = 0;
			}
			i++;
		}
	}
	i = 0;
	while (i < ph[0].total_phi)
		ph[i++].to_eat = -1;
	return (NULL);
}

pthread_mutex_t	*ft_mutex_forks(t_philo *ph)
{
	pthread_mutex_t	*next_fork;
	
	if (ph->n_phi == (ph->total_phi - 1) && ph->total_phi > 1)
		next_fork = ph->forks[0];
	else
		next_fork = ph->forks[ph->n_phi + 1];
	if (ph->to_eat == -1)
		return (NULL);
	if (ph->n_phi % 2 == 0)
		pthread_mutex_lock(ph->forks[ph->n_phi]);
	else
		pthread_mutex_lock(next_fork);
	printf("%" PRId64 " %d has taken a fork\n", ft_stamp(ph), ph->n_phi);
	if (ph->to_eat == -1)
			return (NULL);
	if (ph->n_phi % 2 == 0)
		pthread_mutex_lock(next_fork);
	else
		pthread_mutex_lock(ph->forks[ph->n_phi]);
	if (ph->to_eat == -1)
		return (NULL);
	printf("%" PRId64 " %d has taken a fork\n", ft_stamp(ph), ph->n_phi);
	return (next_fork);
}

void	ft_eating(t_philo *ph)
{
	pthread_mutex_t	*next_fork;

	next_fork = ft_mutex_forks(ph);
	if (!next_fork)
		return ;
	printf("%" PRId64 " %d is eating\n", ft_stamp(ph), ph->n_phi);
	ph->last_eat = ft_time();
	usleep(ph->to_eat * 1000);
	pthread_mutex_unlock(ph->forks[ph->n_phi]);
	pthread_mutex_unlock(next_fork);
	ph->times_eat += 1;
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
	t_philo	*ph;

	ph = (t_philo *)arg;
	while (1 && ph->to_eat > 0)
	{
		ft_thinking(ph);
		if (ph->to_eat > 0)
			ft_eating(ph);
		else
			break;
		if (ph->to_eat > 0)
			ft_sleeping(ph);
		else
			break;
		//printf("philo: %d times eat: %d\n", ph->n_phi, ph->times_eat);
	}
	return (NULL);
}
