/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:45:06 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/28 13:12:27 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../libft/libft.h"
#include <math.h>

void	initialise_fractal_julia(t_lst_display *win)
{
	win->Minreal = -1.5;
	win->Minima = -1.2;
	win->Maxreal = 1.0;
	win->Maxima = win->Minima + (win->Maxreal - win->Minreal)
	* (win->display_h / win->display_w);
	win->Real_scale = (win->Maxreal - win->Minreal) / win->display_w;
	win->Ima_scale = (win->Maxima - win->Minima) / win->display_h;
	win->julia_re = 200 / win->zoom_scale + win->Minreal;
	win->julia_im = 100 / win->zoom_scale + win->Minima;
	win->pt_function = &julia;
	win->zoom_scale = 250;
	win->julia_mod_enable = false;
	set_color_to_mode1(win);
	refresh_image(win);
}

int		julia_compute(t_lst_display *win, int x, int y)
{
	t_complex	c;
	int			i;

	i = 0;
	c.z_re = x / win->zoom_scale + win->Minreal;
	c.z_im = y / win->zoom_scale + win->Minima;
	while (i < win->Max_it)
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
