/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:07:52 by ccliffor          #+#    #+#             */
/*   Updated: 2018/05/22 17:08:00 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*p_str;
	size_t	len;

	str = (char *)s;
	p_str = str;
	len = 0;
	while (s[len])
		len++;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	p_str = str;
	while ((*p_str++ = *s++))
		;
	*p_str = '\0';
	return (str);
}
