/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:00:44 by isporras          #+#    #+#             */
/*   Updated: 2024/01/10 18:32:07 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_dead_flag(t_philo *ph)
{
	if (ph->times_eat >= ph->max_eat && ph->max_eat != -1)
		exit(1);
	else if (ft_time() - ph->last_eat > ph->to_die && ph->n_phi == 0)
		exit(0);
	else if (ph->n_phi > 0 && ft_time() - ph->last_eat > ph->to_die + 100)
		exit(0);
}

void	ft_thinking(t_philo *ph)
{
	sem_wait(ph->print);
	printf("%" PRId64 " %d is thinking\n", ft_stamp(ph), ph->n_phi);
	sem_post(ph->print);
}

void	ft_sleeping(t_philo *ph)
{
	ft_dead_flag(ph);
	sem_wait(ph->print);
	printf("%" PRId64 " %d is sleeping\n", ft_stamp(ph), ph->n_phi);
	sem_post(ph->print);
	usleep(ph->to_sleep * 1000);
}

void	ft_eating(t_philo *ph)
{
	ft_dead_flag(ph);
	if (ph->n_phi % 2 != 0 && ph->times_eat == 0)
		usleep(100);
	sem_wait(ph->sem);
	sem_wait(ph->print);
	printf("%" PRId64 " %d has taken a fork\n", ft_stamp(ph), ph->n_phi);
	sem_post(ph->print);
	ft_dead_flag(ph);
	sem_wait(ph->sem);
	ft_dead_flag(ph);
	sem_wait(ph->print);
	printf("%" PRId64 " %d has taken a fork\n", ft_stamp(ph), ph->n_phi);
	printf("%" PRId64 " %d is eating\n", ft_stamp(ph), ph->n_phi);
	sem_post(ph->print);
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
