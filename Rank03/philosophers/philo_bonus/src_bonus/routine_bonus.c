/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:00:44 by isporras          #+#    #+#             */
/*   Updated: 2023/12/15 12:00:44 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_observer(t_philo *ph)
{
	int		i;
	t_philo	*obs;

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
			if (ft_time() - ph[i].last_eat >= obs->to_die && ph[i].to_eat > -1)
			{
				printf("%" PRId64 " %d died\n", ft_stamp(&ph[i]), ph[i].n_phi);
				obs->total_phi = 0;
			}
			i++;
		}
	}
	ft_dead_flag(ph);
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

void	ft_eating(t_philo *ph)
{
	if (ph->to_eat < 0)
		return ;
	sem_wait(ph->sem);
	printf("%" PRId64 " %d has taken a fork\n", ft_stamp(ph), ph->n_phi);
	if (ph->to_eat < 0)
		return ;
	sem_wait(ph->sem);
	if (ph->to_eat < 0)
		return ;
	printf("%" PRId64 " %d has taken a fork\n", ft_stamp(ph), ph->n_phi);
	printf("%" PRId64 " %d is eating\n", ft_stamp(ph), ph->n_phi);
	ph->last_eat = ft_time();
	usleep(ph->to_eat * 1000);
	ph->times_eat++;
	sem_post(ph->sem);
	sem_post(ph->sem);
}

void	ft_routine(t_philo *ph)
{
	while (ph->to_eat > 0)
	{
		ft_thinking(ph);
		if (ph->to_eat > 0)
			ft_eating(ph);
		printf("to_eat: %d\n", ph->to_eat);
		if (ph->to_eat > 0)
			ft_sleeping(ph);
	}
}