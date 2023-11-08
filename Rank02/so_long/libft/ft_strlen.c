/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:42:54 by isporras          #+#    #+#             */
/*   Updated: 2023/10/20 11:03:41 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if(!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
//int main()
//{
//	char hola[] = "holajjjj";
//	printf("%zu", ft_strlen(hola));
//}
