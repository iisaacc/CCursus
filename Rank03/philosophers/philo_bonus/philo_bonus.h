/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:45:42 by isporras          #+#    #+#             */
/*   Updated: 2024/01/10 12:09:41 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/time.h>
# include <inttypes.h>
# include <unistd.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_philo
{
	int			n_phi;
	int			total_phi;
	int64_t		last_eat;
	pthread_t	*thread;
	int64_t		to_die;
	int64_t		to_eat;
	int64_t		to_sleep;
	int			max_eat;
	int			eaten;
	int			times_eat;
	int64_t		begin;
	sem_t		*sem;
	pid_t		pid;
}	t_philo;

void	ft_print_arg(void);
int64_t	ft_time(void);
int64_t	ft_stamp(t_philo *ph);
int		ft_check_argv(char **argv);
int		ft_atoi(char *str);
void	ft_init(t_philo *ph, char **argv, int argc);
void	ft_routine(t_philo *ph);
void	ft_dead_flag(t_philo *ph);
void	ft_thinking(t_philo *ph);
void	ft_one_philo_bonus(t_philo *ph);
void	ft_wait_childs(t_philo *ph);
void	*ft_observing(void *arg);

#endif