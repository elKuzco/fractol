/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:55:25 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/22 20:03:22 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "../include/fractol.h"
#include "../libft/libft.h"
#include <math.h>
//  a retirer
#include  <stdio.h>

void initialise_fractal_tricorn(t_lst_display *win)
{	win->Minreal = -2.5;
	win->Minima = -2.0;
	win->Maxreal = -0.5;
	win->Maxima = win->Minima +(win->Maxreal - win->Minreal) * (win->display_h / win->display_w); 
	win->Real_scale = (win->Maxreal - win->Minreal) / win->display_w; 
	win->Ima_scale = (win->Maxima - win->Minima) / win->display_h; 
	win->Max_it = 60;
	win->zoom_scale = 150;
	win->pt_function = &tricorn;
	win->julia_mod_enable = false;
	win->color_mod = 1;
	set_color_to_mode1(win);
	refresh_image(win);
}
 
 
void tricorn(t_lst_display *win, int start )
{
	int x;
	int y;
	int i;
	double c_im;
	double c_re;
	double Z_re;
	double Z_im;
	double Z_re2;
	double Z_im2;
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
				c_re = x / win->zoom_scale + win->Minreal;
				i = 0;
				Z_re = c_re;
				Z_im = c_im;
				while (i < win->Max_it)
				{
					Z_re2 = Z_re * Z_re;
					Z_im2 = Z_im * Z_im;
					if ((Z_re2 + Z_im2)  > 4)
						break;
					Z_im = -2 * Z_re * Z_im + c_im;
					Z_re = Z_re2 - Z_im2 + c_re;
					i++;
				}
				color = colormod(i, win);
				fill_pix(win,x,y, color);		
			x++;
		}
	y++;
	}
}
