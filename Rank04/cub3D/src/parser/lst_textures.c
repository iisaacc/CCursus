#include "../../includes/cub3d.h"

void	ft_set_textures(char *dir, char **split_input)
{
	int	i;
	int	j;

	i = 0;
	while (split_input[i])
	{
		if (ft_strncmp(dir, split_input[i], 3))
		i++;
	}
}

t_tx	**ft_init_lst_textures(char	**split_input);