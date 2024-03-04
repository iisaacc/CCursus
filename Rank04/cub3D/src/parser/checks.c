#include "../../includes/cub3d.h"


int	ft_valid_elements(char **split_input)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (split_input[i])
	{
		if (ft_strncmp(split_input[i], "NO ", 3) == 0 ||
			ft_strncmp(split_input[i], "SO ", 3) == 0 ||
			ft_strncmp(split_input[i], "WE ", 3) == 0 ||
			ft_strncmp(split_input[i], "EA ", 3) == 0 ||
			ft_strncmp(split_input[i], "F ", 2) == 0 ||
			ft_strncmp(split_input[i], "C ", 2) == 0 )
			count++;
		else if (split_input[i][0] != '\n' && count != 6)
			return (ft_error_msg("Strange element before textures definitions: ", split_input[i]), 1);
		i++;
	}
	return (0);
}

int	ft_check_walls(char **split_input)
{
	int	i;
	int	j;

	i = 0;
	while (split_input[i])
	{
		j = 0;
		while (split_input[i][j])
		{
			while (split_input[i][j] && (split_input[i][j] == '\n' || split_input[i][j] == ' ' || split_input[i][j] == 9))
				j++;
			printf("split_input[i][j]: %c\n", split_input[i][j]);
			printf("split_input[i][ft_strlen(split_input[i]) - 1]: %c\n", split_input[i][ft_strlen(split_input[i]) - 2]);
			if (split_input[i][j] != '1' || split_input[i][ft_strlen(split_input[i]) - 1] != '1')
				return (ft_error_msg("Map is not surrounded by walls", NULL), 1);
			if (i == 0 || i == ft_count_lines2d(split_input) - 1)
			{
				while (split_input[i][j])
				{
					if (split_input[i][j] != '1' && split_input[i][j] != ' ')
						return (ft_error_msg("Map is not surrounded by walls", NULL), 1);
					j++;
				}
			}
			i++;
		}
	}
	return (0);
}

int	ft_checks(t_cub *cub)
{

	ft_valid_elements(cub->split_input);
	cub->map = ft_get_map(cub->split_input);
	printf("map: \n");
	ft_print_split(cub->map);
	ft_check_walls(cub->map);
	return (0);
}