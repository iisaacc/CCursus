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

int	ft_next_fork(t_philo *ph)
{
	int	pos;

	pos = 0;
	if (ph->n_phi == (ph->total_phi - 1) && ph->total_phi > 1)
		pos = 0;
	else
		pos = ph->n_phi + 1;
	return (pos);
}

void	ft_first_fork(t_philo *ph)
{	
	if (ph->n_phi % 2 == 0)
	{
		pthread_mutex_lock(ph->forks[ph->n_phi]);
		ph->mutex[ph->n_phi] = 1;
	}
	else
	{
		pthread_mutex_lock(ph->forks[ft_next_fork(ph)]);
		ph->mutex[ft_next_fork(ph)] = 1;
	}
	if (ph->to_eat == -1)
		return ;
	printf("%" PRId64 " %d has taken a fork\n", ft_stamp(ph), ph->n_phi);
}

void	ft_second_fork(t_philo *ph)
{
	if (ph->n_phi % 2 == 0)
	{
		pthread_mutex_lock(ph->forks[ft_next_fork(ph)]);
		ph->mutex[ft_next_fork(ph)] = 1;
	}
	else
	{
		pthread_mutex_lock(ph->forks[ph->n_phi]);
		ph->mutex[ph->n_phi] = 1;
	}
	if (ph->to_eat == -1)
		return ;
	printf("%" PRId64 " %d has taken a fork\n", ft_stamp(ph), ph->n_phi);
}

t_philo	*ft_mutex_forks(t_philo *ph)
{
	if (ph->to_eat == -1)
		return (NULL);
	ft_first_fork(ph);
	if (ph->to_eat == -1)
		return (NULL);
	ft_second_fork(ph);
	if (ph->to_eat == -1)
		return (NULL);
	return (ph);
}

void	ft_eating(t_philo *ph)
{
	if(!ft_mutex_forks(ph))
		return ;
	printf("%" PRId64 " %d is eating\n", ft_stamp(ph), ph->n_phi);
	ph->last_eat = ft_time();
	usleep(ph->to_eat * 1000);
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
