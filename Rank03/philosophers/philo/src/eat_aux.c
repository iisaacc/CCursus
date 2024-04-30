/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:36:39 by isporras          #+#    #+#             */
/*   Updated: 2024/04/30 12:04:27 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_dead_flag(t_philo *ph)
{
	int	i;

	i = 0;
	while (i < ph[0].total_phi)
		ph[i++].to_eat = -1;
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
	if (ph->n_phi % 2 != 0 && ph->times_eat == 0)
		usleep(50);
	pthread_mutex_lock(ph->forks[ph->n_phi]);
	ph->mutex[ph->n_phi] = 1;
	if (ph->to_eat == -1)
		return ;
	printf("%" PRId64 " %d has taken a fork\n", ft_stamp(ph), ph->n_phi);
}

void	ft_second_fork(t_philo *ph)
{
	if (ph->n_phi % 2 != 0 && ph->times_eat == 0)
		usleep(50);
	pthread_mutex_lock(ph->forks[ft_next_fork(ph)]);
	ph->mutex[ft_next_fork(ph)] = 1;
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
