/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 09:11:24 by ccliffor          #+#    #+#             */
/*   Updated: 2018/05/21 09:11:25 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	shortest;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len > dstsize)
		return (dstsize + src_len);
	shortest = dstsize - dst_len - 1;
	if (shortest > src_len)
		shortest = src_len;
	ft_memcpy(dst + dst_len, src, shortest);
	dst[dst_len + shortest] = '\0';
	return (dst_len + src_len);
}
