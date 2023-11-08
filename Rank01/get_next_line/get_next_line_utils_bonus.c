/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:49:33 by isporras          #+#    #+#             */
/*   Updated: 2023/05/13 11:44:01 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *line, char *buffer)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = ft_callocmod((ft_strlen(line) + ft_strlen(buffer) + 1), sizeof(char));
	i = 0;
	j = 0;
	while (line && line[i])
	{
		str[j++] = line[i];
		i++;
	}
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[j++] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		str[j++] = buffer[i];
	str[j] = 0;
	if (line)
		free(line);
	return (str);
}

char	*ft_callocmod(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(count * size);
	if (ptr != NULL)
	{
		while (i < count * size)
		{
			ptr[i] = 0;
			i++;
		}
		return (ptr);
	}
	else
		return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
		ptr[i++] = 0;
}
