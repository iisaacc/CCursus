/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_filo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:27:01 by isporras          #+#    #+#             */
/*   Updated: 2023/12/15 10:27:01 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_one_routine(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	while (1 && ph->to_eat > 0)
	{
		ft_thinking(ph);
		if (ph->to_eat < 0)
			break ;
		printf("%" PRId64 " %d has taken a fork\n", ft_stamp(ph), ph->n_phi);
		usleep(ph->to_die * 1000);
		if (ph->to_eat == -1)
			break ;
	}
	return (NULL);
}

void	ft_one_philo(t_philo *ph)
{
	pthread_create(ph[ph[0].total_phi].thread, NULL, &ft_observing, (void *)ph);
	pthread_create(ph[0].thread, NULL, &ft_one_routine, (void *)&ph[0]);
	pthread_join(*(ph[0].thread), NULL);
	pthread_join(*(ph[ph[0].total_phi].thread), NULL);
}
