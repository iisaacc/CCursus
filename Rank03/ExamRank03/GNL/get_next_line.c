/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:33:04 by isporras          #+#    #+#             */
/*   Updated: 2024/01/10 14:17:21 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2
#endif

int	ft_strlen(char *s1)
{
	int	len;

	len = 0;
	while (s1 && s1[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		join[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i] && s2[i] != '\n')
		join[j++] = s2[i++];
	if (s2[i] == '\n')
		join[j] = '\n';
	else
		join[j] = 0;
	if (s1)
		free(s1);
	return (join);
}

int	ft_check_buffer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == '\n')
			return (1);
	}
	return (0);
}

void	ft_bzero(void	*ptr, int n)
{
	unsigned char	*s;
	int				i;

	s = (unsigned char *)ptr;
	i = 0;
	while (i < n)
		s[i++] = 0;
}

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
// 	int fd = open("txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));


// }