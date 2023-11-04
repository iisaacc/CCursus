/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_atributes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:14:27 by isporras          #+#    #+#             */
/*   Updated: 2023/10/30 11:14:27 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_stacksize(t_stack **stack_a)
{
	t_stack	*tmp;
	int		x;

	x = 0;
	tmp = *stack_a;
	while (tmp->next)
	{
		x++;
		tmp = tmp->next;
	}
	x++;
	return (x);
}

int	ft_checkindex(t_stack **stack_a)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack_a;
	i = 0;
	while (tmp->next)
	{
		if (tmp->index == -1)
			i = 1;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_set_index(t_stack **stack_a)
{
	t_stack	*tmp_x;
	t_stack	*tmp_y;
	int		index;
	int		lower;

	index = 1;
	while (ft_checkindex(stack_a) == 1)
	{
		tmp_x = *stack_a;
		while (tmp_x)
		{
			lower = 0;
			tmp_y = *stack_a;
			while (tmp_y)
			{
				if (tmp_x->value > tmp_y->value && tmp_y->index == -1)
					lower = 1;
				tmp_y = tmp_y->next;
			}
			if (lower == 0 && tmp_x->index == -1)
				tmp_x->index = index++;
			tmp_x = tmp_x->next;
		}
	}
}
