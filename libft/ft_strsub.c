/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:05:14 by ccliffor          #+#    #+#             */
/*   Updated: 2018/05/23 15:05:15 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*p_sub;

	if (!s)
		return (NULL);
	s = &s[start];
	if (!(sub = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	p_sub = sub;
	while (*s && len--)
		*p_sub++ = *s++;
	*p_sub = '\0';
	return (sub);
}
