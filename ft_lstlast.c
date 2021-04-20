/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryella <bryella@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 05:39:39 by bshawnee          #+#    #+#             */
/*   Updated: 2021/03/22 23:51:40 by bryella          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

t_list	*ft_lstlast(t_list *list)
{
	if (list && list->next)
		return (ft_lstlast(list->next));
	return (list);
}
