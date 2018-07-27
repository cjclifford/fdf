/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 10:55:21 by ccliffor          #+#    #+#             */
/*   Updated: 2018/07/10 16:01:15 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		has_nl(const char *buff)
{
	while (*buff)
	{
		if (*buff == '\n')
			return (1);
		buff++;
	}
	return (0);
}

static char		*store_bytes(char **buff)
{
	char	*line;
	char	*p_buff;
	char	*tmp;
	size_t	i;

	i = 0;
	if (!buff || !*buff)
		return (NULL);
	while ((*buff)[i] && (*buff)[i] != '\n')
		i++;
	if (!(line = ft_strsub(*buff, 0, i)))
		return (NULL);
	p_buff = &(*buff)[i + ((*buff)[i] == '\n')];
	tmp = ft_strdup(p_buff);
	ft_strdel(buff);//----------------------------------------------------------
	*buff = tmp;
	return (line);
}

static int		read_more(const int fd, char **buff)
{
	char	more[BUFF_SIZE + 1];
	char	*tmp;
	ssize_t	br;

	if (!(br = read(fd, more, BUFF_SIZE)))
		return (0);
	else if (br < 0)
		return (-1);
	more[br] = '\0';
	tmp = ft_strjoin(*buff, more);
	ft_strdel(buff);//----------------------------------------------------------
	*buff = tmp;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*buff[1];
	int			read_ret;

	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	if (!buff[fd])
		buff[fd] = ft_strnew(1);
	while (!has_nl(buff[fd]))
	{
		if (!(read_ret = read_more(fd, &buff[fd])))
		{
			if (!buff[fd] || !*buff[fd])
				return (0);
			if (!(*line = store_bytes(&buff[fd])))
				return (-1);
			return (1);
		}
		else if (read_ret == -1)
			return (-1);
	}
	if (!(*line = store_bytes(&buff[fd])))
		return (-1);
	return (1);
}
