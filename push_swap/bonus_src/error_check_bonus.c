/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:28:47 by isporras          #+#    #+#             */
/*   Updated: 2023/10/30 12:28:47 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

//Devuelve 1 si encuentra un carácter no numérico.
int	ft_check_char(int argc, char **argv)
{
	int	i;
	int	i2;

	i2 = 0;
	i = 1;
	while (i < argc)
	{
		while (argv[i][i2])
		{
			if ((argv[i][i2] < '0' || argv[i][i2] > '9') && argv[i][i2] != '-')
				return (1);
			i2++;
		}
		i++;
		i2 = 0;
	}
	return (0);
}

//Devuelve 1 si encuentra valores duplicados
int	ft_check_doubles(int argc, int *stack_a)
{
	int	i;
	int	i2;

	i = 0;
	while (i < argc - 1)
	{
		i2 = 1;
		while (i + i2 < argc - 1)
		{
			if (stack_a[i] == stack_a[i + i2])
				return (1);
			i2++;
		}
		i++;
	}
	return (0);
}

//Devuelve 1 si algún valor supera el rango de int
int	ft_check_range(int argc, int *stack_a)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (stack_a[i] < -2147483647 || stack_a[i] > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

int	ft_correct_input(char *output)
{
	while (output)
	{
		if (ft_strncmp(output, "pa", 2) == 0 
			|| ft_strncmp(output, "pb", 2) == 0
			|| ft_strncmp(output, "sa", 2) == 0
			|| ft_strncmp(output, "sa", 2) == 0
			|| ft_strncmp(output, "sb", 2) == 0
			|| ft_strncmp(output, "ss", 2) == 0
			|| ft_strncmp(output, "ra", 2) == 0
			|| ft_strncmp(output, "rb", 2) == 0
			|| ft_strncmp(output, "rra", 3) == 0
			|| ft_strncmp(output, "rrb", 3) == 0
			|| ft_strncmp(output, "rrr", 3) == 0
			|| ft_strncmp(output, "rr", 2) == 0)
			output = ft_strchr(output, '\n');
		else
			return (1);
		if (output)
			output++;
	}
	return (0);
}

//Llama a todos los checks y devuelve 0 en caso de no haber ningun error
int	ft_check_errors(int argc, char **argv, int *stack_a)
{
	return (ft_check_char(argc, argv)
		+ ft_check_doubles(argc, stack_a) + ft_check_range(argc, stack_a));
}
