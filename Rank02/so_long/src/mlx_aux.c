/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:09:03 by isporras          #+#    #+#             */
/*   Updated: 2023/11/09 11:09:03 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	img_win(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		img, x, y);
}

void	*ft_mlxptr_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_printf("Error\n");
		ft_printf("Couldn't connect to graphic server\n");
		exit(1);
	}
	return (data->mlx_ptr);
}

void	*ft_mlxwin_init(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->map->width, data->map->heigth + 32, "VENTANICA");
	if (!data->win_ptr)
		return (free(data->mlx_ptr), NULL);
	return (data->win_ptr);
}

int	ft_find_collectibles(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	data->collectibles = 0;
	while (y < data->map->heigth)
	{
		while (x < data->map->width)
		{
			if (data->map->map[y / 32][x / 32] == 'C')
				data->collectibles++;
			x += 32;
		}
		x = 0;
		y += 32;
	}
	return (data->collectibles);
}

void	*ft_init(t_data *data, char *map)
{
	char	**map2d;

	map2d = ft_split(map, '\n');
	data->map->map = map2d;
	data->map->width = ft_strlen(map2d[0]) * 32;
	data->map->heigth = ft_count_lines2d(map2d) * 32;
	data->movements = 0;
	data->spr->state = 1;
	data->spr->updttime = time(NULL);
	data->collectibles = ft_find_collectibles(data);
	data->mlx_ptr = ft_mlxptr_init(data);
	data->lost = 0;
	if (!data->mlx_ptr)
		return (NULL);
	data->win_ptr = ft_mlxwin_init(data);
	if (!data->win_ptr)
		return (NULL);
	return (data->mlx_ptr);
}
