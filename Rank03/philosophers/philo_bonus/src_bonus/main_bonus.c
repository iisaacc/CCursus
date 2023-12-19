/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:05:09 by isporras          #+#    #+#             */
/*   Updated: 2023/12/14 13:05:11 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	main(int argc, char **argv)
{
	t_philo	ph[200];

	sem_unlink("/sema");
	if ((argc == 5 || argc == 6) && ft_check_argv(argv) == 0)
	{
		ft_init(ph, argv, argc);
		sem_unlink("/sema");
	}
	else
		ft_print_arg();
}