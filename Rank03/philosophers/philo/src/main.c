/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:54:16 by isporras          #+#    #+#             */
/*   Updated: 2024/01/16 13:52:43 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//void	ft_leaks(void)
//{
//	system("leaks philo");
//}
int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = ft_time();
	while ((ft_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	ph[200];

	if ((argc == 5 || argc == 6) && ft_check_argv(argv) == 0)
	{
		ft_init(ph, argv, argc);
		ft_clean(ph);
	}
	else
		ft_print_arg();
	return (0);
}
