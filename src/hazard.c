/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hazard.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:21:46 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/28 14:18:30 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../libft/libft.h"
#include <math.h>

void initialise_fractal_hazard(t_lst_display *win)
{	win->Minreal = -2.0;
	win->Minima = -1.2;
	win->Maxreal = 1.0;
	win->Maxima = win->Minima +(win->Maxreal - win->Minreal) * (win->display_h / win->display_w); 
	win->Real_scale = (win->Maxreal - win->Minreal) / win->display_w; 
	win->Ima_scale = (win->Maxima - win->Minima) / win->display_h; 
	win->Max_it = 60;
	win->zoom_scale = 250;
	win->pt_function = &hazard;
	win->julia_mod_enable = false;
	win->clr_m = 1;
	set_color_to_mode1(win);
	refresh_image(win);
}
 
void hazard(t_lst_display *win, int start )
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
	double tmp;
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
				tmp = c_re;
				c_re = c_re/ (c_re * c_re + c_im * c_im);
				c_im = (c_im/ (tmp * tmp + c_im * c_im) );
				while (i < win->Max_it)
				{
					Z_re2 = Z_re * Z_re;
					Z_im2 = Z_im * Z_im;
					if ((Z_re2 + Z_im2)  > 4)
					 	break;
					// Z_im = sinh(Z_im) + c_re;
					// Z_re = sinh(Z_re) + c_im;
					tmp = Z_re;
					// Z_re = cos(Z_re) * cosh(Z_im);
					// Z_im = (sin(tmp) * sinh(Z_im));
					Z_re = cos(Z_re) * cosh(Z_im);
					Z_im = (sin(Z_re) * sinh(Z_im));
					// Z_re = cos(Z_re) * ((exp(Z_im)+ exp(-Z_im)) / 2);
					// Z_im = (sin(Z_re) * ((exp(Z_im)-exp(-Z_im))/2));
					Z_re += c_re; 
					Z_im -= c_im;
					i++;
				}
				color = colormod(i, win);
				fill_pix(win,x,y, color);		
			x++;
		}
	y++;
	}
}


/*
void hazard(t_lst_display *win, int start )
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
	double tmp;
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
					// Z_im = sinh(Z_im) + c_re;
					// Z_re = sinh(Z_re) + c_im;
					tmp = Z_re;
					Z_re = (pow(Z_re,3) - 3* Z_re *pow(Z_im,2)) ;
					Z_im = ((3* pow(tmp,2)*Z_im) - (pow(Z_im,3)));
					Z_re += c_re;
					Z_im += c_im;

					i++;
				}
				color = colormod(i, win);
				fill_pix(win,x,y, color);		
			x++;
		}
	y++;
	}
}
*/