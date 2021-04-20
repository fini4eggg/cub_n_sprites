/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 06:01:57 by bryella           #+#    #+#             */
/*   Updated: 2020/11/25 06:02:02 by bryella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_nb(const char *str, int *i, int *sign)
{
	while (str[*i] && ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

int			ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nu;
	int	digs;

	i = 0;
	sign = 1;
	nu = 0;
	digs = 0;
	if (str[i] == '\0')
		return (0);
	ft_nb(str, &i, &sign);
	while (ft_isdigit(str[i]))
	{
		nu = nu * 10 + (str[i] - 48);
		i++;
		digs++;
	}
	return (nu * sign);
}
