/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 10:12:08 by ccliffor          #+#    #+#             */
/*   Updated: 2018/05/19 10:29:21 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	if (!c)
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == (char)c)
			ptr = (char *)s;
		s++;
	}
	if (*ptr == (char)c)
		return (ptr);
	return (0);
}
