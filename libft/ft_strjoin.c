/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:49:41 by bryella           #+#    #+#             */
/*   Updated: 2020/11/24 21:49:46 by bryella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	l1;
	size_t	l2;
	size_t	i;
	size_t	lres;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	lres = l1 + l2;
	res = (char*)malloc(lres + 1);
	if (!res)
		return (NULL);
	ft_bzero(res, lres + 1);
	ft_strlcat(res, s1, l1 + 1);
	ft_strlcat(res + l1, s2, lres + 1);
	return (res);
}
