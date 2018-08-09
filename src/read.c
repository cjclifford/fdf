/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 14:31:51 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/09 18:24:37 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	wrong_line(void)
{
	ft_putstr_fd("Found wrong line length. Exiting.\n", 2);
	return (0);
}

static int	no_data(void)
{
	ft_putstr_fd("No data found.\n", 2);
	return (0);
}

int			get_map_dimensions(char *file, t_param *param)
{
	int		fd;
	int		i;
	char	*line;
	char	**list;

	fd = open(file, O_RDONLY);
	param->size_z = 0;
	while (get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, ' ');
		free(line);
		i = 0;
		while (list[i])
			free(list[i++]);
		free(list);
		if (param->size_z == 0)
			param->size_x = i;
		if (i < param->size_x)
			return (wrong_line());
		param->size_z++;
	}
	if (param->size_x == 0)
		return (no_data());
	close(fd);
	return (1);
}

static int	is_hex(char c)
{
	if (c >= 'A' && c <= 'F')
		return (1);
	else if (c >= 'a' && c <= 'f')
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	hex_to_dec(const char *s)
{
	int	max;
	int	ret;

	max = 1048576;
	ret = 0;
	while (*s && is_hex(*s))
	{
		if (*s >= 'A' && *s <= 'F')
			ret += (*s - 'A' + 10) * max;
		else if (*s >= 'a' && *s <= 'f')
			ret += (*s - 'a' + 10) * max;
		else
			ret += (*s - '0') * max;
		max /= 16;
		s++;
	}
	return (ret);
}

// void		get_map_data(char *file, t_param *param)
// {
// 	int		fd;
// 	char	*line;
// 	char	**list;

// 	param->points = (t_point *)malloc(sizeof(t_point) * (param->size_z *
// 		param->size_x));
// }

void		get_map_data(char *file, t_param *param)
{
	char	**list;
	char	*line;
	int		z;
	int		x;
	int		fd;

	param->points = (t_point *)malloc(sizeof(t_point) * (param->size_z *
		param->size_x));
	fd = open(file, O_RDONLY);
	param->size_y = 0;//unnecessary
	z = 0;
	while (get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, ' ');
		free(line);
		x = 0;
		while (list[x])
		{
			param->points[x + z * param->size_x][0] = x;
			if (atoi(list[x]) > (int)param->size_y)
				param->size_y = atoi(list[x]);
			param->points[x + z * param->size_x][1] = atoi(list[x]);
			param->points[x + z * param->size_x][2] = z;
			if (ft_strchr(list[x], 'x'))
				param->points[x + z * param->size_x][3] = hex_to_dec(ft_strchr(list[x], 'x') + 1);
			else
				param->points[x + z * param->size_x][3] = 0xFFFFFF;
			free(list[x]);
			x++;
		}
		z++;
		free(list);
	}
	close(fd);
}
