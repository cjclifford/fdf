/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 14:34:04 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/08 11:01:05 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	translate_x(t_param param, float i)
{
	i = ((i * param.scale) + (param.mid_x - (param.size_x / 2))) - \
	(param.scale * (param.size_x - 1) / 2);
	return (i);
}

static int	translate_y(t_param param, float i)
{
	i = ((i * param.scale) + (param.mid_y - (param.size_y / 2))) - \
	(param.scale * (param.size_y - 1) / 2);
	return (i);
}

void		draw_map(t_param *param)
{
	int		y;
	int		x;
	size_t	i;
	t_line	line;
	t_image	image;

	image.img = mlx_new_image(param->mlx, param->width, param->height);
	image.data = (unsigned char *)mlx_get_data_addr(image.img, \
		&image.bits_per_pixel, &image.size_line, &image.endian);
	image.bits_per_pixel /= 8;
	param->img = &image;
	y = 0;
	while (y < param->size_z)
	{
		x = 0;
		while (x < param->size_x)
		{
			i = x + y * param->size_x;
			if (y + 1 < param->size_z)
			{
				line[0] = translate_x(*param, param->points[i][0]);
				line[1] = param->height - translate_y(*param, \
					param->points[i][1]);
				line[2] = translate_x(*param, param->points[i + \
					param->size_x][0]);
				line[3] = param->height - translate_y(*param, \
					param->points[i + param->size_x][1]);
				line_put_image(param, line, i);
			}
			if (x + 1 < param->size_x)
			{
				line[0] = translate_x(*param, param->points[i][0]);
				line[1] = param->height - translate_y(*param, \
					param->points[i][1]);
				line[2] = translate_x(*param, param->points[i + 1][0]);
				line[3] = param->height - translate_y(*param, \
					param->points[i + 1][1]);
				line_put_image(param, line, i);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(param->mlx, param->window, param->img->img, 0, 0);
	mlx_destroy_image(param->mlx, param->img->img);
}
