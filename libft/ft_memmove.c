/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 23:32:31 by bryella           #+#    #+#             */
/*   Updated: 2020/11/24 23:32:46 by bryella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*destin;
	unsigned char		*source;

	source = (unsigned char*)src;
	destin = (unsigned char*)dst;
	if ((destin - source > 0) && len > (size_t)(destin - source))
	{
		while (len)
		{
			*(destin + len - 1) = *(source + len - 1);
			len--;
		}
	}
	else
		ft_memcpy(destin, source, len);
	return (destin);
}
