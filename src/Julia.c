/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
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

void	ini_fractal_julia(t_lst_display *win)
{
	win->minreal = -1.5;
	win->minima = -1.2;
	win->maxreal = 1.0;
	win->maxima = win->minima + (win->maxreal - win->minreal)
	* (win->display_h / win->display_w);
	win->real_scale = (win->maxreal - win->minreal) / win->display_w;
	win->ima_scale = (win->maxima - win->minima) / win->display_h;
	win->julia_re = 200 / win->zoom_scale + win->minreal;
	win->julia_im = 100 / win->zoom_scale + win->minima;
	win->max_it = 30;
	win->pt_function = &julia;
	win->zoom_scale = 250;
	win->pt_function_init = &ini_fractal_julia;
	win->julia_mod_enable = false;
	set_color_to_mode1(win);
	refresh_image(win);
}

int		julia_compute(t_lst_display *win, int x, int y)
{
	t_complex	c;
	int			i;

	i = 0;
	c.z_re = x / win->zoom_scale + win->minreal;
	c.z_im = y / win->zoom_scale + win->minima;
	while (i < win->max_it)
	{
		c.z_re2 = c.z_re * c.z_re;
		c.z_im2 = c.z_im * c.z_im;
		if (c.z_re2 + c.z_im2 > 4)
			break ;
		c.z_im = c.z_re * c.z_im;
		c.z_im += c.z_im;
		c.z_im += win->julia_im;
		c.z_re = c.z_re2 - c.z_im2 + win->julia_re;
		c.z_re2 = sqrt(c.z_re);
		c.z_im2 = sqrt(c.z_im);
		i++;
	}
	return (i);
}

void	julia(t_lst_display *win, int start)
{
	int				x;
	int				y;
	unsigned int	color;
	int				xmax;

	y = 0;
	xmax = start + win->display_w / THREAD_NUMBER;
	while (y < win->display_h)
	{
		x = start;
		while (x < xmax)
		{
			color = colormod(julia_compute(win, x, y), win);
			fill_pix(win, x, y, color);
			x++;
		}
		y++;
	}
}
