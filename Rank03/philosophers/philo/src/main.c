/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:54:16 by isporras          #+#    #+#             */
/*   Updated: 2023/12/14 13:21:41 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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
