#include "../../includes/cub3d.h"

char	**ft_get_map(char **split_input)
{
	int	i;
	int	j;

	i = 0;
	while (split_input[i])
	{
		j = 0;
		while (split_input[i][j] == ' ')
				j++;
		if (split_input[i][j] && split_input[i][j] != '\n' &&
			ft_strncmp(&split_input[i][j], "NO ", 3) != 0 &&
			ft_strncmp(split_input[i], "SO ", 3) != 0 &&
			ft_strncmp(split_input[i], "WE ", 3) != 0 &&
			ft_strncmp(split_input[i], "EA ", 3) != 0 &&
			ft_strncmp(split_input[i], "F ", 2) != 0 &&
			ft_strncmp(split_input[i], "C ", 2) != 0)
			return (&split_input[i]);
		i++;
	}
	return (ft_error_msg("No map found", NULL), NULL);
}

void	ft_parser(char	*file, t_cub *cub)
{

	cub->split_input = ft_read_and_split(file);
	ft_checks(cub);
	//ft_checks(split_input);
	//cub->tx = ft_init_lst_textures(split_input);
	//ft_conf_elements(split_input);
}