/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:19:43 by ccliffor          #+#    #+#             */
/*   Updated: 2018/06/14 11:18:58 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strre(char *str, size_t size)
{
	char	*new;

	if (!(new = (char *)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (str)
		ft_strcpy(new, str);
	free(str);
	return (new);
}
