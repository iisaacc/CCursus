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
	int		i;
	int		b;
	int		b2;
	int		n;

	n = 0;
	b = 0;
	b2 = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\"')
		{
			c = '\"';
			b2 = 1;
		}
		if (s[i] == '\'' && b2 == 0)
			c = '\'';
		if (s[i] == c)
			b = 0;
		if (s[i] != c && b == 0)
		{
			n++;
			b = 1;
		}
		i++;
	}
	return (n);
}

int	ft_to2d_mod(char const *s, int len, char **ans, int lap)
{
	int	i;

	ans[lap] = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	if (!ans[lap])
	{
		while (lap > 0)
		{
			free(ans[lap - 1]);
			lap--;
		}
		free(ans);
		return (1);
	}
	while (i < len)
	{
		ans[lap][i] = s[i];
		i++;
	}
	ans[lap][i] = '\0';
	return (0);
}

void	ft_skip(char *s, char *c, int *i)
{
	int	b;

	b = 0;
	while (s[*i] == *c && s[*i] != '\0')
	{
		(*i)++;
		if (s[*i] == '\'' && b == 0)
		{
			*c = '\'';
			b = 1;
		}
		if (s[*i] == '\"' && b == 0)
		{
			*c = '\"';
			b = 1;
		}
	}
}

char	**ft_splitaux_mod(char **ans, char *s, char c)
{
	int		i;
	int		len;
	int		lap;

	lap = 0;
	i = 0;
	while (s[i] != '\0')
	{
		len = 0;
		ft_skip(s, &c, &i);
		while (s[i + len] != '\0' && s[i + len] != c)
			len++;
		if (len > 0)
		{
			if (ft_to2d_mod(&s[i], len, ans, lap) == 1)
				return (NULL);
			lap++;
			i += len;
		}
	}

	ans[ft_countl_mod(s, ' ')] = NULL;
	return (ans);
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