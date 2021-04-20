/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 06:03:58 by bryella           #+#    #+#             */
/*   Updated: 2020/11/25 06:04:02 by bryella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;
	unsigned char	ch;

	ch = (unsigned char)c;
	string = (unsigned char*)s;
	while (n--)
	{
		if (*string++ == ch)
			return (string - 1);
	}
	return (NULL);
}
