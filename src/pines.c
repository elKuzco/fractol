/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:21:46 by qlouisia          #+#    #+#             */
/*   Updated: 2019/12/03 17:38:00 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../libft/libft.h"
#include <math.h>

void	initialise_fractal_pines(t_lst_display *win)
{
	win->Minreal = -12.0;
	win->Minima = -12.0;
	win->Maxreal = -9.0;
	win->Maxima = win->Minima + (win->Maxreal - win->Minreal)
	* (win->display_h / win->display_w);
	win->Real_scale = (win->Maxreal - win->Minreal) / win->display_w;
	win->Ima_scale = (win->Maxima - win->Minima) / win->display_h;
	win->Max_it = 25;
	win->zoom_scale = 30;
	win->pt_function_init = &initialise_fractal_pines;
	win->pt_function = &pines;
	win->julia_mod_enable = false;
	win->clr_m = 2;
	set_color_to_mode1(win);
	refresh_image(win);
}

int		pines_compute(t_lst_display *win, double c_im, int x)
{
	int				i;
	t_complex_trig	c;

	c.c_re = x / win->zoom_scale + win->Minreal;
	set_struct_comp(&c, c_im);
	c.n_zim = c_im;
	i = 0;
	while (i < win->Max_it)
	{
		c.z_re = c.n_zre;
		c.z_im = c.n_zim;
		c.z_re2 = c.z_re * c.z_re;
		c.z_im2 = c.z_im * c.z_im;
		c.z_2 = c.z_re2 + c.z_im2;
		if (c.z_2 < 4)
			break ;
		c.n_zre = cos(c.z_re) * cosh(c.z_im);
		c.n_zim = -sin(c.z_re) * sinh(c.z_im);
		c.n_zre += c.inv_re;
		c.n_zim += c.inv_im;
		i++;
	}
	return (i);
}

void	pines(t_lst_display *win, int start)
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
			color = colormod(pines_compute(win, c_im, x), win);
			fill_pix(win, x, y, color);
			x++;
		}
		y++;
	}
}
