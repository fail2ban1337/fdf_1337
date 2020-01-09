/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 23:53:58 by abelomar          #+#    #+#             */
/*   Updated: 2019/05/18 07:39:35 by abelomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	iso(int *x, int *y, int z)
{
	int		previous_x;
	int		previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z * 2 + (previous_x + previous_y) * sin(0.523599);
}

void		calcule(int tm, int **tab, t_ptr *ptr)
{
	t_senddxy *senddxy;

	senddxy = (t_senddxy *)malloc(sizeof(t_senddxy));
	if (tm == 0)
	{
		senddxy->x0 = (ptr->i - ptr->width / 2) * 20;
		senddxy->y0 = (ptr->c - ptr->height / 2) * 20;
		senddxy->x1 = ((ptr->i + 1) - ptr->width / 2) * 20;
		senddxy->y1 = (ptr->c - ptr->height / 2) * 20;
		iso(&senddxy->x0, &senddxy->y0, tab[ptr->c][ptr->i]);
		iso(&senddxy->x1, &senddxy->y1, tab[ptr->c][ptr->i + 1]);
		design(senddxy, ptr);
	}
	else
	{
		senddxy->x0 = (ptr->c - ptr->width / 2) * 20;
		senddxy->y0 = (ptr->i - ptr->height / 2) * 20;
		senddxy->x1 = (ptr->c - ptr->width / 2) * 20;
		senddxy->y1 = ((ptr->i + 1) - ptr->height / 2) * 20;
		iso(&senddxy->x0, &senddxy->y0, tab[ptr->i][ptr->c]);
		iso(&senddxy->x1, &senddxy->y1, tab[ptr->i + 1][ptr->c]);
		design(senddxy, ptr);
	}
	free(senddxy);
}

void		draw(int **tab, t_ptr *ptr)
{
	ptr->i = 0;
	while (ptr->i < ptr->width - 1)
	{
		ptr->c = 0;
		while (ptr->c < ptr->height)
		{
			calcule(ptr->rtn, tab, ptr);
			ptr->c++;
		}
		ptr->i++;
	}
	ptr->i = 0;
	ptr->rtn = 1;
	while (ptr->i < ptr->height - 1)
	{
		ptr->c = 0;
		while (ptr->c < ptr->width)
		{
			calcule(ptr->rtn, tab, ptr);
			ptr->c++;
		}
		ptr->i++;
	}
}
