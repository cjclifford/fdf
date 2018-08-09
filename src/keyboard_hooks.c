/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 14:25:44 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/09 12:28:54 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate(t_param *param, int keycode)
{
	if (keycode == 12)
		rotate_z(param, PI_16);
	else if (keycode == 14)
		rotate_z(param, -PI_16);
	else if (keycode == 2)
		rotate_y(param, PI_16);
	else if (keycode == 0)
		rotate_y(param, -PI_16);
	else if (keycode == 13)
		rotate_x(param, PI_16);
	else if (keycode == 1)
		rotate_x(param, -PI_16);
}

static void	translate(t_param *param, int keycode)
{
	if (keycode == 123)
		param->mid_x -= 10;
	else if (keycode == 124)
		param->mid_x += 10;
	else if (keycode == 125)
		param->mid_y -= 10;
	else if (keycode == 126)
		param->mid_y += 10;
}

static void	scale(t_param *param, int keycode)
{
	if (keycode == 24)
		param->scale *= 1.5;
	else if (keycode == 27)
	{
		if (param->scale > 0.1)
			param->scale /= 1.5;
	}
}

int			keyboard_hook(int keycode, t_param *param)
{
	if (keycode == 53)
		exit(0);
	scale(param, keycode);
	translate(param, keycode);
	rotate(param, keycode);
	draw_map(param);
	return (1);
}
