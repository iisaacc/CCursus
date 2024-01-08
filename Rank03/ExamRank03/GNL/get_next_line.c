/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:33:04 by isporras          #+#    #+#             */
/*   Updated: 2024/01/08 10:33:04 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_clear_buffer(char *buffer)
{
	int	i;
	int dif;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\0')
		ft_bzero(buffer, BUFFER_SIZE);
	else
	{
		dif = i + 1;
		i = 0;
		while (buffer[dif + i])
		{
			buffer[i] = buffer[dif + i];
			i++;
		}
		ft_bzero(&buffer[i], BUFFER_SIZE - i);
	}
}

char	*ft_fill_buffer(int fd, char *buffer, char *line)
{
	int			bytes_read;
	int b;

	b = 0;
	bytes_read = 1;
	while (bytes_read > 0 && b == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			if (bytes_read == 0)
				return(ft_bzero(buffer, BUFFER_SIZE), line);
			return(ft_bzero(buffer, BUFFER_SIZE), NULL);
		}
		if (ft_check_buffer(buffer) == 1)
			b = 1;
		line = ft_strjoin(line, buffer);
		ft_clear_buffer(buffer);
	}
	return (line);
}

char	*ft_get_buffer_line(char *buffer, char *line, int fd)
{
	line = ft_strjoin(line, buffer);
	if (line[ft_strlen(line) - 1] == '\n')
	{
		ft_clear_buffer(buffer);
		return (line);
	}
	return (ft_bzero(buffer, BUFFER_SIZE), ft_fill_buffer(fd, buffer, line));
}

char *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ft_bzero(buffer, BUFFER_SIZE), NULL);
	if (buffer[0] == 0)
		return (ft_fill_buffer(fd, buffer, line));
	else
		return (ft_get_buffer_line(buffer, line, fd));
}

// int main ()
// {
// 	int fd = open("txt.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));


// }