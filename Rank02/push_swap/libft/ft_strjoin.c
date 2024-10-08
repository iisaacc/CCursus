/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:50:38 by isporras          #+#    #+#             */
/*   Updated: 2023/11/10 12:30:04 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = 0;
	free((char *)s1);
	return (str);
}

char	*ft_strjoinfree(char *line, char *buffer)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = ft_calloc((ft_strlen(line) + ft_strlen(buffer) + 1), sizeof(char));
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
//int main()
//{
//    char first[] = "";
//    char last[] = "a potentially long string";
//    printf("Value returned: %s\n",ft_strjoin(first, last));
//    return(0);
//}
