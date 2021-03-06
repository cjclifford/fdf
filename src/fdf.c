/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 12:28:21 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/09 17:00:41 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int argc, char **argv)
{
	t_param	param;

	(void)argc;
	if (argc != 2)
		return (1);
	if (!get_map_dimensions(argv[1], &param))
		return (0);
	param.width = 640;
	param.height = 430;
	get_map_data(argv[1], &param);
	param.mlx = mlx_init();
	param.window = mlx_new_window(param.mlx, param.width, param.height, "fdf");
	param.scale = 10;
	param.mid_x = param.width / 2;
	param.mid_y = param.height / 2;
	rotate_y(&param, -0.785398);
	rotate_x(&param, -0.523599);
	draw_map(&param);
	mlx_hook(param.window, 2, 0L, keyboard_hook, &param);
	mlx_hook(param.window, 4, 0L, mouse_hook_press, &param);
	mlx_hook(param.window, 5, 0L, mouse_hook_release, &param);
	mlx_hook(param.window, 6, 0L, mouse_hook_normal, &param);
	mlx_loop(param.mlx);
	return (0);
}
