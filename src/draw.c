/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 14:34:04 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/04 13:31:42 by ccliffor         ###   ########.fr       */
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

// static int	find_region(t_param param, double x, double y)
// {
// 	int	region;


// 	region = 0;
// 	if (x < 0)
// 		region |= 1;
// 	else if (x > param.width)
// 		region |= 2;
// 	else if (y < 0)
// 		region |= 4;
// 	else if (y > param.height)
// 		region |= 8;
// 	return (region);
// }

// static int	line_clip(t_param param, t_line line)
// {
// 	int		region1;
// 	int		region2;
// 	int		out_region;
// 	float	x;
// 	float	y;

// 	region1 = find_region(param, line[0], line[1]);
// 	region2 = find_region(param, line[2], line[3]);

// 	while (1)
// 	{
// 		if ((region1 == 0) && (region2 == 0))
// 			return (1);
// 		else if (region1 & region2)
// 			return (0);
// 		else
// 		{
// 			if (region1 != 0)
// 				out_region = region1;
// 			else
// 				out_region = region2;
// 			if (out_region & 8)
// 			{
// 				x = line[0] + (line[2] - line[0]) * (param.height - line[1]) / (line[3] - line[1]);
// 				y = param.height;
// 			}
// 			else if (out_region & 4)
// 			{
// 				x = line[0] + (line[2] - line[0]) * (0 - line[1]) / (line[3] - line[1]);
// 				y = 0;
// 			}
// 			else if (out_region & 2)
// 			{
// 				y = line[1] + (line[3] - line[1]) * (param.width - line[0]) / (line[2] - line[0]);
// 				x = param.width;
// 			}
// 			else if (out_region & 1)
// 			{
// 				y = line[0] + (line[2] - line[0]) * (param.height - line[1]) / (line[3] - line[1]);
// 				x = 0;
// 			}
// 			if (out_region == region1)
// 			{
// 				line[0] = x;
// 				line[1] = y;
// 				region1 = find_region(param, line[0], line[1]);
// 			}
// 			else
// 			{
// 				line[2] = x;
// 				line[3] = y;
// 				region2 = find_region(param, line[2], line[3]);
// 			}
// 		}
// 	}
// 	return (1);
// }

void		draw_map(t_param *param)
{
	int	y;// was size_t
	int	x;// was size_t
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
				// if (line_clip(*param, line))
					line_put_image(param, line, i, i + param->size_x);
			}
			if (x + 1 < param->size_x)
			{
				line[0] = translate_x(*param, param->points[i][0]);
				line[1] = param->height - translate_y(*param, \
					param->points[i][1]);
				line[2] = translate_x(*param, param->points[i + 1][0]);
				line[3] = param->height - translate_y(*param, \
					param->points[i + 1][1]);
				// if (line_clip(*param, line))
					line_put_image(param, line, i, i + 1);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(param->mlx, param->window, param->img->img, 0, 0);
	mlx_destroy_image(param->mlx, param->img->img);
}
