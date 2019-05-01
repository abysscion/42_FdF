/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emayert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:35:27 by emayert           #+#    #+#             */
/*   Updated: 2019/01/10 19:35:30 by emayert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static	int	rotation_hook(int key, t_storage *p)
{
	if ((key > 82 && key < 93) && key != 84 && key != 91)
	{
		if (key == 89)
			turn_pmat(p, -0.35, 'z');
		else if (key == 92)
			turn_pmat(p, 0.35, 'z');
		else if (key == 83)
			turn_pmat(p, -0.35, 'x');
		else if (key == 85)
			turn_pmat(p, 0.35, 'x');
		else if (key == 88)
			turn_pmat(p, -0.35, 'y');
		else if (key == 86)
			turn_pmat(p, 0.35, 'y');
		return (1);
	}
	return (0);
}

static	int	translation_hook(int key, t_storage *p)
{
	if (key > 122 && key < 127)
	{
		if (key == 123)
			translate_pmat(-p->scale, 0, p);
		else if (key == 125)
			translate_pmat(0, p->scale, p);
		else if (key == 124)
			translate_pmat(p->scale, 0, p);
		else if (key == 126)
			translate_pmat(0, -p->scale, p);
		return (1);
	}
	return (0);
}

static	int	resize_hook(int key, t_storage *p)
{
	if (key == 78 || key == 69)
	{
		if (key == 78)
			resize_mat(p, -2);
		else if (key == 69)
			resize_mat(p, 2);
		return (1);
	}
	return (0);
}

static	int	altitude_hook(int key, t_storage *p)
{
	if (key == 91 || key == 84)
	{
		if (key == 84)
			realt_mat(-3, p);
		else if (key == 91)
			realt_mat(3, p);
		return (1);
	}
	return (0);
}

int			deal_key(int key, void *param)
{
	t_storage	*p;

	p = param;
	if (key == 53)
	{
		mlx_destroy_window(p->pmlx, p->pwin);
		free_box(p);
		exit(0);
	}
	if (altitude_hook(key, p) || rotation_hook(key, p) ||
		translation_hook(key, p) || resize_hook(key, p))
	{
		clear_screen(p);
		draw_mat(p);
	}
	return (0);
}
