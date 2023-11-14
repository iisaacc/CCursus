/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:14:46 by isporras          #+#    #+#             */
/*   Updated: 2023/10/30 11:14:46 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_finish_it(t_stack **a)
{
	while ((*a)->index != 1)
		ft_do_rra(a);
}

//Crea un nuevo nodo de la lista y lo inicializa
t_stack	*ft_stacklstnewnode(int value, int pos)
{
	struct s_stack	*newobj;

	newobj = (t_stack *)malloc(sizeof(struct s_stack));
	if (!newobj)
		return (NULL);
	newobj->value = value;
	newobj->pos = pos;
	newobj->target_pos = -1;
	newobj->index = -1;
	newobj->cost_a = -1;
	newobj->cost_b = -1;
	newobj->next = NULL;
	return (newobj);
}

int	main(int argc, char **argv)
{
	int		*stack_a;
	t_stack	*list_a;
	t_stack	*list_b;

	list_a = NULL;
	list_b = NULL;
	stack_a = ft_argvtoint(argc, argv);
	if (ft_check_errors(argc, argv, stack_a) == 0 && argc > 2)
	{
		ft_arraytolist(&list_a, stack_a, argc - 1);
		ft_set_index(&list_a);
		if (argc == 3)
			ft_sort_2(&list_a);
		else if (argc == 4)
			ft_sort_3(&list_a);
		else
			ft_bigsort(&list_a, &list_b);
	}
	ft_free(&list_a, &list_b, stack_a);
	return (0);
}
