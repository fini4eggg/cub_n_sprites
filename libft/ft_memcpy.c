/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 23:24:49 by bryella           #+#    #+#             */
/*   Updated: 2020/11/24 23:24:53 by bryella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned const char		*source;
	unsigned char			*destin;

	source = (unsigned char*)src;
	destin = (unsigned char*)dst;
	if (destin || source)
		while (n--)
			*destin++ = *source++;
	return (dst);
}
