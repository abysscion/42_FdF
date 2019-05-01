/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emayert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 19:35:27 by emayert           #+#    #+#             */
/*   Updated: 2018/12/23 19:35:30 by emayert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int				main(int argc, char **argv)
{
	t_storage	*box;

	box = (t_storage *)malloc(sizeof(t_storage));
	init_box(box);
	if (argc == 2 && read_file(argv[1], box))
	{
		config_box(box);
		init_pmat(box);
		init_mlxlib(box);
		draw_mat(box);
		mlx_key_hook(box->pwin, deal_key, box);
		mlx_loop(box->pmlx);
		return (0);
	}
	free_box(box);
	ft_putendl("error");
	return (0);
}
