/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:39:08 by qlouisia          #+#    #+#             */
/*   Updated: 2019/12/02 19:37:45 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../libft/libft.h"
#include <math.h>

void	initialise_fractal_julia3(t_lst_display *win)
{
	win->Minreal = -2.3;
	win->Minima = -2;
	win->Maxreal = 0.2;
	win->zoom_scale = 180;
	win->Maxima = win->Minima + (win->Maxreal - win->Minreal)
	* (win->display_h / win->display_w);
	win->Real_scale = (win->Maxreal - win->Minreal) / win->display_w;
	win->Ima_scale = (win->Maxima - win->Minima) / win->display_h;
	win->julia_re = 200 / win->zoom_scale + win->Minreal;
	win->julia_im = 100 / win->zoom_scale + win->Minima;
	win->Max_it = 15;
	win->pt_function_init = &initialise_fractal_julia3;
	win->pt_function = &julia3;
	win->julia_mod_enable = false;
	set_color_to_mode1(win);
	refresh_image(win);
}

int		julia3_compute(t_lst_display *win, int x, int y)
{
	t_complex	c;
	int			i;
	double		tmp;

	i = 0;
	c.z_re = x / win->zoom_scale + win->Minreal;
	c.z_im = y / win->zoom_scale + win->Minima;
	while (i < win->Max_it)
	{
		c.z_re2 = c.z_re * c.z_re;
		c.z_im2 = c.z_im * c.z_im;
		if (c.z_re2 + c.z_im2 > 4)
			break ;
		tmp = c.z_re;
		c.z_re = (pow(c.z_re, 3) - 3 * c.z_re * pow(c.z_im, 2));
		c.z_im = ((3 * pow(tmp, 2) * c.z_im) - (pow(c.z_im, 3)));
		c.z_re += win->julia_re;
		c.z_im += win->julia_im;
		i++;
	}
	return (i);
}

void	julia3(t_lst_display *win, int start)
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
			color = colormod(julia3_compute(win, x, y), win);
			fill_pix(win, x, y, color);
			x++;
		}
		y++;
	}
}
