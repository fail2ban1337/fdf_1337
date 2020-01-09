/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 19:57:15 by abelomar          #+#    #+#             */
/*   Updated: 2018/10/31 20:17:40 by abelomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		*ft_strndup(const char *s1)
{
	char	*rang;
	int		counter;
	int		i;

	i = ft_strlen(s1) - ft_strlen(ft_memchr(s1, '\n', ft_strlen(s1)));
	counter = 0;
	rang = (char *)malloc(i + 1 * sizeof(char));
	if (!rang)
		return (0);
	while (s1[counter] != '\n')
	{
		rang[counter] = s1[counter];
		counter++;
	}
	rang[counter] = '\0';
	return (rang);
}

int			ft_rtnp(char *src[], int fd)
{
	int		counter;

	counter = 0;
	while (src[fd][counter] != '\n' && src[fd][counter] != '\0')
		counter++;
	return (counter);
}

int			ft_filline(char **line, char *temp[], int fd)
{
	if (ft_strchr(temp[fd], '\n'))
	{
		*line = ft_strndup(temp[fd]);
		temp[fd] = ft_strdup(temp[fd] + 1 + ft_rtnp(temp, fd));
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			rtn;
	static char	*temp[256];

	if (fd < 0 || line == NULL || read(fd, buf, 0))
		return (-1);
	temp[fd] = (temp[fd] != NULL) ? temp[fd] : ft_strnew(10);
	if (ft_filline(line, temp, fd))
		return (1);
	while ((rtn = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rtn] = '\0';
		temp[fd] = ft_strjoin(temp[fd], buf);
		if (ft_filline(line, temp, fd))
			return (1);
	}
	if (rtn == 0 && temp[fd][0] != '\0')
	{
		*line = ft_strdup(temp[fd]);
		ft_strdel(&temp[fd]);
		return (1);
	}
	return (0);
}
