/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:54:16 by isporras          #+#    #+#             */
/*   Updated: 2023/11/22 12:05:39 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_arg(void)
{
	printf("Introduce at least 4 arguments especifying:\n");
	printf("- Number of philosophers\n");
	printf("- Time to die\n");
	printf("- Time to eat\n");
	printf("- Time to sleep\n");
	printf("- Number of times each philosopher must eat to \"win\" (OPTIONAL)\n");
}

int	main(int argc, char **argv)
{
	t_philo	ph[200];

	if (argc == 5 || argc == 6)
	{
		ft_init(ph, argv, argc);
	}
	else
		ft_print_arg();
	return (0);
}