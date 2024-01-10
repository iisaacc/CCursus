/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:48:18 by isporras          #+#    #+#             */
/*   Updated: 2024/01/10 18:21:27 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

long	ft_atolong(const char *str)
{
	long	n;
	int		sign;
	int		i;

	i = 0;
	n = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * sign);
}

int	ft_check_int(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_max_ph(char **argv)
{
	if (ft_atolong(argv[1]) > 200 || ft_atolong(argv[1]) < 1)
		return (1);
	else
		return (0);
}

int	ft_int_range(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atolong(argv[i]) > 2147483647
			|| ft_atolong(argv[i]) < 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_argv(char **argv)
{
	if (ft_check_int(argv) == 0)
		return (1);
	if (ft_int_range(argv) == 1 || ft_check_max_ph(argv) == 1)
		return (1);
	return (0);
}
