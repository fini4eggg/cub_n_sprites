/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:35:35 by wcatwoma          #+#    #+#             */
/*   Updated: 2020/11/25 04:29:02 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *ls, void *(*f)(void *), void (*dl)(void *))
{
	t_list	*new_lst;
	t_list	*new_el;

	if (!f || !dl)
		return (NULL);
	new_lst = NULL;
	while (ls)
	{
		if (!(new_el = ft_lstnew(f(ls->content))))
		{
			ft_lstclear(&new_lst, dl);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_el);
		ls = ls->next;
	}
	return (new_lst);
}
