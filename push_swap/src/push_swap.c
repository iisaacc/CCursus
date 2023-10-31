/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:02:11 by isporras          #+#    #+#             */
/*   Updated: 2023/05/21 13:02:11 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Coge el array de argumentos y lo convierte en un array de enteros
int	*ft_argvtoint(int argc, char **argv)
{
	int	*stack;
	int	i;

	i = 0;
	stack = ft_calloc((argc - 1),sizeof(int));
	while (i < argc - 1)
	{
		stack[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (stack);
}

void	ft_free(t_stack **a, t_stack **b,int *stack_a)
{
	t_stack *tmpa;
	t_stack *tmpb;
	t_stack *aux;

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