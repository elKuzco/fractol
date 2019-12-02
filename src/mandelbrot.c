/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 15:52:03 by qlouisia          #+#    #+#             */
/*   Updated: 2019/12/02 18:51:15 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../libft/libft.h"
#include <math.h>

void	initialise_fractal_mandel(t_lst_display *win)
{
	win->Minreal = -2.0;
	win->Minima = -1.2;
	win->Maxreal = 1.0;
	win->Maxima = win->Minima + (win->Maxreal - win->Minreal)
	* (win->display_h / win->display_w);
	win->Real_scale = (win->Maxreal - win->Minreal) / win->display_w;
	win->Ima_scale = (win->Maxima - win->Minima) / win->display_h;
	win->Max_it = 30;
	win->zoom_scale = 250;
	win->pt_function = &mandelbrot;
	win->julia_mod_enable = false;
	win->clr_m = 1;
	win->pt_function_init = &initialise_fractal_mandel;
	set_color_to_mode1(win);
	refresh_image(win);
}

int		is_in_bulb(double c_re, double c_im)
{
	double p;

	p = sqrt(pow((c_re - 0.25), 2) + pow(c_im, 2));
	if (c_re < (p - 2 * pow(p, 2) + 0.25))
		return (1);
	else if ((pow(c_re + 1, 2) + pow(c_im, 2)) <= 0.0625)
		return (1);
	return (0);
}

int		mandelbrot_compute(t_lst_display *win, double c_im, int x)
{
	t_complex	c;
	int			i;

	i = 0;
	c.c_re = x / win->zoom_scale + win->Minreal;
	if (is_in_bulb(c.c_re, c_im) == 0)
	{
		c.z_re = c.c_re;
		c.z_im = c_im;
		while (i < win->Max_it)
		{
			c.z_re2 = c.z_re * c.z_re;
			c.z_im2 = c.z_im * c.z_im;
			if (c.z_re2 + c.z_im2 > 4)
				break ;
			c.z_im = c.z_re * c.z_im;
			c.z_im += c.z_im;
			c.z_im += c_im;
			c.z_re = c.z_re2 - c.z_im2 + c.c_re;
			c.z_re2 = sqrt(c.z_re);
			c.z_im2 = sqrt(c.z_im);
			i++;
		}
	}
	return (i);
}

void	mandelbrot(t_lst_display *win, int start)
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
			color = colormod(mandelbrot_compute(win, c_im, x), win);
			fill_pix(win, x, y, color);
			x++;
		}
		y++;
	}
}
