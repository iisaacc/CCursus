/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_do.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:06:41 by isporras          #+#    #+#             */
/*   Updated: 2023/10/31 09:06:41 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

char	*ft_read(size_t bufsize)
{
	char	*buffer;
	char	*tmp;
	int		bytesread;

	tmp = ft_strdup("");
	buffer = ft_calloc(bufsize + 1, sizeof(char));
	bytesread = 1;
	while (bytesread > 0)
	{
		bytesread = read(0, buffer, bufsize);
		buffer[bytesread] = '\0';
		tmp = ft_strjoin(tmp, buffer);
		free(buffer);
		buffer = (char *)malloc(sizeof(char) * (bufsize + 1));
		if (!buffer)
			return (NULL);
	}
	free(buffer);
	return (tmp);
}

void	ft_switch(char *output, t_stack **a, t_stack **b)
{
	if (ft_strncmp(output, "pa", 2) == 0)
		ft_do_pa(a, b);
	else if (ft_strncmp(output, "pb", 2) == 0)
		ft_do_pb(a, b);
	else if (ft_strncmp(output, "sa", 2) == 0)
		ft_do_sa(a);
	else if (ft_strncmp(output, "sb", 2) == 0)
		ft_do_sb(b);
	else if (ft_strncmp(output, "ss", 2) == 0)
		ft_do_ss(a, b);
	else if (ft_strncmp(output, "ra", 2) == 0)
		ft_do_ra(a);
	else if (ft_strncmp(output, "rb", 2) == 0)
		ft_do_rb(b);
	else if (ft_strncmp(output, "rra", 3) == 0)
		ft_do_rra(a);
	else if (ft_strncmp(output, "rrb", 3) == 0)
		ft_do_rrb(b);
	else if (ft_strncmp(output, "rrr", 3) == 0)
		ft_do_rrr(a, b);
	else if (ft_strncmp(output, "rr", 2) == 0)
		ft_do_rr(a, b);
}

void	ft_do(char *output, t_stack **a, t_stack **b)
{
	while (output)
	{
		ft_switch(output, a, b);
		output = ft_strchr(output, '\n');
		if (output)
			output++;
	}
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

void	ft_set_index(t_stack **a)
{
	t_stack	*tmp_x;
	t_stack	*tmp_y;
	int		index;
	int		lower;

	index = 1;
	while (ft_checkindex(a) == 1)
	{
		tmp_x = *a;
		while (tmp_x)
		{
			lower = 0;
			tmp_y = *a;
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
