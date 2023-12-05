/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:34:26 by isporras          #+#    #+#             */
/*   Updated: 2023/11/22 11:55:10 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_arg(void)
{
	printf("Introduce at least 4 arguments especifying:\n");
	printf("- Number of philosophers\n");
	printf("- Time to die\n");
	printf("- Time to eat\n");
	printf("- Time to sleep\n");
	printf("- Number of times each philosopher must eat to \"win\" (OPTIONAL)\n");
}

int64_t	ft_print_stamp(void)
{
	struct timeval	tv;
	int64_t			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

void print_philo(t_philo *ph)
{
	printf("n_phi: %d\n", ph->total_phi);
	printf("to_die: %" PRId64 "\n", ph->to_die);
	printf("to_eat: %" PRId64 "\n", ph->to_eat);
	printf("to_sleep: %" PRId64 "\n", ph->to_sleep);
	printf("times_eat: %d \n", ph->times_eat);
}