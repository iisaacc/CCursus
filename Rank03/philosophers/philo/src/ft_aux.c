/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:34:26 by isporras          #+#    #+#             */
/*   Updated: 2024/01/10 16:48:58 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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

void	ft_print_arg(void)
{
	printf("Introduce at least 4 arguments especifying:\n");
	printf("- Number of philosophers (Max 200)\n");
	printf("- Time to die\n");
	printf("- Time to eat\n");
	printf("- Time to sleep\n");
	printf("- Number of times each philosopher must eat (OPTIONAL)\n");
}

int64_t	ft_time(void)
{
	struct timeval	tv;
	int64_t			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

int64_t	ft_stamp(t_philo *ph)
{
	int64_t	stamp;
	int64_t	time;

	time = ft_time();
	stamp = time - ph->begin;
	return (stamp);
}

void	ft_clean(t_philo *ph)
{
	int	i;

	i = 0;
	while (i <= ph[0].total_phi)
	{
		free(ph[i].thread);
		i++;
	}
	i = 0;
	while (i < ph[0].total_phi)
	{
		free(ph[0].forks[i]);
		i++;
	}
	free(ph[0].mutex);
	free(ph[0].forks);
}
