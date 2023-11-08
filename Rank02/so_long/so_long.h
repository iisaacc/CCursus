#ifndef SO_LONG_H
# define SO_LONG_H

#include "./minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 400
#define HEIGHT 400

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}t_mlx_data;

char	*ft_read_map(char *mapname);
int		ft_check_map(char *map);
#endif