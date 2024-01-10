/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:00:44 by isporras          #+#    #+#             */
/*   Updated: 2024/01/10 13:05:04 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_dead_flag(t_philo *ph)
{
	if (ph->times_eat >= ph->max_eat && ph->max_eat != -1)
		exit(1);
	else if (ft_time() - ph->last_eat >= ph->to_die)
		exit(0);
}

void	ft_thinking(t_philo *ph)
{
	printf("%" PRId64 " %d is thinking\n", ft_stamp(ph), ph->n_phi);
}

void	ft_sleeping(t_philo *ph)
{
	ft_dead_flag(ph);
	printf("%" PRId64 " %d is sleeping\n", ft_stamp(ph), ph->n_phi);
	usleep(ph->to_sleep * 1000);
}

void	ft_eating(t_philo *ph)
{
	ft_dead_flag(ph);
	sem_wait(ph->sem);
	printf("%" PRId64 " %d has taken a fork\n", ft_stamp(ph), ph->n_phi);
	ft_dead_flag(ph);
	sem_wait(ph->sem);
	ft_dead_flag(ph);
	printf("%" PRId64 " %d has taken a fork\n", ft_stamp(ph), ph->n_phi);
	printf("%" PRId64 " %d is eating\n", ft_stamp(ph), ph->n_phi);
	ph->last_eat = ft_time();
	usleep(ph->to_eat * 1000);
	sem_post(ph->sem);
	sem_post(ph->sem);
	ph->times_eat++;
}

void	ft_routine(t_philo *ph)
{
	while (ph->to_eat > 0)
	{
		ft_dead_flag(ph);
		ft_thinking(ph);
		ft_dead_flag(ph);
		ft_eating(ph);
		ft_dead_flag(ph);
		ft_sleeping(ph);
	}
}
