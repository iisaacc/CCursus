/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:11:51 by isporras          #+#    #+#             */
/*   Updated: 2023/11/16 11:11:51 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	*ft_get_argv(t_pipex *px, char **argv)
{
	px->fd[0] = open(argv[1], O_RDONLY);
	px->fd[1] = open(argv[4], O_WRONLY);
	px->cmnd1 = ft_split(argv[2], ' ');
	px->cmnd2 = ft_split(argv[3], ' ');
	if (!px->cmnd1 || !px->cmnd2 || px->fd[0] == -1 || px->fd[1] == -1)
		return (NULL);
	return (px);
}

void	*ft_init(t_pipex *px, char **argv, char **envp)
{
	if (!ft_get_argv(px, argv))
		return (NULL);
	px->pth[0] = ft_find_cmnd_path(px->cmnd1[0], envp);
	px->pth[1] = ft_find_cmnd_path(px->cmnd2[0], envp);
	if (pipe(px->pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	if (!px->pth[0] || !px->pth[1])
		return (NULL);
	return (px);
}