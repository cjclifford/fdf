/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 14:31:51 by ccliffor          #+#    #+#             */
/*   Updated: 2018/07/23 12:24:43 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_map_dimensions(char *file, t_param *param)
{
	char	**list;
	char	*line;
	int		fd;
	size_t	i;

	fd = open(file, O_RDONLY);
	param->size_z = 0;
	param->size_x = 0;
	while (get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, ' ');
		i = 0;
		while (list[i])
			i++;
		if (param->size_z == 0)
			param->size_x = i;
		else if (i < param->size_x)
			return ;// return a map size error
		param->size_z++;
	}
	close(fd);
}

void	get_map_data(char *file, t_param *param)
{
	char	**list;
	char	*line;
	int		z;
	int		x;
	int		fd;

	param->points = (t_point *)malloc(sizeof(t_point) * (param->size_z * param->size_x));
	fd = open(file, O_RDONLY);
	z = 0;
	while (get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, ' ');
		x = 0;
		while (list[x])
		{
			param->points[x + z * param->size_x][0] = x;
			if (atoi(list[x]) > (int)param->size_y)
				param->size_y = atoi(list[x]);
			param->points[x + z * param->size_x][1] = atoi(list[x]);
			param->points[x + z * param->size_x][2] = z;
			if (ft_strchr(list[x], 'x'))
				param->points[x + z * param->size_x][3] = strtol(ft_strchr(list[x], 'x') + 1, NULL, 16);
			else
				param->points[x + z * param->size_x][3] = 0xFFFFFF;
			x++;
		}
		free(list[x]);
		free(list);
		z++;
	}
	close(fd);
}
