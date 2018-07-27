/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 12:48:50 by ccliffor          #+#    #+#             */
/*   Updated: 2018/07/27 15:02:11 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	map(float value, t_range i_range, t_range o_range)
{
	return (o_range.start + (o_range.end - o_range.start) * ((value - i_range.start) / (i_range.end - i_range.start)));
}
