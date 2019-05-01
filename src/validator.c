/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emayert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:35:27 by emayert           #+#    #+#             */
/*   Updated: 2018/12/29 19:35:30 by emayert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static	int	is_cols_valid(t_vld_storage *bin, t_rdr_storage *box)
{
	char	**arr;
	int		result;
	int		i;

	result = 1;
	i = 0;
	arr = ft_strsplit(bin->cont, '\n');
	box->cols = ft_wordsnum(arr[0], ' ');
	while (arr[i])
	{
		if (ft_wordsnum(arr[i], ' ') != box->cols)
			result = 0;
		free(arr[i++]);
	}
	box->rows = i;
	free(arr);
	return (result);
}

static	int	is_nums_valid(t_vld_storage *bin)
{
	char	**arr;
	int		result;

	result = 1;
	bin->i = 0;
	ft_memrepl(bin->cont, '\n', ' ');
	arr = ft_strsplit(bin->cont, ' ');
	while (arr[bin->i])
	{
		bin->min_cnt = 0;
		bin->num_cnt = 0;
		bin->j = -1;
		while (arr[bin->i][++bin->j] && result)
			if (arr[bin->i][bin->j] == '-')
				++bin->min_cnt;
			else if (arr[bin->i][bin->j] != '\n')
				++bin->num_cnt;
		if (bin->min_cnt > 1 ||
			(arr[bin->i][0] == '-' && !ft_isdigit(arr[bin->i][1])))
			result = 0;
		free(arr[bin->i++]);
	}
	free(arr);
	return (result);
}

int			is_content_valid(t_rdr_storage *box)
{
	t_vld_storage	*bin;
	int				result;

	bin = (t_vld_storage *)malloc(sizeof(t_vld_storage));
	result = 0;
	bin->cont = box->fcont;
	bin->size = box->fsize;
	if (is_cols_valid(bin, box))
		if (is_nums_valid(bin))
			result = 1;
	free(bin);
	return (result);
}
