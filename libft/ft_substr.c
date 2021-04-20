/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 06:11:28 by bryella           #+#    #+#             */
/*   Updated: 2020/11/25 06:11:32 by bryella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	l;
	char	*str;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (start >= l)
		return (ft_strdup("\0"));
	str = (char*)s;
	l = (l - start + 1) > len ? len : l - start + 1;
	if (!len)
		return (ft_strdup("\0"));
	sub = (char*)malloc(l + 1);
	if (!sub)
		return (NULL);
	while (i < l)
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
