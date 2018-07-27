/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_put_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 14:30:03 by ccliffor          #+#    #+#             */
/*   Updated: 2018/07/23 15:51:09 by ccliffor         ###   ########.fr       */
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

// void	line_put_image(t_param *param, int x1, int y1, int x2, int y2, int point1, int point2)
// {
// 	(void)param;
// 	(void)point1;
// 	(void)point2;
// 	int	*x = &x1;
// 	int	*y = &y1;
// 	int	dx = x2 - x1;
// 	int	dy = y2 - y1;
// 	// if (abs(x1 - x2) >= abs(y1 - y2))
// 	// {
// 	// 	x = &x1;
// 	// 	y = &y1;
// 	// }
// 	// else
// 	// {
// 	// 	swap(&x1, &y1);
// 	// 	swap(&x2, &y2);
// 	// 	x = &y1;
// 	// 	y = &x1;
// 	// }
// 	while (*x < x2)
// 	{
// 		y1 += dy * (*x - x1) / dx;
// 		pixel_put_image(param, *x, *y, 0xFFFFFF);
// 		x1++;
// 	}
// }

void	line_put_image(t_param *param, int x1, int y1, int x2, int y2, int point1, int point2)
{
	double	slope;
	double	offset;
	int		iterate;
	int		start;
	int		*x;
	int		*y;

	slope = 0;
	offset = 0;
	if (abs(x1 - x2) >= abs(y1 - y2))
	{
		x = &x1;
		y = &y1;
	}
	else
	{
		swap(&x1, &y1);
		swap(&x2, &y2);
		x = &y1;
		y = &x1;
	}
	start = x1;
	iterate = -1 + (2 * (x1 < x2));
	slope = ((double)abs(y1 - y2) / (double)abs(x1 - x2)) * (-1 + (2 * (y1 < y2)));
	while (x1 != x2)
	{
		if (offset >= 0.5 || offset <= -0.5)
		{
			offset -= -1 + (2 * (y1 < y2));
			y1 += -1 + (2 * (y1 < y2));
		}
		// (void) point1;
		// pixel_put_image(param, *x, *y, param->points[point2][3]);
		pixel_put_image(param, *x, *y, gradient(param->points[point1][3], param->points[point2][3], map(*x, start, x2, 0, 1)));
		// if (param->points[point1][3] != 0xFFFFFF)
			// printf("x: %d, map(x): %f, colour: %d\n", *x, map(*x, start, x2, 0, 1), gradient(param->points[point1][3], param->points[point2][3], map(*x, start, x2, 0, 1)));
		x1 += iterate;
		offset += slope;
	}
	// if (param->points[point1][3] != 0xFFFFFF)
	// 	printf("\n");
}
