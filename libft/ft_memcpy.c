/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:59:12 by ccliffor          #+#    #+#             */
/*   Updated: 2018/05/21 15:59:14 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*p_dst;
	char	*p_src;

	p_dst = (char *)dst;
	p_src = (char *)src;
	while (n--)
		*p_dst++ = *p_src++;
	return (dst);
}
