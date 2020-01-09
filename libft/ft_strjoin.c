/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 19:16:52 by abelomar          #+#    #+#             */
/*   Updated: 2018/10/31 13:42:49 by abelomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (s1 && s2)
	{
		ptr = ft_strnew(i + j);
		if (!ptr)
			return (0);
		else
		{
			ft_strcat(ptr, s1);
			ft_strcat(ptr, s2);
			return (ptr);
		}
	}
	return (0);
}
