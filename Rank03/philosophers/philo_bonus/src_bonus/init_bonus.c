/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:49:13 by isporras          #+#    #+#             */
/*   Updated: 2024/01/10 18:25:41 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_wait_childs(t_philo *ph)
{
	int	eaten;
	int	status;

	eaten = 0;
	while (wait(&status) > 0)
	{
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == 0)
				break ;
			else
				eaten += WEXITSTATUS(status);
			if (eaten == ph[0].total_phi)
				break ;
		}
	}
}

void	ft_init_process(t_philo *ph)
{
	int	i;

	i = 0;
	while (i < ph[0].total_phi)
	{
		ph[i].pid = fork();
		if (ph[i].pid == 0)
		{
			pthread_create(ph[i].thread, NULL, &ft_observing, (void *)&ph[i]);
			ft_routine(&ph[i]);
		}
		i++;
	}
	ft_wait_childs(ph);
	i = 0;
	while (i < ph[0].total_phi)
		kill(ph[i++].pid, SIGKILL);
	i = 0;
	while (i < ph[0].total_phi)
		pthread_join(*(ph[i++].thread), NULL);
}

void	ft_init_struct(t_philo *ph, char **argv, int total_phi, int64_t begin)
{
	int		i;
	sem_t	*sem;
	sem_t	*print;

	sem = sem_open("/s", O_CREAT, S_IRUSR | S_IWUSR, (unsigned int)total_phi);
	print = sem_open("/p", O_CREAT, S_IRUSR | S_IWUSR, 1);
	i = 0;
	while (i <= total_phi)
	{
		ph[i].total_phi = total_phi;
		ph[i].thread = calloc(1, sizeof(pthread_t));
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
		ph[i].print = print;
		i++;
	}
}

void	ft_init(t_philo *ph, char **argv, int argc)
{
	int		total_phi;
	int		i;
	int64_t	begin;

	total_phi = ft_atoi(argv[1]);
	begin = ft_time();
	ft_init_struct(ph, argv, total_phi, begin);
	i = 0;
	while (i <= total_phi)
	{
		if (argc == 6)
			ph[i].max_eat = ft_atoi(argv[5]);
		else
			ph[i].max_eat = -1;
		i++;
	}
	if (total_phi == 1)
		ft_one_philo_bonus(ph);
	else
		ft_init_process(ph);
}
