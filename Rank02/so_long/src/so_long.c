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

int main(int argc, char *argv[])
{
	char	*map;
	
	if (argc == 1)
	{
		printf("Introduce el nombre del archivo de mapa");
		return (1);
	}
	//Leo el archivo de mapa especificado en el primer argumento y lo almaceno en un buffer
	map = ft_read_fd(open(argv[1], O_RDONLY));
	printf("mapa:\n%s\n",map);
	ft_check_map(map);
	return (0);
}