/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:45:06 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/19 20:23:00 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/fractol.h"
#include "../libft/libft.h"
#include <math.h>
//  a retirer
#include  <stdio.h>

void initialise_fractal_julia(t_lst_display *win)
{	
	win->Minreal = -1.5;
	win->Minima = -1.2;
	win->Maxreal = 1.0;
	win->Maxima = win->Minima +(win->Maxreal - win->Minreal) * (win->display_h / win->display_w); 
	win->Real_scale = (win->Maxreal - win->Minreal) / win->display_w; 
	win->Ima_scale = (win->Maxima - win->Minima) / win->display_h;
	win->julia_re = 200/ win->zoom_scale + win->Minreal;
	win->julia_im = 100 / win->zoom_scale + win->Minima ;
	win->pt_function = &julia;
	win->julia_mod_enable = false;
	set_color_to_mode1(win);
	refresh_image(win);
}
 
 

void julia(t_lst_display *win, int start )
{
	int x;
	int y;
	int i;
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
		x = start;
		while (x < xmax)
		{
				i = 0;
				Z_re = x / win->zoom_scale + win->Minreal;
				Z_im = y / win->zoom_scale + win->Minima ;
				while (i < win->Max_it)
				{
					Z_re2 = Z_re * Z_re;
					Z_im2 = Z_im * Z_im;
					if (Z_re2 + Z_im2  > 4)
						break;
					Z_im = Z_re * Z_im;
					Z_im += Z_im;
					Z_im += win->julia_im;
					Z_re = Z_re2 - Z_im2 + win->julia_re;
					Z_re2 = sqrt(Z_re);
					Z_im2 = sqrt(Z_im);
					i++;
				}
				color = colormod(i, win);
				fill_pix(win,x,y, color);
				
				x++;
		}
		y++;
	}
}
