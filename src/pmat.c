/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emayert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 19:35:27 by emayert           #+#    #+#             */
/*   Updated: 2019/01/19 19:35:30 by emayert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static	void	fill_pmat(t_storage *box)
{
	int	i;
	int	j;

	i = -1;
	while (++i < box->rows)
	{
		j = -1;
		while (++j < box->cols)
		{
			box->pmat->mat[i][j].x = box->scale * (j - box->cols / 2) +
				(box->scale / 2) - (box->cols % 2 * box->scale / 2);
			box->pmat->mat[i][j].y = box->scale * (i - box->rows / 2) +
				(box->scale / 2) - (box->rows % 2 * box->scale / 2);
			box->pmat->mat[i][j].z = box->scale * box->mat[i][j];
			box->pmat->mat[i][j].color = 0x00aaee;
		}
	}
}

void			turn_pmat(t_storage *box, double angle, char axis)
{
	int	i;
	int	j;

	i = -1;
	while (++i < box->rows)
	{
		j = -1;
		while (++j < box->cols)
			turn_point(&box->pmat->mat[i][j], angle, axis);
	}
	if (axis == 'x')
		box->pmat->anglex += angle;
	else if (axis == 'y')
		box->pmat->angley += angle;
	else if (axis == 'z')
		box->pmat->anglez += angle;
}

void			translate_pmat(int dx, int dy, t_storage *box)
{
	int	i;
	int	j;

	i = -1;
	while (++i < box->rows)
	{
		j = -1;
		while (++j < box->cols)
		{
			box->pmat->mat[i][j].x += dx;
			box->pmat->mat[i][j].y += dy;
		}
	}
}

void			recalc_pmat(t_storage *box)
{
	double	tmpx;
	double	tmpy;
	double	tmpz;

	tmpx = box->pmat->anglex;
	tmpy = box->pmat->angley;
	tmpz = box->pmat->anglez;
	box->pmat->anglex = 0;
	box->pmat->angley = 0;
	box->pmat->anglez = 0;
	fill_pmat(box);
	turn_pmat(box, tmpx, 'x');
	turn_pmat(box, tmpy, 'y');
	turn_pmat(box, tmpz, 'z');
}

void			init_pmat(t_storage *box)
{
	int		i;

	i = -1;
	box->pmat = (t_pmat *)malloc(sizeof(t_pmat));
	box->pmat->mat = (t_point **)malloc(sizeof(t_point *) * box->rows);
	while (++i < box->rows)
		box->pmat->mat[i] = (t_point *)malloc(sizeof(t_point) * box->cols);
	box->pmat->anglex = 0;
	box->pmat->angley = 0;
	box->pmat->anglez = 0;
	fill_pmat(box);
}
