/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 15:52:03 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/19 13:50:09 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../libft/libft.h"
#include <math.h>
//  a retirer
#include  <stdio.h>

void initialise_fractal_mandel(t_lst_display *win)
{	win->Minreal = -2.0;
	win->Minima = -1.2;
	win->Maxreal = 1.0;
	win->Maxima = win->Minima +(win->Maxreal - win->Minreal) * (win->display_h / win->display_w); 
	win->Real_scale = (win->Maxreal - win->Minreal) / win->display_w; 
	win->Ima_scale = (win->Maxima - win->Minima) / win->display_h; 
	win->Max_it = 60;
	win->zoom_scale = 250;
	win->pt_function = &mandelbrot;
	win->julia_mod_enable = false;
	win->color_mod = 1;
	set_color_to_mode1(win);
	refresh_image(win);
}
 
 int is_in_bulb(double c_re, double c_im)
 {
	 double p;
	 
	 p = sqrt(pow((c_re - 0.25),2)+ pow(c_im,2));	 
	 if (c_re < (p - 2 * pow(p,2) + 0.25)) 
		 return (1);
	 
	 else if ((pow(c_re + 1,2) + pow(c_im,2)) <= 0.0625)
		 return (1);
	 return (0);
 }
 
 
 int mandelbrot_compute(t_lst_display *win, double c_im, int x)
 {
	double c_re;
 	double Z_re;
 	double Z_im;
 	double Z_re2;
 	double Z_im2;
	int i;
	
	
	i = 0;
	c_re = x / win->zoom_scale + win->Minreal;
	if (is_in_bulb(c_re, c_im) == 0)
	{
		Z_re = c_re;
		Z_im = c_im;
		while (i < win->Max_it)
		{
			Z_re2 = Z_re * Z_re;
			Z_im2 = Z_im * Z_im;
			if (Z_re2 + Z_im2  > 4)
				break;
			Z_im = Z_re * Z_im;
			Z_im += Z_im;
			Z_im += c_im;
			Z_re = Z_re2 - Z_im2 + c_re;
			Z_re2 = sqrt(Z_re);
			Z_im2 = sqrt(Z_im);
			i++;
		}
 }
 return (i);
}
 
 
 /*
 ** tab[0] = c_re
 ** tab[1] = Z_re
 ** tab[2] = Z_im
 ** tab[3] = Z_re2
 ** tab[4] = Z_im2
 */
 
 /*
 int mandelbrot_compute(t_lst_display *win, double c_im, int x)
 {
	double tab[5];
	int i;
	
	i = 0;
	tab[0] = x / win->zoom_scale + win->Minreal;
	if (is_in_bulb(tab[0], c_im) == 0)
	{
		tab[1] = tab[0];
		tab[2] = c_im;
		while (i < win->Max_it)
		{
			tab[3] = tab[1] * tab[1];
			tab[4] = tab[2] * tab[2];
			if (tab[3] + tab[4]  > 4)
				break;
			tab[2] = tab[1] * tab[2];
			tab[2] += tab[2];
			tab[2] += c_im;
			tab[1] = tab[3] - tab[4] + tab[0];
			tab[3] = sqrt(tab[1]);
			tab[4] = sqrt(tab[2]);
			i++;
		}
 }
 return (i);
}
*/
/*			Z_im = Z_re * Z_im;
			Z_im += Z_im;
			Z_im += c_im;*/




void mandelbrot(t_lst_display *win, int start )
{
	int x;
	int y;
	double c_im;
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
			color = colormod(mandelbrot_compute(win, c_im,x), win);
			fill_pix(win,x,y, color);
			x++;
		}
		y++;
	}
}

/*
void mandelbrot(t_lst_display *win, int start )
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
				if (is_in_bulb(c_re, c_im) == 0)
				{
					i = 0;
					Z_re = c_re;
					Z_im = c_im;
					while (i < win->Max_it)
					{
						Z_re2 = Z_re * Z_re;
						Z_im2 = Z_im * Z_im;
						if (Z_re2 + Z_im2  > 4)
							break;
						Z_im = Z_re * Z_im;
						Z_im += Z_im;
						Z_im += c_im;
						Z_re = Z_re2 - Z_im2 + c_re;
						Z_re2 = sqrt(Z_re);
						Z_im2 = sqrt(Z_im);
						i++;
					}
					color = colormod(i, win);
					fill_pix(win,x,y, color);
				}
				x++;
		}
		y++;
	}
}*/
