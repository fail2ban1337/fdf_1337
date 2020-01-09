/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   designfdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 23:49:29 by abelomar          #+#    #+#             */
/*   Updated: 2019/05/18 07:55:29 by abelomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		design(t_senddxy *senddxy, t_ptr *ptr)
{
	t_dxy	*dxy;

	dxy = (t_dxy *)malloc(sizeof(t_dxy));
	dxy->dx = abs(senddxy->x1 - senddxy->x0);
	dxy->sx = senddxy->x0 < senddxy->x1 ? 1 : -1;
	dxy->dy = abs(senddxy->y1 - senddxy->y0);
	dxy->sy = senddxy->y0 < senddxy->y1 ? 1 : -1;
	dxy->err = (dxy->dx > dxy->dy ? dxy->dx : -dxy->dy) / 2;
	while (senddxy->x0 != senddxy->x1 || senddxy->y0 != senddxy->y1)
	{
		mlx_pixel_put(ptr->mlx_ptr, ptr->win_ptr
				, senddxy->x0 + 400, senddxy->y0 + 400, 0xC2FF0D);
		dxy->e2 = dxy->err;
		if (dxy->e2 > -dxy->dx)
		{
			dxy->err -= dxy->dy;
			senddxy->x0 += dxy->sx;
		}
		if (dxy->e2 < dxy->dy)
		{
			dxy->err += dxy->dx;
			senddxy->y0 += dxy->sy;
		}
	}
	free(dxy);
}
