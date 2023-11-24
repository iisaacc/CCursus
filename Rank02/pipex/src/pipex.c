/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:44:04 by isporras          #+#    #+#             */
/*   Updated: 2023/11/15 09:44:04 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_execve(t_pipex *px, int pid)
{
	if (pid == 0)
	{
		close(px->pipefd[0]);
		dup2(px->pipefd[1], STDOUT_FILENO);
		dup2(px->fd[0], STDIN_FILENO);
		execve(px->pth[0], px->cmnd1, NULL);
		close(px->pipefd[1]);
		ft_cleanup(px);
	}
	else
	{
		close(px->pipefd[1]);
		dup2(px->pipefd[0], STDIN_FILENO);
		dup2(px->fd[1], STDOUT_FILENO);
		execve(px->pth[1], px->cmnd2, NULL);
		close(px->pipefd[0]);
		ft_cleanup(px);
	}
}

int	main(int argc, char *argv[], char **envp)
{
	t_pipex	px;
	pid_t	pid;

	if (argc == 5)
	{
		if (!ft_init(&px, argv, envp))
		{
			ft_cleanup(&px);
			perror("init");
			exit(EXIT_FAILURE);
		}
		pid = fork();
		if (pid == -1)
		{
			ft_cleanup(&px);
			perror("fork");
			exit(EXIT_FAILURE);
		}
		ft_execve(&px, pid);
		return (0);
	}
	else
		ft_printf("Introduce 4 arguments\n");
}
