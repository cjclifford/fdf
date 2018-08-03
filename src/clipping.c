/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 11:49:53 by ccliffor          #+#    #+#             */
/*   Updated: 2018/07/31 11:50:47 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void  point_clip(t_p2d *p, float w, float h, float m, float im)
{
	t_p2d  clamped;

	if (p->x >= 0 && p->x < w && p->y >= 0 && p->y < h)
	return ;
	clamped.x = CLAMP(p->x, 0, w - 1.0f);
	if (isfinite(m))
	{
	if (p->x < 0)
		p->y = m * (0 - p->x) + p->y;
	else if (p->x > w)
		p->y = m * (w - 1.0f - p->x) + p->y;
	}
	clamped.y = CLAMP(p->y, 0, h - 1.0f);
	p->x = clamped.x;
	if (isfinite(im))
	{
	if (p->y < 0)
		p->x = im * (0 - p->y) + p->x;
	else if (p->y > h)
		p->x = im * (h - 1.0f - p->y) + p->x;
	}
	p->y = clamped.y;
}

static void  line_clip(t_p2d *a, t_p2d *b, float w, float h)
{
	const float m = (b->y - a->y) / (b->x - a->x);
	const float im = (b->x - a->x) / (b->y - a->y);

	point_clip(a, w, h, m, im);
	point_clip(b, w, h, m, im);
}