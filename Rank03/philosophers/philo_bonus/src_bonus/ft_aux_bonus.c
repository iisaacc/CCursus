/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:01:27 by isporras          #+#    #+#             */
/*   Updated: 2024/01/10 18:32:52 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	*ft_observing(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	while (1)
	{
		if (ft_time() - ph->last_eat > ph->to_die && ph->n_phi == 0)
		{
			sem_wait(ph->print);
			printf("%" PRId64 " %d died\n", ft_stamp(ph), ph->n_phi);
			sem_post(ph->print);
			exit(0);
		}
		else if (ft_time() - ph->last_eat > ph->to_die + 100 && ph->n_phi != 0)
		{
			sem_wait(ph->print);
			printf("%" PRId64 " %d died\n", ft_stamp(ph), ph->n_phi);
			sem_post(ph->print);
			exit(0);
		}
		if (ph->to_eat == -1)
			exit(1);
	}
	return (NULL);
}

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
	printf("- Number of philosophers\n");
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
