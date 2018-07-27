/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:53:27 by ccliffor          #+#    #+#             */
/*   Updated: 2018/05/22 15:53:30 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;

	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	if (src > dst)
	{
		while (len--)
			*p_dst++ = *p_src++;
	}
	else if (src < dst)
	{
		p_dst = &p_dst[len];
		p_src = &p_src[len];
		while (len--)
			*--p_dst = *--p_src;
	}
	return (dst);
}
