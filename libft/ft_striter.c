/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 16:55:45 by abelomar          #+#    #+#             */
/*   Updated: 2018/10/16 17:28:47 by abelomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void (*f)(char *))
{
	if (f)
		if (s)
			while (*s)
			{
				f(s++);
			}
}
