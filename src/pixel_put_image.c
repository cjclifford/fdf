/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 13:35:29 by ccliffor          #+#    #+#             */
/*   Updated: 2018/07/27 15:02:12 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put_image(t_param *param, int x, int y, int color)
{
	int	i;

	i = 0;
	if (x >= 0 && x < (int)param->width && y >= 0 && y < (int)param->height)
	{
		i = x * param->img->bits_per_pixel + y * param->img->size_line;
		param->img->data[i] = color & 0xFF;
		param->img->data[i + 1] = (color & 0xFF00) / 0x100;
		param->img->data[i + 2] = (color & 0xFF0000) / 0x10000;
	}
}
