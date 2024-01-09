/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:05:09 by isporras          #+#    #+#             */
/*   Updated: 2024/01/09 17:31:56 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_leaks(void)
{
	system("leaks philo_bonus");
}

int	main(int argc, char **argv)
{
	atexit(ft_leaks);
	t_philo	ph[200];

	sem_unlink("/sema");
	if ((argc == 5 || argc == 6) && ft_check_argv(argv) == 0)
		ft_init(ph, argv, argc);
	else
		ft_print_arg();
}