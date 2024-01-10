/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:54:16 by isporras          #+#    #+#             */
/*   Updated: 2024/01/10 11:53:44 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//void	ft_leaks(void)
//{
//	system("leaks philo");
//}

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
