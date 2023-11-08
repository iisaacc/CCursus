/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_tutorial.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:09:21 by isporras          #+#    #+#             */
/*   Updated: 2023/11/07 11:45:31 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int main()
{
	t_mlx_data data;
	
	//inicializamos la conexion con el servidor xwindow
	data.mlx_ptr = mlx_init();
	if (NULL == data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "My Window");
	if (!data.win_ptr)
	{
		mlx_destroy_display(data.mlx_ptr); //Cierra la conexion con el servidor.
		free(data.mlx_ptr);
		return (1);
	}
	mlx_loop(data.mlx_ptr);//Mantiene la ventana abierta
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}