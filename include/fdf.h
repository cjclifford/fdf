/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 11:57:07 by ccliffor          #+#    #+#             */
/*   Updated: 2018/07/27 15:02:13 by ccliffor         ###   ########.fr       */
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


typedef float	t_point[4];
typedef int		t_line[4];

typedef struct	s_range
{
	float	start;
	float	end;
}				t_range;

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

	size_t	size_x;
	size_t	size_y;
	size_t	size_z;

	size_t	width;
	size_t	height;

	size_t	mid_x;
	size_t	mid_y;
	
	float	scale;

	int		is_pressed;
}				t_param;

void	rotate_X(t_param *param, float theta);
void	rotate_Y(t_param *param, float theta);
void	rotate_Z(t_param *param, float theta);

int		keyboard_hook(int keycode, t_param *param);
int		mouse_hook_normal(int x, int y, t_param *param);
int		mouse_hook_press(int button, int x, int y, t_param *param);
int		mouse_hook_release(int button, int x, int y, t_param *param);

void	line_put_image(t_param *param, int x1, int y1, int x2, int y2, int point1, int point2);
void	pixel_put_image(t_param *param, int x, int y, int color);

void	get_map_dimensions(char *file, t_param *param);
void	get_map_data(char *file, t_param *param);

void	draw_map(t_param *param);

float	map(float value, float istart, float istopk, float ostart, float ostop);

int		gradient(int colour1, int colour2, float factor);

#endif
