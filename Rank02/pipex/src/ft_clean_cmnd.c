/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_cmnd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:17:33 by isporras          #+#    #+#             */
/*   Updated: 2023/11/24 14:17:33 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

//Elimina los caracteres de comillas de los extremos de los comandos
void	ft_clean_ext(char **cmnd)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*cmnd)[i] == '\"' || (*cmnd)[i] == '\'')
		i++;
	tmp = *cmnd;
	*cmnd = ft_substr(*cmnd, i, ft_strlen(*cmnd));
	free(tmp);
	i = ft_strlen(*cmnd) - 1;
	while ((*cmnd)[i] == '\"' || (*cmnd)[i] == '\'')
		(*cmnd)[i--] = '\0';
}

//Elimina los carácteres no permitidos en el interior de los comandos
void	ft_clean_ins(char *cmnd)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (cmnd[i])
	{
		if (cmnd[i] == '\\')
			i++;
		else
			cmnd[j++] = cmnd[i++];
	}
	cmnd[j] = '\0';
}

void	ft_clean_cmnd(t_pipex *px)
{
	if (px->cmnd1[1])
	{
		ft_clean_ext(&px->cmnd1[1]);
		ft_clean_ins(px->cmnd1[1]);
	}
	if (px->cmnd2[1])
	{
		ft_clean_ext(&px->cmnd2[1]);
		ft_clean_ins(px->cmnd2[1]);
	}
	
}