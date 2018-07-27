/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 13:12:22 by ccliffor          #+#    #+#             */
/*   Updated: 2018/06/04 11:37:07 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_subs(const char *s, char c)
{
	size_t	i;
	size_t	subs;

	i = 0;
	subs = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			subs++;
		i++;
	}
	return (subs);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**list;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(list = (char **)ft_memalloc(sizeof(char *) * (count_subs(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		len = 0;
		if (*s && *s != c)
		{
			while (s[len] && s[len] != c)
				len++;
			if (!(list[i++] = ft_strsub(s, 0, len)))
				return (NULL);
			s += len;
		}
		else
			s++;
	}
	list[i] = 0;
	return (list);
}
