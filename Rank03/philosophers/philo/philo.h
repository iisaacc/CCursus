/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:07:38 by isporras          #+#    #+#             */
/*   Updated: 2023/12/13 10:45:09 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <inttypes.h>
# include <unistd.h>

typedef struct s_philo
{
	int				n_phi;
	int				total_phi;
	pthread_t		*thread;
	pthread_mutex_t	**forks;
	int64_t			last_eat;
	int64_t			to_die;
	int64_t			to_eat;
	int64_t			to_sleep;
	int				max_eat;
	int				eaten;
	int				times_eat;
	int64_t			begin;
	int				*mutex;
}	t_philo;

void	ft_init(t_philo *ph, char **argv, int argc);
int64_t	ft_time(void);
int64_t	ft_stamp(t_philo *ph);
void	*ft_routine(void *arg);
void	ft_print_arg(void);
int		ft_atoi(char *str);
void	*ft_observing(void *arg);
void	ft_clean(t_philo *ph);
t_philo	*ft_mutex_forks(t_philo *ph);
int		ft_next_fork(t_philo *ph);
void	ft_dead_flag(t_philo *ph);

#endif