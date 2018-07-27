/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:39:49 by ccliffor          #+#    #+#             */
/*   Updated: 2018/05/21 16:39:52 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;

	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	while (n--)
	{
		*p_dst = *p_src;
		if (*p_src == (unsigned char)c)
			return (++p_dst);
		p_dst++;
		p_src++;
	}
	return (0);
}
