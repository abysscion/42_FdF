/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emayert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:35:27 by emayert           #+#    #+#             */
/*   Updated: 2019/01/18 19:35:30 by emayert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	turn_point(t_point *src, double a, char axis)
{
	t_point	p;
	double	cosa;
	double	sina;

	cosa = cos(a);
	sina = sin(a);
	p = *src;
	if (axis == 'x')
	{
		p.y = src->y * cosa - src->z * sina;
		p.z = src->y * sina + src->z * cosa;
	}
	else if (axis == 'y')
	{
		p.x = src->x * cosa - src->z * sina;
		p.z = src->x * sina + src->z * cosa;
	}
	else if (axis == 'z')
	{
		p.x = src->x * cosa - src->y * sina;
		p.y = src->x * sina + src->y * cosa;
	}
	src->x = p.x;
	src->y = p.y;
	src->z = p.z;
}
