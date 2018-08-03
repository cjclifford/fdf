/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 12:48:50 by ccliffor          #+#    #+#             */
/*   Updated: 2018/07/31 11:45:47 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	map(float value, t_range i_range, t_range o_range)
{
	return (o_range[0] + (o_range[1] - o_range[0]) * \
		((value - i_range[0]) / (i_range[1] - i_range[0])));
}
