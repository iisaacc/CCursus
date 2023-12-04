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
	if (px->fd[0] == -1)
	{
		perror("bash: infile");
		px->fd[0] = open("/dev/null", O_RDONLY);
	}
	px->fd[1] = open(argv[4], O_WRONLY | O_CREAT, 0644);
	px->cmnd1 = ft_split_mod(argv[2], ' ');
	px->cmnd2 = ft_split_mod(argv[3], ' ');
	ft_clean_cmnd(px);
	if (!px->cmnd1 || !px->cmnd2)
	{
		ft_cleanup(px);
		perror("split");
		exit(EXIT_FAILURE);
		return (NULL);
	}
	if (px->fd[1] == -1)
		perror("Failed to open file");
	return (px);
}

void	ft_null_init(t_pipex *px)
{
	px->pipefd[0] = -1;
	px->pipefd[1] = -1;
	px->fd[0] = -1;
	px->fd[1] = -1;
	px->fl[0] = NULL;
	px->fl[1] = NULL;
	px->pth[0] = NULL;
	px->pth[1] = NULL;
	px->cmnd1 = NULL;
	px->cmnd2 = NULL;
}

void	*ft_init(t_pipex *px, char **argv, char **envp)
{
	ft_null_init(px);
	if (!ft_get_argv(px, argv))
		return (NULL);
	px->pth[0] = ft_find_cmnd_path(px->cmnd1[0], envp);
	px->pth[1] = ft_find_cmnd_path(px->cmnd2[0], envp);
	if (pipe(px->pipefd) == -1)
	{
		ft_cleanup(px);
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	if (!px->pth[0] || !px->pth[1])
		perror("command not found");
	return (px);
}

void	ft_cleanup(t_pipex *px)
{
	if (px->fl[0])
		free(px->fl[0]);
	if (px->fl[1])
		free(px->fl[1]);
	if (px->pth[0])
		free(px->pth[0]);
	if (px->pth[1])
		free(px->pth[1]);
	if (px->cmnd1)
		ft_free_2d(px->cmnd1);
	if (px->cmnd2)
		ft_free_2d(px->cmnd2);
}
