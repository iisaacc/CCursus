/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:07:38 by isporras          #+#    #+#             */
/*   Updated: 2023/11/22 11:52:28 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <inttypes.h>

typedef struct s_philo
{
	int		n_phi;
	int64_t	to_die;
	int64_t	to_eat;
	int64_t	to_sleep;
	int		times_eat;
} t_philo;

void	ft_init(t_philo *ph, char **argv, int argc);
void	print_philo(t_philo *ph);
void	ft_print_stamp(void);

#endif