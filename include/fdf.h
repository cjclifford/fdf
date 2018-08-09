/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 11:57:07 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/08 11:00:45 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h> // REMOVE

# define PI_16 ((360 * M_PI / 180) / 16)
# define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
# define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
# define CLAMP(i, min, max) (i > max ? max : i < min ? min : i)


typedef float	t_range[2];
typedef float	t_point[4];
typedef int		t_line[4];

typedef struct	s_image
{
	void			*img;
	unsigned char	*data;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}				t_image;

typedef struct	s_param
{
	void	*mlx;
	void	*window;
	t_image	*img;

	t_point	*points;

	int	size_x;//was size_t
	int	size_y;//was size_t
	int	size_z;//was size_t

	size_t	width;
	size_t	height;

	int	mid_x;//was size_t
	int	mid_y;//was size_t
	
	float	scale;

	int		is_pressed;
}				t_param;

void	rotate_x(t_param *param, float theta);
void	rotate_y(t_param *param, float theta);
void	rotate_z(t_param *param, float theta);

int		keyboard_hook(int keycode, t_param *param);
int		mouse_hook_normal(int x, int y, t_param *param);
int		mouse_hook_press(int button, int x, int y, t_param *param);
int		mouse_hook_release(int button, int x, int y, t_param *param);

void	line_put_image(t_param *param, t_line line, int point);
void	pixel_put_image(t_param *param, int x, int y, int color);

int		get_map_dimensions(char *file, t_param *param);
void	get_map_data(char *file, t_param *param);

void	draw_map(t_param *param);

#endif
