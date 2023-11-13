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

char	*ft_read_map(char *argv)
{
	char	*map1d;
	int		i;
	int		fd;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == '.' && ft_strncmp(argv + i, ".ber", 4) != 0)
			return (NULL);
		i++;
	}
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map1d = ft_read_fd(fd);
	if (*map1d == '\0')
	{
		free(map1d);
		return (NULL);
	}
	else
		return (map1d);
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
	int	p;
	int	e;
	int	c;

	p = 0;
	e = 0;
	c = 0;
	while (*map != '\0')
	{
		if (*map == 'P')
			p++;
		else if (*map == 'C')
			c++;
		else if (*map == 'E')
			e++;
		else if (*map != '0' && *map != '1' && *map != 'C'
			&& *map != 'E' && *map != 'P' && *map != '\n')
			return (1);
		map++;
	}
	if (p == 1 && e == 1 && c >= 1)
		return (0);
	return (1);
}

//Checkea que el mapa cumpla los requisitos como mapa válido.
int	ft_check_map(char *map)
{
	if (ft_check_line_len(map) + ft_check_walls(map) + ft_check_tokens(map) > 0)
	{
		write(1, "Error\n", 6);
		if (ft_check_line_len(map) == 1)
			write(1, "Invalid line length/s\n", 22);
		if (ft_check_walls(map) == 1)
			write(1, "Map is not closed by obstacles\n", 31);
		if (ft_check_tokens(map) == 1)
			write(1, "Map has invalid tokens or there is some missing\n", 48);
		return (1);
	}
	else if (ft_check_way(map) > 0)
	{
		ft_printf("Map has no valid way\n");
		return (1);
	}
	return (0);
}
