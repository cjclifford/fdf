/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 10:05:59 by ccliffor          #+#    #+#             */
/*   Updated: 2018/05/29 11:45:50 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	digit_len(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		i++;
	if (!n)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	size_t		i;
	long		tmp_n;
	int			neg;
	char		*str;

	i = 0;
	tmp_n = n;
	neg = 0;
	i = digit_len(n);
	if (tmp_n < 0)
	{
		tmp_n = -tmp_n;
		neg = 1;
	}
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i)
	{
		i--;
		str[i] = tmp_n % 10 + '0';
		tmp_n /= 10;
	}
	if (neg)
		str[i] = '-';
	return (str);
}
