/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:09:21 by isporras          #+#    #+#             */
/*   Updated: 2023/11/01 13:44:48 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int main()
{
	void	*mlx_connection;
	void	*mlx_window;
	
	//inicializamos la conexion con el servidor xwindow
	mlx_connection = mlx_init();
	if (NULL == mlx_connection)
		return (1);
	mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "My Window");
	if (!mlx_window)
	{
		mlx_destroy_display(mlx_connection); //Cierra la conexion con el servidor.
		free(mlx_connection);
		return (1);
	}
	
}