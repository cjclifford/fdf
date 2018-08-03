/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 14:25:44 by ccliffor          #+#    #+#             */
/*   Updated: 2018/07/30 16:32:08 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keyboard_hook(int keycode, t_param *param)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 24)
	{
		param->scale *= 1.5;
		draw_map(param);
	}
	else if (keycode == 27)
	{
		if (param->scale > 0.1)
			param->scale /= 1.5;
		draw_map(param);
	}
	else if (keycode == 123)
	{
		param->mid_x -= 10;
		draw_map(param);
	}
	else if (keycode == 124)
	{
		param->mid_x += 10;
		draw_map(param);
	}
	else if (keycode == 125)
	{
		param->mid_y -= 10;
		draw_map(param);
	}
	else if (keycode == 126)
	{
		param->mid_y += 10;
		draw_map(param);
	}
	else if (keycode == 12)
	{
		rotate_z(param, PI_16);
		draw_map(param);
	}
	else if (keycode == 14)
	{
		rotate_z(param, -PI_16);
		draw_map(param);
	}
	else if (keycode == 2)
	{
		rotate_y(param, PI_16);
		draw_map(param);
	}
	else if (keycode == 0)
	{
		rotate_y(param, -PI_16);
		draw_map(param);
	}
	else if (keycode == 13)
	{
		rotate_x(param, PI_16);
		draw_map(param);
	}
	else if (keycode == 1)
	{
		rotate_x(param, -PI_16);
		draw_map(param);
	}
	return (1);
}

int	mouse_hook_normal(int x, int y, t_param *param)
{
	static int prev_x;
	static int prev_y;

	if (param->is_pressed)
	{
		rotate_y(param, ((float)(prev_x - x)) / 57);
		rotate_x(param, ((float)(prev_y - y)) / 57);
		draw_map(param);
	}
	prev_x = x;
	prev_y = y;
	return (0);
}

int	mouse_hook_press(int button, int x, int y, t_param *param)
{
	param->is_pressed = 1;
	return (button + x + y);
}

int	mouse_hook_release(int button, int x, int y, t_param *param)
{
	param->is_pressed = 0;
	return (button + x + y);
}
