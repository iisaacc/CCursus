#include "../../includes/cub3d.h"


int	ft_valid_elements(char **split_input)
{
	int	i;
	int	count;
	char debug;

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
		{
			debug = split_input[i][0];
			(void)debug;
			return (ft_error_msg("Strange element before textures definitions: ", split_input[i]), 1);
		}
		i++;
	}
	return (0);
}

int	ft_check_walls(char **split_input)
{
	int	i;

}
int	ft_checks(t_cub *cub)
{
	if (ft_valid_elements(cub->split_input) == 0)
		return (0);
	cub->map = ft_get_map(cub->split_input);
}