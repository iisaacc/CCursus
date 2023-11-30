/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:07:13 by isporras          #+#    #+#             */
/*   Updated: 2023/11/30 11:09:40 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_sprite(t_data *data)
{
	time_t	ct;

	ct = time(NULL);
	if (ct - data->spr->updttime >= 0.1)
	{
		if (data->spr->state == 1)
		{
			img_win(data, data->img->extd, data->ex, data->ey);
			data->spr->state = 0;
		}
		else
		{
			img_win(data, data->img->extu, data->ex, data->ey);
			data->spr->state = 1;
		}
		mlx_do_sync(data->mlx_ptr);
		data->spr->updttime = ct;
	}
	mlx_loop_hook(data->mlx_ptr, &ft_sprite, data);
	return (0);
}

void	ft_dstry_img(t_data *data)
{
	if (data->img->back)
		mlx_destroy_image(data->mlx_ptr, data->img->back);
	if (data->img->player)
		mlx_destroy_image(data->mlx_ptr, data->img->player);
	if (data->img->playerl)
		mlx_destroy_image(data->mlx_ptr, data->img->playerl);
	if (data->img->police)
		mlx_destroy_image(data->mlx_ptr, data->img->police);
	if (data->img->speaker)
		mlx_destroy_image(data->mlx_ptr, data->img->speaker);
	if (data->img->extu)
		mlx_destroy_image(data->mlx_ptr, data->img->extu);
	if (data->img->extd)
		mlx_destroy_image(data->mlx_ptr, data->img->extd);
	if (data->img->box)
		mlx_destroy_image(data->mlx_ptr, data->img->box);
}

int	dstry(t_data *data)
{
	ft_dstry_img(data);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		free(data->mlx_ptr);
	while (data->map->heigth > 0
		&& data->map->map[(data->map->heigth / 32) - 1])
	{
		free(data->map->map[(data->map->heigth / 32) - 1]);
		data->map->heigth -= 32;
	}
	if (data->map->map)
		free(data->map->map);
	if (data->map1d)
		free(data->map1d);
	exit(0);
	return (0);
}

int	ft_on_kpress(int keysym, t_data *data)
{
	char	*str;

	(void)data;
	if (keysym == 53)
		dstry(data);
	if (keysym == 0)
		ft_move_object(data, LEFT);
	if (keysym == 2)
		ft_move_object(data, RIGHT);
	if (keysym == 13)
		ft_move_object(data, UP);
	if (keysym == 1)
		ft_move_object(data, DOWN);
	img_win(data, data->img->box, 0, data->map->heigth);
	str = ft_strjoinmod("Movements: ", ft_itoa(data->movements));
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, data->map->heigth + 20,
		0x00FFFFFF, str);
	free(str);
	return (0);
}

void	ft_mlx_hooks(t_data *data)
{
	mlx_hook(data->win_ptr, 3, 2, &ft_on_kpress, data);
	mlx_hook(data->win_ptr, 17, 1 << 17, &dstry, data);
	mlx_loop_hook(data->mlx_ptr, &ft_sprite, data);
}
