/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emayert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 04:13:27 by emayert           #+#    #+#             */
/*   Updated: 2018/12/25 04:13:30 by emayert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static	void	put_pix(t_point *p, t_storage *b)
{
	mlx_pixel_put(b->pmlx, b->pwin, b->ofsx + p->x, b->ofsy + p->y, p->color);
}

void			draw_line(t_point src, t_point dst, t_storage *b)
{
	t_line	line;
	t_point	s;
	t_point d;

	s = (t_point) {(int)src.x, (int)src.y, src.z, src.color};
	d = (t_point) {(int)dst.x, (int)dst.y, dst.z, dst.color};
	line = (t_line)	{ft_abs(d.x - s.x), ft_abs(d.y - s.y),
					(s.x < d.x ? 1 : -1), (s.y < d.y ? 1 : -1), 0, 0};
	line.err = line.dx - line.dy;
	put_pix(&d, b);
	while (s.x != d.x || s.y != d.y)
	{
		put_pix(&s, b);
		line.err2 = line.err * 2;
		if (line.err2 > -line.dy)
		{
			line.err -= line.dy;
			s.x += line.signx;
		}
		if (line.err2 < line.dx)
		{
			line.err += line.dx;
			s.y += line.signy;
		}
	}
}

void			clear_screen(t_storage *b)
{
	mlx_clear_window(b->pmlx, b->pwin);
	mlx_string_put(b->pmlx, b->pwin, 5, 15, 0x00ff00,
					"(ESC)          QUIT");
	mlx_string_put(b->pmlx, b->pwin, 5, 30, 0x00ff00,
					"(7 / 9)        Rotate aroud Z axis");
	mlx_string_put(b->pmlx, b->pwin, 5, 45, 0x00ff00,
					"(4 / 6)        Rotate aroud Y axis");
	mlx_string_put(b->pmlx, b->pwin, 5, 60, 0x00ff00,
					"(1 / 3)        Rotate aroud X axis");
	mlx_string_put(b->pmlx, b->pwin, 5, 75, 0x00ff00,
					"(+ / -)        Object scaling");
	mlx_string_put(b->pmlx, b->pwin, 5, 90, 0x00ff00,
					"(2 / 8)        Altitude scaling");
	mlx_string_put(b->pmlx, b->pwin, 5, 105, 0x00ff00,
					"(Arrows keys)  Translate");
}
