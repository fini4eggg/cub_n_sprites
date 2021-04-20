/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryella <bryella@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 05:04:41 by bryella           #+#    #+#             */
/*   Updated: 2021/04/05 19:08:27 by bryella          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*ptr;
	size_t		mem;

	mem = count * size;
	if (!(ptr = malloc(mem)))
		return (NULL);
	if (ptr)
		ft_memset(ptr, 0, mem);
	return (ptr);
}
