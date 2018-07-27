/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:59:36 by ccliffor          #+#    #+#             */
/*   Updated: 2018/07/16 16:42:22 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_X(t_param *param, float theta)
{
	double	sin_t;
	double	cos_t;
	float	tmp;
	float	tmp_point[2];
	int	i;

	sin_t = sin(theta);
	cos_t = cos(theta);
	i = (param->size_z * param->size_x) - 1;
	while (i >= 0)
	{
		tmp_point[0] = param->points[i][1] - (param->size_y / 2);
		tmp_point[1] = param->points[i][2] - (param->size_z / 2);
		tmp = tmp_point[1] * cos_t - tmp_point[0] * sin_t;
		tmp_point[0] = tmp_point[0] * cos_t + tmp_point[1] * sin_t;
		tmp_point[1] = tmp;
		param->points[i][1] = tmp_point[0] + (param->size_y / 2);
		param->points[i][2] = tmp_point[1] + (param->size_z / 2);
		i--;
	}
}

void	rotate_Y(t_param *param, float theta)
{
	double	sin_t;
	double	cos_t;
	float	tmp;
	float	tmp_point[2];
	int	i;

	sin_t = sin(theta);
	cos_t = cos(theta);
	i = (param->size_z * param->size_x) - 1;
	while (i >= 0)
	{
		tmp_point[0] = param->points[i][0] - (param->size_x / 2);
		tmp_point[1] = param->points[i][2] - (param->size_z / 2);
		tmp = tmp_point[0] * cos_t - tmp_point[1] * sin_t;
		tmp_point[1] = tmp_point[1] * cos_t + tmp_point[0] * sin_t;
		tmp_point[0] = tmp;
		param->points[i][0] = tmp_point[0] + (param->size_x / 2);
		param->points[i][2] = tmp_point[1] + (param->size_z / 2);
		i--;
	}
}

void	rotate_Z(t_param *param, float theta)
{
	double	sin_t;
	double	cos_t;
	float	tmp;
	float	tmp_point[2];
	int	i;

	sin_t = sin(theta);
	cos_t = cos(theta);
	i = (param->size_z * param->size_x) - 1;
	while (i >= 0)
	{
		tmp_point[0] = param->points[i][0] - (param->size_x / 2);
		tmp_point[1] = param->points[i][1] - (param->size_y / 2);
		tmp = tmp_point[0] * cos_t - tmp_point[1] * sin_t;
		tmp_point[1] = tmp_point[1] * cos_t + tmp_point[0] * sin_t;
		tmp_point[0] = tmp;
		param->points[i][0] = tmp_point[0] + (param->size_x / 2);
		param->points[i][1] = tmp_point[1] + (param->size_y / 2);
		i--;
	}
}
