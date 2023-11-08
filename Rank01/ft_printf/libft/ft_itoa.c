/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:08:35 by isporras          #+#    #+#             */
/*   Updated: 2023/05/02 18:16:09 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		size;
	long	num;

	num = n;
	size = countn(num);
	str = (char *)malloc(size + 1 * sizeof(char));
	if (!str)
		return (NULL);
	if (num < 0)
	{
		num *= -1;
		str[0] = '-';
	}
	i = 0;
	while (num > 9)
	{
		str[size - 1 - i] = num % 10 + '0';
		num /= 10;
		i++;
	}
	str[size - 1 - i] = num + '0';
	str[size] = '\0';
	return (str);
}

//int main()
//{
//	int n = -2147483648;
//	printf("%s\n", ft_itoa(n));
//}
