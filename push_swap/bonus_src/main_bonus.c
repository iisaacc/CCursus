/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:29:07 by isporras          #+#    #+#             */
/*   Updated: 2023/10/30 12:29:07 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	main(int argc, char **argv)
{
	int		*stack_a;
	t_stack	*list_a;
	t_stack	*list_b;
	char	*output;

	list_a = NULL;
	list_b = NULL;
	stack_a = ft_argvtoint(argc, argv);
	if(ft_check_errors(argc, argv, stack_a) > 0)
		write(1, "Error\n", 6);
	else
	{
		ft_arraytolist(&list_a, stack_a, argc - 1);
		ft_read_and_do(&list_a, &list_b);
	}
	ft_free(&list_a, &list_b, stack_a);
	return (0);
}