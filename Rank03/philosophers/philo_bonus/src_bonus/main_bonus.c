/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:05:09 by isporras          #+#    #+#             */
/*   Updated: 2024/01/16 13:58:08 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

//void	ft_leaks(void)
//{
//	system("leaks philo_bonus");
//}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = ft_time();
	while ((ft_time() - start) < milliseconds)
		usleep(500);
	return (0);
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
	sem_close(ph[0].sem);
	sem_unlink("/s");
	sem_close(ph[0].print);
	sem_unlink("/p");
}

int	main(int argc, char **argv)
{
	t_philo	ph[200];

	sem_unlink("/s");
	sem_unlink("/p");
	if ((argc == 5 || argc == 6) && ft_check_argv(argv) == 0)
	{
		ft_init(ph, argv, argc);
		ft_clean(ph);
	}
	else
		ft_print_arg();
}
