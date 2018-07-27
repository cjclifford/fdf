/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 11:23:35 by ccliffor          #+#    #+#             */
/*   Updated: 2018/06/19 16:18:28 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ap, size_t old_size, size_t new_size)
{
	char	*new;

	if (!(new = (char *)ft_memalloc(sizeof(char) * new_size)))
		return (NULL);
	ft_memcpy(new, (char *)ap, old_size);
	free(ap);
	return (new);
}
