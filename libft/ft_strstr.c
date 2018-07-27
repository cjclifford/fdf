/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 08:26:00 by ccliffor          #+#    #+#             */
/*   Updated: 2018/05/18 16:05:29 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*p_haystack;
	char	*p_needle;
	char	*temp;

	p_haystack = (char *)haystack;
	p_needle = (char *)needle;
	temp = p_needle;
	if (!*p_needle)
		return (p_haystack);
	while (*p_haystack)
	{
		temp = p_haystack;
		while (*p_haystack == *p_needle)
		{
			p_needle++;
			if (!*p_needle)
				return (temp);
			p_haystack++;
		}
		p_needle = (char *)needle;
		p_haystack = temp;
		p_haystack++;
	}
	return (0);
}
