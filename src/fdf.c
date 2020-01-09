/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:56:13 by abelomar          #+#    #+#             */
/*   Updated: 2019/05/18 22:43:27 by abelomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_press(int key, t_ptr *ptr)
{
	if (key == 53)
	{
		mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
		exit(0);
	}
	return (0);
}

int			**ft_filli(int width, int height, char *str)
{
	int		**tabl;
	char	*line;
	char	**strspl;
	t_ptr	*ptr1;

	ptr1 = (t_ptr*)malloc(sizeof(t_ptr));
	ptr1->c = 0;
	ptr1->fd = open(str, O_RDONLY);
	tabl = (int **)malloc(sizeof(int *) * height);
	while ((ptr1->rtn = get_next_line(ptr1->fd, &line)) > 0)
	{
		ptr1->i = 0;
		tabl[ptr1->c] = (int *)malloc(sizeof(int) * width);
		strspl = ft_strsplit(line, ' ');
		while (strspl[ptr1->i])
		{
			tabl[ptr1->c][ptr1->i] = ft_atoi(strspl[ptr1->i]);
			ptr1->i++;
		}
		ptr1->c++;
	}
	return (tabl);
}

int			**gethwnb(int fd, char *str, int rtm)
{
	t_ptr	*ptr;
	int		**tab;

	ptr = (t_ptr *)malloc(sizeof(t_ptr));
	ptr->width = 0;
	ptr->height = 0;
	while ((ptr->rtn = get_next_line(fd, &ptr->line)) > 0)
	{
		ptr->height++;
		ptr->strspl = ft_strsplit(ptr->line, ' ');
		while (ptr->strspl[ptr->width])
			ptr->width++;
		if (rtm == 0)
			rtm = ptr->width;
		if (rtm != ptr->width)
			return (0);
	}
	tab = ft_filli(ptr->width, ptr->height, str);
	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, 800, 800, "FDF 1337");
	draw(tab, ptr);
	mlx_hook(ptr->win_ptr, 2, 1, key_press, (void *)ptr);
	mlx_loop(ptr->mlx_ptr);
	freefunc(ptr);
	return (0);
}

int			main(int ac, char **av)
{
	int fd;
	int rtm;

	rtm = 0;
	if (ac != 2)
	{
		ft_putendl("error");
		return (0);
	}
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
		{
			ft_putendl("error");
			return (0);
		}
		gethwnb(fd, av[1], rtm);
	}
	return (0);
}
