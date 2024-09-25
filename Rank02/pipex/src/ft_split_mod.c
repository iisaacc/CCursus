/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:54:23 by isporras          #+#    #+#             */
/*   Updated: 2023/11/20 09:54:23 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_countl_mod(char const *s, char c)
{
	int	i;
	int	count;
	int	b;

	b = 0;
	i = 0;
	count = 0;
	while (s && s[i] && count < 2)
	{
		if (s[i] != c && b == 0 && count < 2)
		{
			count++;
			b = 1;
		}
		if (s[i] == c)
			b = 0;
		i++;
	}
	return (count);
}

char	**ft_splitaux_mod(char **str, char *s, char c)
{
	int		i;
	int		len;
	int		lap;

	lap = 0;
	i = 0;
	while (s && s[i])
	{
		len = 0;
		while (s[i + len] != c && s[i + len] != '\0')
			len++;
		if (len > 0)
			ft_to2d(&s[i], len, str, lap++);
		i += len;
		c = '\0';
		if (s[i] != '\0')
			i++;
	}
	str[lap] = NULL;
	return (str);
}

char	**ft_split_mod(char const *s, char c)
{
	char	**ans;

	ans = (char **)malloc((ft_countl_mod(s, c) + 1) * sizeof(char *));
	if (!ans)
		return (NULL);
	return (ft_splitaux_mod(ans, (char *)s, c));
}

// int main(void)
// {
// 	int i;
// 	char *str = "awk \"'{count++} END {print count}'\"";
// 	char **split = ft_split_mod(str, ' ');
// 	i = 0;
// 	while (split[i])
// 	{
// 		printf("%s\n", split[i]);
// 		i++;
// 	}
// }