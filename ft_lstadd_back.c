/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryella <bryella@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:35:35 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/03/22 23:44:48 by bryella          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list *last;

	if (*list)
	{
		last = ft_lstlast(*list);
		last->next = new;
	}
	else
		*list = new;
}
