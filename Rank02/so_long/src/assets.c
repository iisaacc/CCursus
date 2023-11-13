/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:17:32 by isporras          #+#    #+#             */
/*   Updated: 2023/11/09 13:17:32 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_img	*ft_load_assets(t_data *data)
{
	int		w;
	int		h;

	printf("cargando assets\n");
	if (!data->mlx_ptr || !data->win_ptr)
		return (NULL);
	data->img->back = mlx_xpm_file_to_image(data->mlx_ptr, BCKGRND, &w, &h);
	data->img->player = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER, &w, &h);
	data->img->playerl = mlx_xpm_file_to_image(data->mlx_ptr, PLAYERL, &w, &h);
	data->img->police = mlx_xpm_file_to_image(data->mlx_ptr, POLICE, &w, &h);
	data->img->speaker = mlx_xpm_file_to_image(data->mlx_ptr, SPEAKER, &w, &h);
	data->img->exit = mlx_xpm_file_to_image(data->mlx_ptr, EXIT, &w, &h);
	if (!data->img->back || !data->img->player || !data->img->police
		|| !data->img->speaker || !data->img->exit || !data->img->playerl)
		return (NULL);
	return (data->img);
}

void	ft_put_background(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < data->map->heigth)
	{
		while (x < data->map->width)
		{
			img_win(data, data->img->back, x, y);
			x += 32;
		}
		x = 0;
		y += 32;
	}
}

void	ft_put_player(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map->heigth)
	{
		while (x < data->map->width)
		{
			if (data->map->map[y / 32][x / 32] == 'P')
			{
				img_win(data, data->img->player, x, y);
				data->map->px = x;
				data->map->py = y;
			}
			x += 32;
		}
		x = 0;
		y += 32;
	}
}

void	ft_put_objects(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map->heigth)
	{
		while (x < data->map->width)
		{
			if (data->map->map[y / 32][x / 32] == '1')
				img_win(data, data->img->police, x, y);
			if (data->map->map[y / 32][x / 32] == 'C')
				img_win(data, data->img->speaker, x, y);
			if (data->map->map[y / 32][x / 32] == 'E')
				img_win(data, data->img->exit, x, y);
			x += 32;
		}
		x = 0;
		y += 32;
	}
}

void	ft_load_put_assets(t_data *data)
{
	if (ft_load_assets(data) == NULL)
		dstry(data);
	ft_put_background(data);
	ft_put_objects(data);
	ft_put_player(data);
}
