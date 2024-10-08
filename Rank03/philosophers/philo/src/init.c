/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:25:36 by isporras          #+#    #+#             */
/*   Updated: 2024/01/10 17:14:32 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_init_threads(t_philo *ph)
{
	int			i;

	pthread_create(ph[ph[0].total_phi].thread, NULL, &ft_observing, (void *)ph);
	i = 0;
	while (i < ph[0].total_phi)
	{
		pthread_create(ph[i].thread, NULL, &ft_routine, (void *)&ph[i]);
		if (ph[i].thread == NULL)
			return (NULL);
		i++;
	}
	i = 0;
	while (i < ph[0].total_phi)
	{
		pthread_join(*(ph[i].thread), NULL);
		i++;
	}
	pthread_join(*(ph[ph[0].total_phi].thread), NULL);
	return (ph);
}

pthread_mutex_t	**ft_init_forks(int total_phi)
{
	pthread_mutex_t	**forks;
	int				i;

	forks = calloc(total_phi, (sizeof(pthread_mutex_t *)));
	if (forks == NULL)
	{
		printf("Error: malloc failed\n");
		return (NULL);
	}
	i = 0;
	while (i < total_phi)
	{
		forks[i] = calloc(1, sizeof(pthread_mutex_t));
		if (forks[i] == NULL)
		{
			printf("Error: malloc failed\n");
			return (NULL);
		}
		pthread_mutex_init(forks[i], NULL);
		i++;
	}
	return (forks);
}

void	ft_init_struct(t_philo *ph, char **argv, pthread_mutex_t **forks
						, int *mutex)
{
	int		i;
	int64_t	begin;
	int		total_phi;

	total_phi = ft_atoi(argv[1]);
	begin = ft_time();
	i = 0;
	while (i <= total_phi)
	{
		ph[i].total_phi = total_phi;
		ph[i].to_die = (int64_t)ft_atoi(argv[2]);
		ph[i].to_eat = (int64_t)ft_atoi(argv[3]);
		ph[i].to_sleep = (int64_t)ft_atoi(argv[4]);
		ph[i].n_phi = i;
		ph[i].thread = calloc(1, sizeof(pthread_t));
		ph[i].forks = forks;
		ph[i].last_eat = ft_time();
		ph[i].begin = begin;
		ph[i].times_eat = 0;
		ph[i].mutex = mutex;
		ph[i].eaten = 0;
		i++;
	}
}

void	ft_init(t_philo *ph, char **argv, int argc)
{
	int				i;
	int				total_phi;
	pthread_mutex_t	**forks;
	int				*mutex;

	total_phi = ft_atoi(argv[1]);
	mutex = calloc(total_phi, sizeof(int));
	forks = ft_init_forks(total_phi);
	ft_init_struct(ph, argv, forks, mutex);
	i = 0;
	while (i <= total_phi)
	{
		if (argc == 6)
			ph[i++].max_eat = ft_atoi(argv[5]);
		else
			ph[i++].max_eat = -1;
	}
	if (total_phi == 1)
		ft_one_philo(ph);
	else
		ft_init_threads(ph);
}
