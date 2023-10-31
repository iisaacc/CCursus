/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:58:49 by isporras          #+#    #+#             */
/*   Updated: 2023/05/12 19:23:59 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strjoin(char *s1, char *s2);
char	*ft_callocmod(size_t count, size_t size);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
char	*get_next_line(int fd);

#endif
