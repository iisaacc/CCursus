/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:54:16 by isporras          #+#    #+#             */
/*   Updated: 2023/12/05 16:43:01 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	ph[200];

	if (argc == 5 || argc == 6)
	{
		ft_init(ph, argv, argc);
		ft_clean(ph);
	}
	else
		ft_print_arg();
	return (0);
}
