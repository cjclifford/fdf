/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 09:51:32 by ccliffor          #+#    #+#             */
/*   Updated: 2018/05/23 09:51:33 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	tmp_n;

	tmp_n = n;
	if (tmp_n < 0)
	{
		ft_putchar_fd('-', fd);
		tmp_n = -tmp_n;
	}
	if (tmp_n >= 10)
	{
		ft_putnbr_fd((int)(tmp_n / 10), fd);
		ft_putchar_fd(tmp_n % 10 + '0', fd);
	}
	else if (n < 10)
		ft_putchar_fd(tmp_n % 10 + '0', fd);
}
