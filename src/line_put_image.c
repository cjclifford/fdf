/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_put_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 14:30:03 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/03 17:45:31 by ccliffor         ###   ########.fr       */
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

void		line_put_image(t_param *param, t_line line, int point1, int point2)
{
	double	slope;
	double	offset;
	int		iterate;
	int		*x;
	int		*y;

	(void)point2;

	slope = 0;
	offset = 0;
	if (abs(line[0] - line[2]) >= abs(line[1] - line[3]))
	{
		x = &line[0];
		y = &line[1];
	}
	else
	{
		swap(&line[0], &line[1]);
		swap(&line[2], &line[3]);
		x = &line[1];
		y = &line[0];
	}
	iterate = -1 + (2 * (line[0] < line[2]));
	slope = ((double)abs(line[1] - line[3]) / (double)abs(line[0] - line[2])) * \
	(-1 + (2 * (line[1] < line[3])));
	while (line[0] != line[2])
	{
		if (offset >= 0.5 || offset <= -0.5)
		{
			offset -= -1 + (2 * (line[1] < line[3]));
			line[1] += -1 + (2 * (line[1] < line[3]));
		}
		if ((*x < (int)param->width && *x > 0) || (*y < (int)param->height && *y > 0))
			pixel_put_image(param, *x, *y, (int)param->points[point1][3]);
		line[0] += iterate;
		offset += slope;
	}
}
