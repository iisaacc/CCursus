/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:07:13 by isporras          #+#    #+#             */
/*   Updated: 2023/11/09 17:07:13 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	if (data->img->exit)
		mlx_destroy_image(data->mlx_ptr, data->img->exit);
}

int	dstry(t_data *data)
{
	ft_dstry_img(data);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
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
	(void)data;
	if (keysym == XK_Escape)
		dstry(data);
	if (keysym == XK_a)
		ft_move_object(data, LEFT);
	if (keysym == XK_d)
		ft_move_object(data, RIGHT);
	if (keysym == XK_w)
		ft_move_object(data, UP);
	if (keysym == XK_s)
		ft_move_object(data, DOWN);
	return (0);
}

void	ft_mlx_hooks(t_data *data)
{
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &ft_on_kpress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &dstry, data);
}
