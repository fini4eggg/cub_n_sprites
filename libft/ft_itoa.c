/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 06:06:40 by bryella           #+#    #+#             */
/*   Updated: 2020/11/25 06:06:44 by bryella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nd(int n)
{
	int		i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (!n)
		return (0);
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = ft_nd(n);
	if (!(str = (char*)malloc((len) * sizeof(char))))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	str[--len] = '\0';
	while (n > 0)
	{
		str[--len] = 48 + n % 10;
		n = n / 10;
	}
	return (str);
}
