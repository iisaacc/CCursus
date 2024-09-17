/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:37:43 by isporras          #+#    #+#             */
/*   Updated: 2023/10/30 13:37:43 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

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

//Coge el array de argumentos y lo convierte en un array de enteros
int	*ft_argvtoint(int argc, char **argv)
{
	int		*stack;
	int		i;
	long	num;

	i = 0;
	stack = ft_calloc((argc - 1), sizeof(int));
	while (i < argc - 1)
	{
		num = ft_atoi_mod(argv[i + 1]);
		if (num < -2147483648 || num > 2147483647)
			return (NULL);
		else
			stack[i] = (int)num;
		i++;
	}
	return (stack);
}

void	ft_free(t_stack **a, t_stack **b, int *stack_a)
{
	t_stack	*tmpa;
	t_stack	*tmpb;
	t_stack	*aux;

	aux = NULL;
	tmpa = *a;
	tmpb = *b;
	while (tmpa)
	{
		aux = tmpa;
		tmpa = tmpa->next;
		free(aux);
	}
	while (tmpb)
	{
		aux = tmpb;
		tmpb = tmpb->next;
		free(aux);
	}
	free(stack_a);
}
