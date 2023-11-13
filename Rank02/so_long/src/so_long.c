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

int	main(int argc, char *argv[])
{
	t_data	data;
	t_img	img;
	t_map	map;

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
	{
		ft_printf("Error\n");
		ft_pintf("Introduce a single argument with a valid .ber map file.\n");
		return (1);
	}
}
