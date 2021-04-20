/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 06:05:24 by bryella           #+#    #+#             */
/*   Updated: 2020/11/25 06:05:28 by bryella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t nlen;

	nlen = ft_strlen(needle);
	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack != '\0' && len-- >= nlen)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, nlen) == 0)
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
