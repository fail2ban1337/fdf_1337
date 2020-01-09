/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 23:00:37 by abelomar          #+#    #+#             */
/*   Updated: 2019/05/18 08:40:00 by abelomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include "mlx.h"
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# define BUFF_SIZE  10000

typedef	struct	s_ptr
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		fd;
	int		c;
	int		i;
	int		check;
	int		rtn;
	int		rtm;
	int		height;
	int		width;
	char	*line;
	char	**strspl;
}				t_ptr;

typedef	struct	s_dxy
{
	int	dx;
	int	dy;
	int	err;
	int	e2;
	int	sx;
	int	sy;
}				t_dxy;

typedef struct	s_senddxy
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
}				t_senddxy;

int				get_next_line(const int fd, char **line);
void			draw(int **tab, t_ptr *ptr);
void			design(t_senddxy *senddxy, t_ptr *ptr);
void			freefunc(void *ptr);

#endif
