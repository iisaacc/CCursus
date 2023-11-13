/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:40:21 by isporras          #+#    #+#             */
/*   Updated: 2023/11/07 11:40:21 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strjoinmod(char *line, char *buffer)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = ft_calloc((ft_strlen(line) + ft_strlen(buffer) + 1), sizeof(char));
	i = 0;
	j = 0;
	while (line && line[i])
	{
		str[j++] = line[i];
		i++;
	}
	i = 0;
	while (buffer[i])
	{
		str[j++] = buffer[i];
		i++;
	}
	free(buffer);
	str[j] = 0;
	return (str);
}

void	ft_on_lost(t_data *data)
{
	printf("GAME OVER! PRESS ESC TO EXIT\n");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, data->map->heigth + 20,
		0x00FFFFFF, "GAME OVER!");
	data->lost = 1;
}

void	ft_on_win(t_data *data)
{
	printf("YOU WIN! PRESS ESC TO EXIT.\n");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, data->map->heigth + 20,
		0x00FFFFFF, "YOU WIN!");
	data->lost = 1;
}

int	ft_errorcase(void)
{
	ft_printf("Error\n");
	ft_printf("Introduce a single argument with a valid .ber map file.\n");
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_img	img;
	t_map	map;
	t_spr	spr;

	data.spr = &spr;
	data.img = &img;
	data.map = &map;
	data.map1d = ft_read_map(argv[1]);
	if (argc == 2 && data.map1d)
	{
		if (ft_check_map(data.map1d) == 1)
			return (free(data.map1d), 1);
		if (ft_init(&data, data.map1d) == NULL)
			return (dstry(&data), 1);
		ft_load_put_assets(&data);
		ft_mlx_hooks(&data);
		mlx_loop(data.mlx_ptr);
		return (0);
	}
	else
		return (ft_errorcase());
}
