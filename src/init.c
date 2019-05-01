/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emayert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 04:13:27 by emayert           #+#    #+#             */
/*   Updated: 2018/12/25 04:13:30 by emayert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_mlxlib(t_storage *box)
{
	t_storage *p;

	p = box;
	p->pmlx = mlx_init();
	p->pwin = mlx_new_window(p->pmlx, p->winsizex, p->winsizey, p->name);
	clear_screen(box);
}

void	init_box(t_storage *box)
{
	t_storage *p;

	p = box;
	p->cols = 0;
	p->matl = 0;
	p->matw = 0;
	p->ofsx = 0;
	p->ofsy = 0;
	p->rows = 0;
	p->scale = 0;
	p->winsizex = 0;
	p->winsizey = 0;
	p->mat = 0x0;
	p->name = 0x0;
	p->pmat = 0x0;
	p->pmlx = 0x0;
	p->pwin = 0x0;
}
