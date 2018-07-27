/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 09:19:18 by ccliffor          #+#    #+#             */
/*   Updated: 2018/07/23 09:48:56 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	gradient(int colour1, int colour2, float factor)
{
	return (colour1 + (colour2 - colour1) * factor);
}
