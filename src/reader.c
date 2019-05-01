/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emayert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:35:27 by emayert           #+#    #+#             */
/*   Updated: 2018/12/28 19:35:30 by emayert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static	int		get_fsize(char *fname)
{
	char	buf[1];
	int		fd;
	int		size;

	if ((fd = open(fname, O_RDONLY)))
	{
		size = 0;
		while (read(fd, &buf, 1) > 0)
			++size;
		return (size);
	}
	return (-1);
}

void			create_mat(t_storage *box, char *fcont)
{
	char	**charr;
	char	**pcharr;
	int		i;
	int		j;
	int		k;

	i = -1;
	box->mat = (int **)malloc(sizeof(int *) * box->rows);
	while (++i < box->rows)
		box->mat[i] = (int *)malloc(sizeof(int) * box->cols);
	charr = ft_strsplit(fcont, ' ');
	pcharr = charr;
	i = -1;
	k = 0;
	while (++i < box->rows)
	{
		j = -1;
		while (++j < box->cols)
		{
			box->mat[i][j] = ft_atoi(charr[k]);
			free(charr[k++]);
		}
	}
	free(pcharr);
}

int				read_file(char *fname, t_storage *box)
{
	t_rdr_storage	*bin;

	bin = (t_rdr_storage *)malloc(sizeof(t_rdr_storage));
	if ((bin->fsize = get_fsize(fname)))
	{
		bin->fcont = (char *)malloc(bin->fsize + 1);
		if (read(open(fname, O_RDONLY), bin->fcont, bin->fsize) == bin->fsize)
		{
			bin->fcont[bin->fsize] = '\0';
			if (is_content_valid(bin))
			{
				box->cols = bin->cols;
				box->rows = bin->rows;
				create_mat(box, bin->fcont);
				free(bin->fcont);
				free(bin);
				return (1);
			}
		}
		free(bin->fcont);
	}
	free(bin);
	return (0);
}
