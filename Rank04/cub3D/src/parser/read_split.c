#include "../../includes/cub3d.h"

int	ft_count_lines_fd(int fd)
{
	int		count;

	count = 0;
	while (get_next_line(fd))
		count++;
	close(fd);
	return (count);
}

char	**ft_read_and_split(char *file)
{
	char	**array;
	char	*line;
	int		fd;
	int		len;

	fd = open(file, O_RDONLY);
	len = ft_count_lines_fd(fd);
	fd = open(file, O_RDONLY);
	array = ft_calloc((len + 1), sizeof(char *));
	line = get_next_line(fd);
	len = 0;
	while (line)
	{
		array[len] = line;
		line = get_next_line(fd);
		len++;
	}
	array[len] = NULL;
	return (array);
}