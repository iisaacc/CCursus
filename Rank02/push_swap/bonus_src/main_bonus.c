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

void	ft_is_ordered(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	ft_set_index(a);
	tmp = *a;
	while (tmp)
	{
		if (tmp->index != i)
		{
			write(1, "KO\n", 3);
			return ;
		}
		tmp = tmp->next;
		i++;
	}
	if (*b)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

void	ft_read_and_do(t_stack **a, t_stack **b)
{
	char *output;

	output = ft_read(1024);
	if (ft_correct_input(output) == 1)
	{
		write(2, "Error\n", 6);
		return ;
	}
	ft_do(output, a, b);
	ft_is_ordered(a, b);
	free(output);
}

int	main(int argc, char **argv)
{
	int		*stack_a;
	t_stack	*list_a;
	t_stack	*list_b;

	list_a = NULL;
	list_b = NULL;
	stack_a = ft_argvtoint(argc, argv);
	if(argc > 1)
	{
		if (ft_check_errors(argc, argv, stack_a) > 0)
			write(2, "Error\n", 6);
		else
		{
			ft_arraytolist(&list_a, stack_a, argc - 1);
			ft_read_and_do(&list_a, &list_b);
		}
	}
	ft_free(&list_a, &list_b, stack_a);
	return (0);
}
