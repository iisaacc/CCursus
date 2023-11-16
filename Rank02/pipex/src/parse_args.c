/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:45:50 by isporras          #+#    #+#             */
/*   Updated: 2023/11/15 13:45:50 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <string.h>

char	*ft_strjointest(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = 0;
	if (s1)
		free((char *)s1);
	return (str);
}

char *ft_find_cmnd_path(char *command, char **envp)
{
	(void)command;
	char	**splitpth;
	char	*fullpth;
	int		i;

	splitpth = NULL;
	fullpth = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break;
		i++;
	}
	splitpth = ft_split(&envp[i][5], ':');
	i = 0;
	while (splitpth[i])
	{
		fullpth = ft_strjointest(fullpth, splitpth[i]);
		fullpth = ft_strjointest(fullpth, "/\0");
		fullpth = ft_strjointest(fullpth, command);
		if (access(fullpth, F_OK) == 0)
		{
			ft_free_2d(splitpth);
			return (fullpth);
		}
		ft_bzero(fullpth, ft_strlen(fullpth));
		i++;
	}
	free(fullpth);
	ft_free_2d(splitpth);
	return (NULL);
}

