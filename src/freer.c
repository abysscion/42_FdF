/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emayert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:35:27 by emayert           #+#    #+#             */
/*   Updated: 2019/01/10 19:35:30 by emayert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_box(t_storage *box)
{
	int i;

	if (box->mat)
	{
		i = -1;
		while (++i < box->rows)
			free(box->mat[i]);
		free(box->mat);
	}
	if (box->pmat)
	{
		if (box->pmat->mat)
		{
			i = -1;
			while (++i < box->rows)
				free(box->pmat->mat[i]);
			free(box->pmat->mat);
		}
		free(box->pmat);
	}
	free(box);
	box = NULL;
}
