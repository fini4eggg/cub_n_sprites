/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 06:10:05 by bryella           #+#    #+#             */
/*   Updated: 2020/11/25 06:10:10 by bryella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_nw(char const *s, char c)
{
	size_t i;
	size_t nw;

	i = 0;
	nw = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			nw++;
		i++;
	}
	return (nw);
}

size_t		ft_strclen(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char		**resfree(char **res, size_t nw)
{
	size_t	i;

	i = 0;
	while (i < nw)
	{
		free((char *)res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	if (!(res = (char**)malloc(sizeof(char*) * (ft_nw(s, c) + 1))))
		return (NULL);
	res[ft_nw(s, c)] = NULL;
	while (j < ft_nw(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		if (!(res[j] = ft_substr(s, i, ft_strclen(&(s[i]), c))))
		{
			resfree(res, j);
			return (NULL);
		}
		i += ft_strclen(&(s[i]), c);
		j++;
	}
	res[j] = NULL;
	return (res);
}
