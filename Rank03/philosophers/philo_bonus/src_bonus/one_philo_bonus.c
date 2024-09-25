/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:27:01 by isporras          #+#    #+#             */
/*   Updated: 2024/01/16 13:58:26 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	*ft_one_routine(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	ft_thinking(ph);
	ft_dead_flag(ph);
	printf("%" PRId64 " %d has taken a fork\n", ft_stamp(ph), ph->n_phi);
	ft_usleep(ph->to_die);
	printf("%" PRId64 " %d is dead\n", ft_stamp(ph), ph->n_phi);
	exit(1);
	return (NULL);
}

void	ft_one_philo_bonus(t_philo *ph)
{
	ph[0].pid = fork();
	if (ph[0].pid == 0)
		ft_one_routine(&ph[0]);
	ft_wait_childs(ph);
}
