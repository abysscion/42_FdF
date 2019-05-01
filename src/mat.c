/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emayert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:35:27 by emayert           #+#    #+#             */
/*   Updated: 2019/01/12 19:35:30 by emayert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	resize_mat(t_storage *box, int size)
{
	box->scale += size;
	recalc_pmat(box);
}

void	realt_mat(int alt, t_storage *box)
{
	int	i;
	int	j;
	int	dpossib;

	dpossib = 1;
	i = -1;
	while (++i < box->rows)
	{
		j = -1;
		while (++j < box->cols)
			if (box->mat[i][j] != 0)
				if (box->mat[i][j] / -alt == 0)
					dpossib = 0;
	}
	i = -1;
	while (++i < box->rows)
	{
		j = -1;
		while (++j < box->cols)
			if (alt > 0)
				box->mat[i][j] *= alt;
			else if (dpossib)
				box->mat[i][j] /= -alt;
	}
	recalc_pmat(box);
}

void	draw_mat(t_storage *box)
{
	int	i;
	int	j;

	i = -1;
	while (++i < box->rows)
	{
		j = -1;
		while (++j < box->cols)
		{
			if (j + 1 < box->cols)
				draw_line(box->pmat->mat[i][j], box->pmat->mat[i][j + 1], box);
			if (i + 1 < box->rows)
				draw_line(box->pmat->mat[i][j], box->pmat->mat[i + 1][j], box);
		}
	}
}
