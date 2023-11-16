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

int main (int argc, char *argv[], char **envp)
{
	// (void)argv;
	(void)argc;
	t_pipex	px;
	pid_t	pid;
	//char	*buffer;


	if (argc == 5)
	{
		if (!ft_init(&px, argv, envp))
		{
			perror("init");
			exit(EXIT_FAILURE);
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			close(px.pipefd[0]);
			dup2(px.pipefd[1], STDOUT_FILENO);
			dup2(px.fd[0], STDIN_FILENO);
			execve(px.pth[0], px.cmnd1, NULL);
			close(px.pipefd[1]);
		}
		else
		{
			close(px.pipefd[1]);
			dup2(px.pipefd[0], STDIN_FILENO);
			dup2(px.fd[1] ,STDOUT_FILENO);
			execve(px.pth[1], px.cmnd2, NULL);
			close(px.pipefd[0]);
		}
		return (0);
	}
}