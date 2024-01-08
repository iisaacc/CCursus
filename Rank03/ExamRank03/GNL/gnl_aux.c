/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:57:01 by isporras          #+#    #+#             */
/*   Updated: 2024/01/08 10:57:01 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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