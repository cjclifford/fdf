/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 12:28:21 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/09 12:34:20 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int argc, char **argv)
{
	t_param	*param;

	ft_putendl("allocating struct");
	param = (t_param *)malloc(sizeof(t_param));
	ft_putendl("allocating mlx ptr");
	param->mlx = malloc(sizeof(void *));
	param->window = malloc(sizeof(void *));
	ft_putendl("creating mlx ptr");
	param->mlx = mlx_init();
	ft_putendl("getting dimensions");
	if (!get_map_dimensions(argv[1], param))
		return (0);
	ft_putendl("setting window width");
	param->width = 640;
	ft_putendl("setting window height");
	param->height = 430;
	ft_putendl("setting window midx");
	param->mid_x = param->width / 2;
	ft_putendl("setting window midy");
	param->mid_y = param->height / 2;
	ft_putendl("getting data");
	get_map_data(argv[1], param);
	ft_putendl("creating new window");
	printf("%p\n", mlx_new_window);
	param->window = mlx_new_window(param->mlx, param->width, param->height, "fdf");
	ft_putendl("voiding argc");
	(void)argc;
	ft_putendl("setting scale");
	param->scale = 10;
	printf("%f\n", param->scale);
	ft_putendl("y rotation");
	rotate_y(param, -0.785398);
	ft_putendl("x rotation");
	rotate_x(param, -0.523599);
	ft_putendl("drawing map");
	draw_map(param);
	ft_putendl("hooks");
	mlx_hook(param->window, 2, 0L, keyboard_hook, param);
	mlx_hook(param->window, 4, 0L, mouse_hook_press, param);
	mlx_hook(param->window, 5, 0L, mouse_hook_release, param);
	mlx_hook(param->window, 6, 0L, mouse_hook_normal, param);
	mlx_loop(param->mlx);
	return (0);
}
