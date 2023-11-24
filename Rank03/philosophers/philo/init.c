/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:25:36 by isporras          #+#    #+#             */
/*   Updated: 2023/11/22 11:47:35 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	n;
	int	sign;
	int	i;

	i = 0;
	n = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * sign);
}

void	ft_init(t_philo *ph, char **argv, int argc)
{
	ph->n_phi = ft_atoi(argv[1]);
	ph->to_die = (int64_t)ft_atoi(argv[2]);
	ph->to_eat = (int64_t)ft_atoi(argv[3]);
	ph->to_sleep = (int64_t)ft_atoi(argv[4]);
	if (argc == 6)
		ph->times_eat = ft_atoi(argv[5]);
	else
		ph->times_eat = -1;
}

void print_philo(t_philo *ph)
{
	printf("n_phi: %d\n", ph->n_phi);
	printf("to_die: %" PRId64 "\n", ph->to_die);
	printf("to_eat: %" PRId64 "\n", ph->to_eat);
	printf("to_sleep: %" PRId64 "\n", ph->to_sleep);
	printf("times_eat: %d \n", ph->times_eat);
}