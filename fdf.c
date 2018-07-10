/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 12:28:21 by ccliffor          #+#    #+#             */
/*   Updated: 2018/07/10 16:10:02 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_params
{
	void	*mlx;
	void	*window;
	size_t	width;
	size_t	height;
	int		**map;
	size_t	map_width;
	size_t	map_height;
}				t_params;

// static void	swap(int *a, int *b)
// {
// 	int	tmp;

// 	tmp = *a;
// 	*a = *b;
// 	*b = tmp;
// }

// static void	line_put(int x1, int y1, int x2, int y2, t_params params)
// {
// 	double	slope;
// 	double	offset;
// 	int		iterate;
// 	int		*x;
// 	int		*y;
// 	slope = 0;
// 	offset = 0;
// 	if (abs(x1 - x2) >= abs(y1 - y2))
// 	{
// 		x = &x1;
// 		y = &y1;
// 	}
// 	else
// 	{
// 		swap(&x1, &y1);
// 		swap(&x2, &y2);
// 		x = &y1;
// 		y = &x1;
// 	}
// 	iterate = -1 + (2 * (x1 < x2));
// 	slope = ((double)abs(y1 - y2) / (double)abs(x1 - x2)) * (-1 + (2 * (y1 < y2)));
// 	while (x1 != x2)
// 	{
// 		if (offset >= 0.49999 || offset <= -0.5)
// 		{
// 			offset -= -1 + (2 * (y1 < y2));
// 			y1 += -1 + (2 * (y1 < y2));
// 		}
// 		mlx_pixel_put(params.mlx, params.window, *x, *y, 0x36FF00);
// 		x1 += iterate;
// 		offset += slope;
// 	}
// }

// static int	keyboard_hook(int keycode)
// {
// 	printf("%d\n", keycode);
// 	if (keycode == 53)
// 		exit(0);
// 	return (1);
// }



void	read_map(char *file, t_params *params)
{
	char	**list;
	char	*line;
	size_t	i;
	size_t	j;
	int		fd;

	//new plan!
	//read file, get dimensions, read again colleting data
	fd = open(file, O_RDONLY);
	params->height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		params->map_width = 0;
		list = ft_strsplit(line, ' ');
		i = 0;
		while (list[i])
			i++;
		if (params->map_height == 0)
			params->map_width = i;
		else if (i < params->map_width)
			return ;
		params->map_height++;
	}
	params->map = (int **)malloc(sizeof(int *) * (params->map_height));
	i = 0;
	while (i < params->map_height)
		params->map[i++] = (int *)malloc(sizeof(int *) * (params->map_width));
	close(fd);
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, ' ');
		j = 0;
		while (list[j])
		{
			params->map[i][j] = ft_atoi(list[j]);
			if (params->map[i][j] >= 10)
				printf("%d ", params->map[i][j]);
			else
				printf("%d  ", params->map[i][j]);
			j++;
		}
		printf("\n");
		free(list);
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_params	params;
	// size_t		i = 0;
	// size_t		j;

	// params.mlx = mlx_init();
	// params.width = 640;
	// params.height = 430;
	// params.window = mlx_new_window(params.mlx, params.width, params.height, "does bruno mars is gay");
	// params.x = params.width / 2;
	// params.y = params.height / 2;

	// mlx_key_hook(params.window, keyboard_hook, &params);
	// mlx_loop(params.mlx);
	(void)argc;
	read_map(argv[1], &params);
	// while (i < params.map_height)
	// {
	// 	j = 0;
	// 	while (j < params.map_width)
	// 	{
	// 		printf("%lu %lu (%d) ", i, j, params.map[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
	return (0);
}
