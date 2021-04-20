/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:35:35 by wcatwoma          #+#    #+#             */
/*   Updated: 2020/11/17 05:51:21 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*el;
	t_list	*buf;

	el = *lst;
	while (el)
	{
		buf = el->next;
		if (del)
			del(el->content);
		free(el);
		el = buf;
	}
	*lst = NULL;
}
