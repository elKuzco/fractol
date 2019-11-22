/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:45:06 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/22 20:47:37 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/fractol.h"
#include "../libft/libft.h"
#include <math.h>
//  a retirer
#include  <stdio.h>

void initialise_fractal_julia3(t_lst_display *win)
{	
	win->Minreal = -1.5;
	win->Minima = -1.2;
	win->Maxreal = 1.0;
	win->Maxima = win->Minima +(win->Maxreal - win->Minreal) * (win->display_h / win->display_w); 
	win->Real_scale = (win->Maxreal - win->Minreal) / win->display_w; 
	win->Ima_scale = (win->Maxima - win->Minima) / win->display_h;
	win->julia_re = 200/ win->zoom_scale + win->Minreal;
	win->julia_im = 100 / win->zoom_scale + win->Minima ;
	win->Max_it = 25;
	win->pt_function = &julia3;
	win->julia_mod_enable = false;
	set_color_to_mode1(win);
	refresh_image(win);
}
 
 

void julia3(t_lst_display *win, int start )
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
	double tmp;

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
					if ((Z_re2 + Z_im2)  > 4)
						break;
					tmp = Z_re;
					Z_re = (pow(Z_re,3) - 3* Z_re *pow(Z_im,2)) ;
					Z_im = ((3* pow(tmp,2)*Z_im) - (pow(Z_im,3)));
					Z_re += win->julia_re;
					Z_im += win->julia_im;
					i++;
				}
				color = colormod(i, win);
				fill_pix(win,x,y, color);
				
				x++;
		}
		y++;
	}
}
