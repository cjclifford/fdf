/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:14:48 by ccliffor          #+#    #+#             */
/*   Updated: 2018/06/08 12:03:01 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*list;
	t_list	*prev;

	if (!lst || !f || !(head = f(lst)))
		return (NULL);
	lst = lst->next;
	prev = head;
	while (lst)
	{
		if (!(list = f(lst)))
			return (head);
		if (prev)
			prev->next = list;
		prev = list;
		lst = lst->next;
	}
	return (head);
}
