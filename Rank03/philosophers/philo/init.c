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

void	*ft_init_threads(t_philo *ph)
{
	int	i;

	i = 1;
	while (i < ph[i].total_phi)
	{
		pthread_create(ph[i].thread, NULL, &ft_routine, (void *)&ph[i]);
		if (ph[i].thread == NULL)
			return (NULL);
		i++;
	}
	
	i = 1;
	while (i < ph[i].total_phi)
	{
		pthread_join(*(ph[i].thread), NULL);
		i++;
	}
	return (ph);
}

void	ft_init(t_philo *ph, char **argv, int argc)
{
	int	i;
	int	total_phi;

	total_phi = ft_atoi(argv[1]);
	i = 1;
	while (i <= total_phi)
	{
		ph[i].total_phi = total_phi;
		ph[i].to_die = (int64_t)ft_atoi(argv[2]);
		ph[i].to_eat = (int64_t)ft_atoi(argv[3]);
		ph[i].to_sleep = (int64_t)ft_atoi(argv[4]);
		ph[i].n_phi = i;
		ph[i].thread = malloc(sizeof(pthread_t));
		ph[i].forks = malloc(sizeof(pthread_mutex_t));
		i++;
	}
	i = 1;
	while (i < total_phi)
	{
		if (argc == 6)
			ph[i++].times_eat = ft_atoi(argv[5]);
		else
			ph[i++].times_eat = -1;
	}
	ft_init_threads(ph);
}
