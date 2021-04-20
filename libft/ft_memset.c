/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryella <bryella@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 23:33:28 by bryella           #+#    #+#             */
/*   Updated: 2021/03/24 13:45:45 by bryella          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char		temp;
	unsigned char		*i;

	temp = (unsigned char)c;
	i = (unsigned char *)b;
	while (len-- && len >=0)
		*i++ = temp;
	return (b);
}
