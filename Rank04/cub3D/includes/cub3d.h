#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 64
#endif

//Guarda los datos sobre las texturas
typedef struct s_tx
{
	char		*path;
	char		*dir;
	struct s_tx	*next;
}	t_tx;

//Guarda los datos principales del juego
typedef struct s_cub
{
	t_tx	**tx;
	char	**map;
	char	**split_input;
}	t_cub;

//------------------PARSER--------------------------
void	ft_parser(char	*file, t_cub *cub);
char	*get_next_line(int fd);
void	ft_error_msg(char *s1, char *s2);
char	**ft_read_and_split(char *file);
char	**ft_get_map(char **split_input);
int		ft_checks(t_cub *cub);
int		ft_check_way(char **map);
void	ft_cut_char(char **str, char c);

#endif