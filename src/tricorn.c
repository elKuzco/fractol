/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:55:25 by qlouisia          #+#    #+#             */
/*   Updated: 2019/12/02 19:37:10 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../libft/libft.h"
#include <math.h>

void	initialise_fractal_tricorn(t_lst_display *win)
{
	win->Minreal = -2.5;
	win->Minima = -2.0;
	win->Maxreal = -0.5;
	win->Maxima = win->Minima + (win->Maxreal - win->Minreal)
	* (win->display_h / win->display_w);
	win->Real_scale = (win->Maxreal - win->Minreal) / win->display_w;
	win->Ima_scale = (win->Maxima - win->Minima) / win->display_h;
	win->Max_it = 60;
	win->zoom_scale = 150;
	win->pt_function = &tricorn;
	win->julia_mod_enable = false;
	win->pt_function_init = &initialise_fractal_tricorn;
	win->clr_m = 1;
	set_color_to_mode1(win);
	refresh_image(win);
}

int		tricorn_compute(t_lst_display *win, double c_im, int x)
{
	t_complex	c;
	int			i;

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
		c.z_im = -2 * c.z_re * c.z_im + c_im;
		c.z_re = c.z_re2 - c.z_im2 + c.c_re;
		i++;
	}
	return (i);
}

void	tricorn(t_lst_display *win, int start)
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
			color = colormod(tricorn_compute(win, c_im, x), win);
			fill_pix(win, x, y, color);
			x++;
		}
		y++;
	}
}
