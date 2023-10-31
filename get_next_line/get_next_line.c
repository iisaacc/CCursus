/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:49:22 by isporras          #+#    #+#             */
/*   Updated: 2023/05/13 11:35:50 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_clear_buffer(char *buffer)
{
	size_t	i;
	int		dif;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
		ft_bzero(buffer, BUFFER_SIZE);
	else
	{
		i++;
		dif = i;
		while (buffer[i] != '\0')
		{
			buffer[i - dif] = buffer[i];
			i++;
		}
		ft_bzero(&buffer[i - dif], BUFFER_SIZE - (i - dif));
	}
}

char	*ft_fill_line(char *buffer, int fd, char *line)
{
	int		boole;
	size_t	i;
	size_t	bytes_read;

	bytes_read = 1;
	boole = 0;
	while (bytes_read > 0 && boole == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			if (bytes_read == 0)
				return (ft_bzero(buffer, BUFFER_SIZE), line);
			return (ft_bzero(buffer, BUFFER_SIZE), NULL);
		}
		i = 0;
		while (buffer[i] != '\0' && boole == 0)
		{
			if (buffer[i++] == '\n')
				boole = 1;
		}
		line = ft_strjoin(line, buffer);
		ft_clear_buffer(buffer);
	}
	return (line);
}

char	*ft_get_buffer_line(char *buffer, char *line, int fd)
{
	int	i;

	i = 0;
	line = ft_strjoin(line, buffer);
	if (line[ft_strlen(line) - 1] == '\n')
	{
		ft_clear_buffer(buffer);
		return (line);
	}
	return (ft_bzero(buffer, BUFFER_SIZE), ft_fill_line(buffer, fd, line));
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	buffer[BUFFER_SIZE] = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ft_bzero(buffer, BUFFER_SIZE), NULL);
	line = NULL;
	if (buffer[0] == 0)
		return (ft_bzero(buffer, BUFFER_SIZE), ft_fill_line(buffer, fd, line));
	else
		return (ft_get_buffer_line(buffer, line, fd));
}
