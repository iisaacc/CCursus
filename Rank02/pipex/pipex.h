/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:13:01 by isporras          #+#    #+#             */
/*   Updated: 2023/11/15 10:13:01 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_pipex
{
	int		pipefd[2];
	char	*fl[2];
	int		fd[2];
	char	**cmnd1;
	char	**cmnd2;
	char	*pth[2];
}	t_pipex;

char	*ft_find_cmnd_path(char *command, char **envp);
char	*ft_find_cmnd_path(char *command, char **envp);
void	*ft_init(t_pipex *px, char **argv, char **envp);
void	ft_cleanup(t_pipex *px);
char	**ft_split_mod(char const *s, char c);

#endif