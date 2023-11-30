/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:56:38 by isporras          #+#    #+#             */
/*   Updated: 2023/11/30 11:09:37 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	ft_dfs(char **mapcopy, int x, int y)
{
	int	i;
	int	xi[4];
	int	yi[4];

	xi[0] = 0;
	xi[1] = 1;
	xi[2] = 0;
	xi[3] = -1;
	yi[0] = -1;
	yi[1] = 0;
	yi[2] = 1;
	yi[3] = 0;
	if (mapcopy[y][x] == '1' || mapcopy[y][x] == 'V')
		return ;
	else
		mapcopy[y][x] = 'V';
	i = 0;
	while (i < 4)
	{
		ft_dfs(mapcopy, x + xi[i], y + yi[i]);
		i++;
	}
}

//Busco la primera posición válida para empezar el dfs.
void	ft_valid_pos(char **mapcopy, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (mapcopy[i])
	{
		j = 0;
		while (mapcopy[i][j])
		{
			if (mapcopy[i][j] != '1')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	ft_parse_dfs(char **mapcpy)
{
	int	i;
	int	j;

	i = 0;
	while (mapcpy[i])
	{
		j = 0;
		while (mapcpy[i][j])
		{
			if (mapcpy[i][j] != 'V' && mapcpy[i][j] != '1'
				&& mapcpy[i][j] != '0')
				return (1);
			j++;
		}
		i++;
	}
	while (i >= 0)
	{
		free(mapcpy[i]);
		i--;
	}
	free(mapcpy);
	return (0);
}

//Chequea que haya un camino válido.
int	ft_check_way(char *map)
{
	char	**mapcopy;
	int		x;
	int		y;

	x = 0;
	y = 0;
	mapcopy = ft_split(map, '\n');
	ft_valid_pos(mapcopy, &x, &y);
	ft_dfs(mapcopy, x, y);
	return (ft_parse_dfs(mapcopy));
}
