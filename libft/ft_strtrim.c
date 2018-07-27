/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:01:12 by ccliffor          #+#    #+#             */
/*   Updated: 2018/05/23 14:01:14 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	unsigned int	start;
	size_t			end;

	start = 0;
	if (!s)
		return (NULL);
	while (s[start] == '\t' || s[start] == '\n' || s[start] == ' ')
		start++;
	end = ft_strlen(s) - 1;
	while (end > start && (s[end] == '\t' || s[end] == '\n' || s[end] == ' '))
		end--;
	if (end == start)
		return (ft_strnew(0));
	return (ft_strsub(s, start, end - start + 1));
}
