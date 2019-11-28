/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 19:48:02 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/28 13:55:32 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../libft/libft.h"
#include <math.h>

void	initialise_fractal_burningship(t_lst_display *win)
{
	win->Minreal = -2.0;
	win->Minima = -2.2;
	win->Maxreal = 0.0;
	win->Maxima = win->Minima + (win->Maxreal - win->Minreal)
	* (win->display_h / win->display_w);
	win->Real_scale = (win->Maxreal - win->Minreal) / win->display_w;
	win->Ima_scale = (win->Maxima - win->Minima) / win->display_h;
	win->Max_it = 60;
	win->zoom_scale = 250;
	win->pt_function = &burningship;
	win->julia_mod_enable = false;
	win->clr_m = 1;
	set_color_to_mode1(win);
	refresh_image(win);
}

int		burningship_compute(t_lst_display *win, double c_im, int x)
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
		c.z_im = c.z_re * c.z_im;
		c.z_im += c.z_im;
		c.z_im += c_im;
		c.z_re = c.z_re2 - c.z_im2 + c.c_re;
		c.z_re = fabs(c.z_re);
		c.z_im = fabs(c.z_im);
		c.z_re2 = sqrt(c.z_re);
		c.z_im2 = sqrt(c.z_im);
		i++;
	}
	return (i);
}

void	burningship(t_lst_display *win, int start)
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
			color = colormod(burningship_compute(win, c_im, x), win);
			fill_pix(win, x, y, color);
			x++;
		}
		y++;
	}
}
