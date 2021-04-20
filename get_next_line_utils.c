/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryella <bryella@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 05:13:40 by bryella           #+#    #+#             */
/*   Updated: 2021/03/19 21:33:21 by bryella          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (s1[len] != '\0')
		len++;
	s2 = (char*)malloc(len * sizeof(char) + 1);
	if (s2 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strchr(const char *s, int c)
{
	char	*a;
	char	ch;

	a = (char *)s;
	ch = (char)c;
	while (*a != '\0')
	{
		if (*a == ch)
			return (a);
		a++;
	}
	return ((*a == ch) ? a : NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ns;
	int		i;
	int		j;
	int		lens1;
	int		lens2;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	i = 0;
	j = 0;
	ns = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (ns == NULL)
		return (NULL);
	while (s1 && lens1--)
		ns[i++] = *s1++;
	while (s2 && lens2--)
		ns[i + j++] = *s2++;
	ns[i + j] = '\0';
	return ((char *)ns);
}
