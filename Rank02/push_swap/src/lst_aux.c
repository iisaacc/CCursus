/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:23:29 by isporras          #+#    #+#             */
/*   Updated: 2023/05/21 16:23:29 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Devuelve el último nodo de la lista
t_stack	*ft_stacklstlast(t_stack **lst)
{
	t_stack	*last;

	last = *lst;
	while (last->next)
		last = last->next;
	return (last);
}

//Añade un nuevo nodo al final de la lista
void	ft_stacklstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!lst)
		lst = &new;
	else
	{
		last = ft_stacklstlast(lst);
		last->next = new;
	}
}

void	ft_stacklstadd_front(t_stack **lst, t_stack *new)
{
	t_stack	*first;

	if (!lst)
		lst = &new;
	else
	{
		first = *lst;
		*lst = new;
		new->next = first;
	}
}

//Convierte un array de enteros en una lista de nodos
void	ft_arraytolist(t_stack **stack, int *array, int len)
{
	int		i;
	t_stack	*node;

	node = ft_stacklstnewnode(array[0], 0);
	*stack = node;
	i = 1;
	while (i < len)
	{
		ft_stacklstadd_back(stack, ft_stacklstnewnode(array[i], i));
		i++;
	}
}

t_stack	*ft_onebeforelast(t_stack **lst)
{
	t_stack	*nolast;

	nolast = *lst;
	while ((nolast->next)->next)
		nolast = nolast->next;
	return (nolast);
}

/*void ft_print_stack(t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	printf("STACK:\n");
	while (tmp)
	{
		printf("VALUE: %d, pos: %d, target_pos: %d, index: %d,
		cost_a: %d, cost_b: %d\n", tmp->value, tmp->pos, tmp->target_pos,
		tmp->index, tmp->cost_a, tmp->cost_b);
		tmp = tmp->next;
	}
}*/
