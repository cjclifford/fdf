/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_put_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 14:30:03 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/09 16:20:11 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	get_swap(t_line line, int **x, int **y)
{
	*x = &line[0];
	*y = &line[1];
	if (abs(line[0] - line[2]) < abs(line[1] - line[3]))
	{
		swap(&line[0], &line[1]);
		swap(&line[2], &line[3]);
		*x = &line[1];
		*y = &line[0];
	}
}

void		line_put_image(t_param *p, t_line line, int point)
{
	double	slope;
	double	offset;
	int		iterate;
	int		*x;
	int		*y;

	offset = 0;
	x = &line[0];
	y = &line[1];
	get_swap(line, &x, &y);
	iterate = -1 + (2 * (line[0] < line[2]));
	slope = ((double)abs(line[1] - line[3]) / (double)abs(line[0] - line[2]))
		* (-1 + (2 * (line[1] < line[3])));
	while (line[0] != line[2])
	{
		if (offset >= 0.5 || offset <= -0.5)
		{
			offset -= -1 + (2 * (line[1] < line[3]));
			line[1] += -1 + (2 * (line[1] < line[3]));
		}
		if ((*x < (int)p->width && *x > 0) || (*y < (int)p->height && *y > 0))
			pixel_put_image(p, *x, *y, (int)p->points[point][3]);
		line[0] += iterate;
		offset += slope;
	}
}
