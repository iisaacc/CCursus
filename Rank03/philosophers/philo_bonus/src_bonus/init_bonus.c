/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:49:13 by isporras          #+#    #+#             */
/*   Updated: 2023/12/15 11:49:13 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_init_process(t_philo *ph)
{
	int	i;

	i = 0;
	while (i < ph[0].total_phi)
	{
		ph[i].pid = fork();
		if (ph[i].pid == 0)
		{
			ft_routine(&ph[i]);
			exit(0);
		}
		i++;
	}
	ft_observer(ph);
	i = 0;
	while (i < ph[0].total_phi)
	{
		wait(NULL);
		i++;
	}
}

void	ft_init_struct(t_philo *ph, char **argv)
{
	int64_t	begin;
	int		i;
	int		total_phi;
	sem_t	*sem;

	total_phi = ft_atoi(argv[1]);
	sem = sem_open("/sema", O_CREAT, S_IRUSR | S_IWUSR, (unsigned int)total_phi);
	begin = ft_time();
	i = 0;
	while (i <= total_phi)
	{
		ph[i].total_phi = total_phi;
		ph[i].to_die = (int64_t)ft_atoi(argv[2]);
		ph[i].to_eat = (int64_t)ft_atoi(argv[3]);
		ph[i].to_sleep = (int64_t)ft_atoi(argv[4]);
		ph[i].n_phi = i;
		ph[i].last_eat = begin;
		ph[i].begin = begin;
		ph[i].times_eat = 0;
		ph[i].eaten = 0;
		ph[i].sem = sem;
		ph[i].pid = -1;
		i++;
	}
}

void	ft_init(t_philo *ph, char **argv, int argc)
{
	int		total_phi;
	int		i;

	total_phi = ft_atoi(argv[1]);
	ft_init_struct(ph, argv);
	i = 0;
	while (i <= total_phi)
	{
		if (argc == 6)
			ph[i].max_eat = ft_atoi(argv[5]);
		else
			ph[i].max_eat = -1;
		i++;
	}
	ft_init_process(ph);
}