/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 20:34:59 by qlouisia          #+#    #+#             */
/*   Updated: 2019/12/02 19:36:52 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../libft/libft.h"
#include <math.h>

void	initialise_fractal_mandel3(t_lst_display *win)
{
	win->Minreal = -2.0;
	win->Minima = -1.2;
	win->Maxreal = 1.0;
	win->Maxima = win->Minima + (win->Maxreal - win->Minreal)
	* (win->display_h / win->display_w);
	win->Real_scale = (win->Maxreal - win->Minreal) / win->display_w;
	win->Ima_scale = (win->Maxima - win->Minima) / win->display_h;
	win->Max_it = 20;
	win->zoom_scale = 250;
	win->pt_function = &mandel3;
	win->julia_mod_enable = false;
	win->pt_function_init = &initialise_fractal_mandel3;
	win->clr_m = 1;
	set_color_to_mode1(win);
	refresh_image(win);
}

int		mandelbrot_compute3(t_lst_display *win, double c_im, int x)
{
	t_complex	c;
	int			i;
	double		tmp;

	i = 0;
	c.c_re = x / win->zoom_scale + win->Minreal;
	c.z_re = c.c_re;
	c.z_im = c_im;
	while (i < win->Max_it)
	{
		c.z_re2 = c.z_re * c.z_re;
		c.z_im2 = c.z_im * c.z_im;
		if (c.z_re2 + c.z_im2 > 4)
			break ;
		tmp = c.z_re;
		c.z_re = (pow(c.z_re, 3) - 3 * c.z_re * pow(c.z_im, 2));
		c.z_im = ((3 * pow(tmp, 2) * c.z_im) - (pow(c.z_im, 3)));
		c.z_re += c.c_re;
		c.z_im += c_im;
		i++;
	}
	return (i);
}

void	mandel3(t_lst_display *win, int start)
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
		c_im = y / win->zoom_scale + win->Minima;
		x = start;
		while (x < xmax)
		{
			color = colormod(mandelbrot_compute3(win, c_im, x), win);
			fill_pix(win, x, y, color);
			x++;
		}
		y++;
	}
}
