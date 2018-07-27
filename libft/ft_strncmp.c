/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:59:38 by ccliffor          #+#    #+#             */
/*   Updated: 2018/06/12 13:14:36 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (n-- && *s1 && (*s1 == *s2))
	{
		if (n)
		{
			s1++;
			s2++;
		}
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
