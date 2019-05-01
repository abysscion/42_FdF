/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_box.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emayert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:35:27 by emayert           #+#    #+#             */
/*   Updated: 2019/01/12 19:35:30 by emayert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static	void	calc_scale(t_storage *box)
{
	int	surp;
	int	sx;
	int	sy;

	surp = 0;
	sx = DEF_SCALE * box->cols;
	sy = DEF_SCALE * box->rows;
	while (sx > DEF_WINSZ || sy > DEF_WINSZ)
	{
		surp += 1;
		sx = (DEF_SCALE - surp) * box->cols;
		sy = (DEF_SCALE - surp) * box->rows;
	}
	box->scale = DEF_SCALE - surp;
}

void			config_box(t_storage *box)
{
	box->name = "Masterpiece :^)";
	calc_scale(box);
	box->winsizex = box->scale * box->cols * 2;
	box->winsizey = box->scale * box->rows * 2;
	box->ofsx = box->winsizex / 2;
	box->ofsy = box->winsizey / 2;
}
