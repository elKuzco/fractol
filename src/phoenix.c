/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoenix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:45:06 by qlouisia          #+#    #+#             */
/*   Updated: 2019/12/02 19:38:21 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../libft/libft.h"
#include <math.h>

void initialise_fractal_phoenix(t_lst_display *win)
{
	win->Minreal = -2.5;
	win->Minima = -2.2;
	win->Maxreal = 0.0;
	win->Maxima = win->Minima + (win->Maxreal - win->Minreal) * (win->display_h / win->display_w);
	win->Real_scale = (win->Maxreal - win->Minreal) / win->display_w;
	win->Ima_scale = (win->Maxima - win->Minima) / win->display_h;
	win->julia_re = 0.56667;
	win->julia_im = -0.5;
	win->pt_function_init = &initialise_fractal_phoenix;
	win->pt_function = &phoenix;
	win->zoom_scale = 150;
	win->julia_mod_enable = false;
	set_color_to_mode1(win);
	refresh_image(win);
}

int phoenix_compute(t_lst_display *win, double c_im, int x)
{
	t_complex c;
	int i;
	double old;

	i = 0;
	c.c_re = x / win->zoom_scale + win->Minreal;
	c.z_re = c.c_re;
	c.z_im = c_im;
	while (i < win->Max_it)
	{
		old = c.z_re + c.z_im;
		c.z_re2 = c.z_re * c.z_re;
		c.z_im2 = c.z_im * c.z_im;
		if (c.z_re2 + c.z_im2 > 4)
			break;
		c.z_im = c.z_re * c.z_im;
		c.z_im += c.z_im;
		c.z_im += win->julia_im * old;
		c.z_re = c.z_re2 - c.z_im2 + win->julia_re;
		c.z_re2 = sqrt(c.z_re);
		c.z_im2 = sqrt(c.z_im);
		i++;
	}
	return (i);
}

void phoenix(t_lst_display *win, int start)
{
	int x;
	int y;
	double c_im;
	unsigned int color;
	int xmax;

	y = 0;
	xmax = start + win->display_w / THREAD_NUMBER;
	while (y < win->display_h)
	{
		c_im = y / win->zoom_scale + win->Minima;
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
