/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heart.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 19:48:02 by qlouisia          #+#    #+#             */
/*   Updated: 2019/12/04 13:30:15 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../libft/libft.h"
#include <math.h>

void	ini_fractal_heart(t_lst_display *win)
{
	win->minreal = -2.0;
	win->minima = -1.5;
	win->maxreal = 0.0;
	win->maxima = win->minima + (win->maxreal - win->minreal)
	* (win->display_h / win->display_w);
	win->real_scale = (win->maxreal - win->minreal) / win->display_w;
	win->ima_scale = (win->maxima - win->minima) / win->display_h;
	win->max_it = 60;
	win->zoom_scale = 250;
	win->pt_function_init = &ini_fractal_heart;
	win->pt_function = &heart;
	win->julia_mod_enable = false;
	win->clr_m = 1;
	set_color_to_mode1(win);
	refresh_image(win);
}

int		heart_compute(t_lst_display *win, double c_im, int x)
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
		c.z_im = fabs(c.z_re) * c.z_im;
		c.z_im += c.z_im;
		c.z_im += c_im;
		c.z_re = c.z_re2 - c.z_im2 + c.c_re;
		c.z_re2 = sqrt(c.z_re);
		c.z_im2 = sqrt(c.z_im);
		i++;
	}
	return (i);
}

void	heart(t_lst_display *win, int start)
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
			color = colormod(heart_compute(win, c_im, x), win);
			fill_pix(win, x, y, color);
			x++;
		}
		y++;
	}
}
