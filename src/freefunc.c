/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 22:20:01 by abelomar          #+#    #+#             */
/*   Updated: 2019/05/18 22:30:29 by abelomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	freefunc(void *ptr)
{
	int		i;
	t_ptr	*ptr1;

	ptr1 = (t_ptr *)ptr;
	i = 0;
	free(ptr1->mlx_ptr);
	free(ptr1->win_ptr);
	free(ptr1->line);
	while (ptr1->strspl[i])
		free(ptr1->strspl[i++]);
	free(ptr1->strspl);
	free(ptr1);
}
