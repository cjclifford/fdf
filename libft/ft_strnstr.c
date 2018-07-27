/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:29:48 by ccliffor          #+#    #+#             */
/*   Updated: 2018/06/12 12:04:34 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*p_haystack;
	char	*p_needle;
	char	*temp;
	size_t	tmp_len;

	p_haystack = (char *)haystack;
	p_needle = (char *)needle;
	if (!*p_needle)
		return (p_haystack);
	while (*p_haystack && len)
	{
		temp = p_haystack;
		tmp_len = len;
		while (*p_haystack == *p_needle && tmp_len)
		{
			if (!*++p_needle)
				return (temp);
			p_haystack++;
			tmp_len--;
		}
		p_needle = (char *)needle;
		p_haystack = ++temp;
		len--;
	}
	return (0);
}
