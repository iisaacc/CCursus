/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:02:15 by isporras          #+#    #+#             */
/*   Updated: 2023/11/30 10:59:26 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_mv_r(t_data *data)
{
	if (data->map->map[data->map->py / 32][(data->map->px + 32) / 32] != '1')
	{
		if (data->map->map[data->map->py / 32][data->map->px / 32 + 1] == 'C')
		{
			data->collectibles--;
			data->map->map[data->map->py / 32][(data->map->px + 32) / 32] = '0';
		}
		if (data->map->map[data->map->py / 32][(data->map->px + 32) / 32] == 'E'
			&& data->collectibles == 0)
			ft_on_win(data);
		if (data->map->map[data->map->py / 32][data->map->px / 32] == 'E')
			img_win(data, data->img->extu, data->map->px, data->map->py);
		else
			img_win(data, data->img->back, data->map->px, data->map->py);
		data->map->px += 32;
		img_win(data, data->img->player, data->map->px, data->map->py);
		data->movements++;
	}
}

void	ft_mv_l(t_data *data)
{
	if (data->map->map[data->map->py / 32][(data->map->px - 32) / 32] != '1')
	{
		if (data->map->map[data->map->py / 32][data->map->px / 32 - 1] == 'C')
		{
			data->collectibles--;
			data->map->map[data->map->py / 32][(data->map->px - 32) / 32] = '0';
		}
		if (data->map->map[data->map->py / 32][(data->map->px - 32) / 32] == 'E'
			&& data->collectibles == 0)
			ft_on_win(data);
		if (data->map->map[data->map->py / 32][data->map->px / 32] == 'E')
			img_win(data, data->img->extu, data->map->px, data->map->py);
		else
			img_win(data, data->img->back, data->map->px, data->map->py);
		data->map->px -= 32;
		img_win(data, data->img->playerl, data->map->px, data->map->py);
		data->movements++;
	}
}

void	ft_mv_u(t_data *data)
{
	if (data->map->map[(data->map->py - 32) / 32][data->map->px / 32] != '1')
	{
		if (data->map->map[data->map->py / 32 - 1][data->map->px / 32] == 'C')
		{
			data->collectibles--;
			data->map->map[(data->map->py - 32) / 32][data->map->px / 32] = '0';
		}
		if (data->map->map[(data->map->py - 32) / 32][data->map->px / 32] == 'E'
			&& data->collectibles == 0)
			ft_on_win(data);
		if (data->map->map[(data->map->py) / 32][data->map->px / 32] == 'E')
			img_win(data, data->img->extu, data->map->px, data->map->py);
		else
			img_win(data, data->img->back, data->map->px, data->map->py);
		data->map->py -= 32;
		img_win(data, data->img->player, data->map->px, data->map->py);
		data->movements++;
	}
}

void	ft_mv_d(t_data *data)
{
	if (data->map->map[(data->map->py + 32) / 32][data->map->px / 32] != '1')
	{
		if (data->map->map[data->map->py / 32 + 1][data->map->px / 32] == 'C')
		{
			data->collectibles--;
			data->map->map[(data->map->py + 32) / 32][data->map->px / 32] = '0';
		}
		if (data->map->map[(data->map->py + 32) / 32][data->map->px / 32] == 'E'
			&& data->collectibles == 0)
			ft_on_win(data);
		if (data->map->map[(data->map->py) / 32][data->map->px / 32] == 'E')
			img_win(data, data->img->extu, data->map->px, data->map->py);
		else
			img_win(data, data->img->back, data->map->px, data->map->py);
		data->map->py += 32;
		img_win(data, data->img->player, data->map->px, data->map->py);
		data->movements++;
	}
}

void	ft_move_object(t_data *data, int dir)
{
	if (data->lost == 0)
	{
		if (dir == RIGHT)
			ft_mv_r(data);
		if (dir == LEFT)
			ft_mv_l(data);
		if (dir == UP)
			ft_mv_u(data);
		if (dir == DOWN)
			ft_mv_d(data);
	}
}
