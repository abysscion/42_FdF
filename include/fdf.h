/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emayert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 19:35:27 by emayert           #+#    #+#             */
/*   Updated: 2018/12/23 19:35:30 by emayert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define DEF_WINSZ 500
# define DEF_SCALE 25

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "../lib/libmlx/mlx.h"
# include "../lib/libft/libft.h"

typedef	struct	s_point
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_point;

typedef	struct	s_line
{
	double		dx;
	double		dy;
	int			signx;
	int			signy;
	double		err;
	double		err2;
}				t_line;

typedef	struct	s_pmat
{
	t_point		**mat;
	double		anglex;
	double		angley;
	double		anglez;
	int			ofsx;
	int			ofsy;
}				t_pmat;

typedef struct	s_storage
{
	t_pmat		*pmat;
	void		*pmlx;
	void		*pwin;
	char		*name;
	int			**mat;
	int			cols;
	int			rows;
	int			ofsx;
	int			ofsy;
	int			matl;
	int			matw;
	int			scale;
	int			winsizex;
	int			winsizey;
}				t_storage;

typedef	struct	s_vld_storage
{
	char		*cont;
	int			size;
	int			i;
	int			j;
	int			min_cnt;
	int			num_cnt;
}				t_vld_storage;

typedef	struct	s_rdr_storage
{
	char		*fcont;
	int			fsize;
	int			cols;
	int			rows;
}				t_rdr_storage;

int				**create_map(char *name);
int				deal_key(int key, void *param);
int				is_content_valid(t_rdr_storage	*box);
int				read_file(char *fname, t_storage *box);
int				deal_click(int button, int x, int y, void *param);
void			init_color(t_point *p);
void			init_box(t_storage *box);
void			free_box(t_storage *box);
void			draw_mat(t_storage *box);
void			init_pmat(t_storage *box);
void			config_box(t_storage *box);
void			recalc_pmat(t_storage *box);
void			init_mlxlib(t_storage *box);
void			clear_screen(t_storage *box);
void			realt_mat(int alt, t_storage *box);
void			resize_mat(t_storage *box, int size);
void			create_mat(t_storage *box, char *fcont);
void			free_mat(t_point ***mat, t_storage *box);
void			turn_point(t_point *src, double a, char axis);
void			translate_pmat(int dx, int dy, t_storage *box);
void			turn_pmat(t_storage *box, double angle, char axis);
void			draw_line(t_point src, t_point dst, t_storage *box);
t_point			init_point(int x, int y, int z);

#endif
