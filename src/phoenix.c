/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoenix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:45:06 by qlouisia          #+#    #+#             */
/*   Updated: 2019/12/04 13:30:15 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../libft/libft.h"
#include <math.h>

void	ini_fractal_phoenix(t_lst_display *win)
{
	win->minreal = -2.5;
	win->minima = -2.2;
	win->maxreal = 0.0;
	win->maxima = win->minima + (win->maxreal - win->minreal) *
	(win->display_h / win->display_w);
	win->real_scale = (win->maxreal - win->minreal) / win->display_w;
	win->ima_scale = (win->maxima - win->minima) / win->display_h;
	win->julia_re = 0.56667;
	win->julia_im = -0.5;
	win->pt_function_init = &ini_fractal_phoenix;
	win->pt_function = &phoenix;
	win->zoom_scale = 150;
	win->julia_mod_enable = false;
	set_color_to_mode1(win);
	refresh_image(win);
}

int		phoenix_compute(t_lst_display *win, double c_im, int x)
{
	t_complex	c;
	int			i;

	i = 0;
	c.c_re = x / win->zoom_scale + win->minreal;
	c.z_re = c.c_re;
	c.z_im = c_im;
	while (i < win->max_it)
	{
		c.z_re2 = c.z_re * c.z_re;
		c.z_im2 = c.z_im * c.z_im;
		if (c.z_re2 + c.z_im2 > 4)
			break ;
		c.z_im = 2 * fabs(c.z_re * c.z_im);
		c.z_im += c.z_im;
		c.z_re = c.z_re2 - c.z_im2 + c.c_re;
		c.z_re2 = sqrt(c.z_re);
		c.z_im2 = sqrt(c.z_im);
		i++;
	}
	return (i);
}

void	phoenix(t_lst_display *win, int start)
{
	int				x;
	int				y;
	double			c_im;
	unsigned int	color;
	int				xmax;

	y = 0;
	xmax = start + win->display_w / THREAD_NUMBER;
	while (y < win->display_h)
	{
		c_im = y / win->zoom_scale + win->minima;
		x = start;
		while (x < xmax)
		{
			color = colormod(phoenix_compute(win, c_im, x), win);
			fill_pix(win, x, y, color);
			x++;
		}
		y++;
	}
}
