/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapa_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:09:01 by isporras          #+#    #+#             */
/*   Updated: 2023/11/07 12:09:01 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//Chequea que solo haya caracteres admitidos.
/*int	ft_check_characters(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] != '0' && map[i] != '1' && map[i] != 'C'
			&& map[i] != 'E' && map[i] != 'P' && map[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}*/

//Chequea que haya un camino válido.
int	ft_check_way(char *map)
{
	char	**map2d;

	map2d = ft_split(map, '\n');
}

//Chequea que todas las líneas midan lo mismo.
int	ft_check_line_len(char *map)
{
	int	i;
	int	l_len;
	int	l_one;

	l_len = 0;
	l_one = 0;
	while (map[l_one] != '\0' && map[l_one] != '\n')
		l_one++;
	if (map[l_one] != '\0')
		i = l_one + 1;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
		{
			if (l_len != l_one)
				return (1);
			l_len = 0;
			i++;
		}
		i++;
		l_len++;
	}
	if (l_len != l_one)
		return (1);
	return (0);
}

//Chequea que el mapa esté totalmente delimitado por obstáculos (1).
int	ft_check_walls(char *map)
{
	int	i;
	int	total_ln;
	int	current_ln;

	current_ln = 1;
	total_ln = ft_count_lines(map);
	i = 0;
	while (map[i] != '\0')
	{
		if ((current_ln == 1 || current_ln == total_ln) 
			&& map[i] != '1' && map[i] != '\n')
			return (1);
		else if ((map[i] == '\n' && map[i + 1] != '1')
				|| (map[i + 1] == '\n' && map[i] != '1')
				|| (map[i + 1] == '\0' && map[i] != '1'))
			return (1);
		if (map[i] == '\n')
			current_ln++;
		i++;
	}
	return (0);
}

//Cheque que haya un p_inicial una salida y al menos un objeto.
int	ft_check_tokens(char *map)
{
	int	i;
	int	P;
	int	E;
	int	C;

	P = 0;
	E = 0;
	C = 0;
	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == 'P')
			P++;
		else if (map[i] == 'C')
			C++;
		else if (map[i] == 'E')
			E++;
		else if (map[i] != '0' && map[i] != '1' && map[i] != 'C'
			&& map[i] != 'E' && map[i] != 'P' && map[i] != '\n')
			return (1);
		i++;
	}
	if (P == 1 && E == 1 && C >= 1)
		return (0);
	else
		return (1);
}

//Checkea que el mapa cumpla los requisitos como mapa válido.
int	ft_check_map(char *map)
{
	if (ft_check_characters(map) + ft_check_line_len(map) + ft_check_walls(map)
		+ ft_check_tokens(map) > 0)
	{	
		write(1, "Error\n", 6);
		if (ft_check_characters(map) == 1)
			write(1, "Invalid character/s\n", 20);
		if (ft_check_line_len(map) == 1)
			write(1, "Invalid line length/s\n", 22);
		if (ft_check_walls(map) == 1)
			write(1, "Map is not closed by obstacles\n", 31);
		if (ft_check_tokens(map) == 1)
			write(1, "Map has no exit/initial pos/objects\n", 36);
		return (1);
	}
	return (0);
}