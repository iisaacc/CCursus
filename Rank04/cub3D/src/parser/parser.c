#include "../../includes/cub3d.h"

char	**ft_get_map(char **split_input)
{
	
}

void	ft_parser(char	*file, t_cub *cub)
{
	char	**split_input;

	cub->split_input = ft_read_and_split(file);
	ft_print_split(cub->split_input);
	ft_checks(cub->split_input);
	//ft_checks(split_input);
	//cub->tx = ft_init_lst_textures(split_input);
	//ft_conf_elements(split_input);
}