/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:01:28 by isporras          #+#    #+#             */
/*   Updated: 2023/11/14 15:44:37 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
//# include <X11/X.h>
//# include <X11/keysym.h>
# include <time.h>

# define WIDTH 512
# define HEIGTH 512
# define TILE_SIZE_X 32
# define TILE_SIZE_Y 32
# define UP 1
# define DOWN -1
# define RIGHT 2
# define LEFT -2
# define BCKGRND "assets/back.xpm"
# define PLAYER "assets/Wright.xpm"
# define PLAYERL "assets/Wleft.xpm"
# define POLICE "assets/police.xpm"
# define SPEAKER "assets/speaker.xpm"
# define EXTD "assets/extd.xpm"
# define EXTU "assets/extu.xpm"
# define BOX "assets/box.xpm"

typedef struct s_img
{
	void	*police;
	void	*back;
	void	*speaker;
	void	*extu;
	void	*extd;
	void	*player;
	void	*playerl;
	void	*box;
}	t_img;

typedef struct s_map
{
	char	**map;
	int		width;
	int		heigth;
	int		px;
	int		py;
}	t_map;

typedef struct s_spr
{
	time_t	updttime;
	int		state;
}	t_spr;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		movements;
	int		collectibles;
	char	*map1d;
	t_img	*img;
	t_map	*map;
	t_spr	*spr;
	int		ex;
	int		ey;
	int		lost;
}	t_data;

char	*ft_read_map(char *argv);
int		ft_check_map(char *map);
int		ft_check_way(char *map);
void	*ft_mlxwin_init(t_data *data);
void	*ft_mlxptr_init(t_data *data);
int		dstry(t_data *data);
int		ft_on_kpress(int keysym, t_data *data);
void	ft_load_put_assets(t_data *data);
void	*ft_init(t_data *data, char *map);
void	ft_mlx_hooks(t_data *data);
void	ft_move_object(t_data *data, int dir);
void	img_win(t_data *data, void *img, int x, int y);
char	*ft_strjoinmod(char *line, char *buffer);
void	ft_on_lost(t_data *data);
void	ft_on_win(t_data *data);
#endif