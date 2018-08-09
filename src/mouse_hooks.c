/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 10:54:58 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/09 11:31:22 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
