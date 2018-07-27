/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 12:28:21 by ccliffor          #+#    #+#             */
/*   Updated: 2018/07/23 14:04:45 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int argc, char **argv)
{
	t_param	param;

	param.mlx = mlx_init();
	get_map_dimensions(argv[1], &param);
	get_map_data(argv[1], &param);
	param.scale = 10;
	param.width = sqrt(pow(param.size_x, 2) + pow(param.size_z, 2)) * param.scale;
	param.height = param.size_y * param.scale + 50;
	param.window = mlx_new_window(param.mlx, param.width, param.height, "does bruno mars is gay");
	param.mid_x = param.width / 2;
	param.mid_y = param.height / 2;
	(void)argc;
	rotate_Y(&param, -0.785398);
	rotate_X(&param, -0.523599);
	draw_map(&param);
	mlx_hook(param.window, 2, 0L, keyboard_hook, &param);
	mlx_hook(param.window, 4, 0L, mouse_hook_press, &param);
	mlx_hook(param.window, 5, 0L, mouse_hook_release, &param);
	mlx_hook(param.window, 6, 0L, mouse_hook_normal, &param);
	mlx_loop(param.mlx);
	return (0);
}
