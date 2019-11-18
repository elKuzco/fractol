/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 15:52:03 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/18 13:05:55 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../libft/libft.h"
#include <math.h>
//  a retirer
#include  <stdio.h>

void initialise_fractal_mandel(t_lst_display **win)
{	(*win)->Minreal = -2.0;
	(*win)->Minima = -1.2;
	(*win)->Maxreal = 1.0;
	(*win)->Maxima = (*win)->Minima +((*win)->Maxreal - (*win)->Minreal) * ((*win)->display_h / (*win)->display_w); 
	(*win)->Real_scale = ((*win)->Maxreal - (*win)->Minreal) / (*win)->display_w; // (*win)->display_w - 1
	(*win)->Ima_scale = ((*win)->Maxima - (*win)->Minima) / (*win)->display_h; // (*win)->display_h - 1
	(*win)->Max_it = 60;
	(*win)->zoom_scale = 250;
	(*win)->pt_function = &mandelbrot;
	(*win)->color_mod = 1;
	set_color_to_mode1(win);
	refresh_image(win);
}
 
 int is_in_bulb(double c_re, double c_im)
 {
	 double p;
	 
	 p = sqrt(pow((c_re - 0.25),2)+ pow(c_im,2));
//	printf("c_re : %f | c_im : %f |(c_re + 1)^2 + c_im^2 = %f\n", c_re, c_im,pow(c_re + 1,2) + pow(c_im,2));
	 
	 if (c_re < (p - 2 * pow(p,2) + 0.25)) 
	 {
		// printf("is in cariodes\n");
		 return (1);
	 }
	 
	 else if ((pow(c_re + 1,2) + pow(c_im,2)) <= 0.0625)
	 {
		 //printf("in the circle\n");
		 return (1);
	 }
	 return (0);
 }
 

void mandelbrot(t_lst_display **win)
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

	y = 0;
	
	while (y < (*win)->display_h)
	{
		c_im = y / (*win)->zoom_scale + (*win)->Minima;
		//c_im = (*win)->Maxima - y * (*win)->Ima_scale;
		x = 0;
		while (x < (*win)->display_w)
		{
				c_re = x / (*win)->zoom_scale + (*win)->Minreal;
				//c_re = (*win)->Minreal + x * (*win)->Real_scale;
				if (is_in_bulb(c_re, c_im) == 1)
				{
					
				}
				else 
				{
					i = 0;
					Z_re = c_re;
					Z_im = c_im;
					while (i < (*win)->Max_it)
					{
						Z_re2 = Z_re * Z_re;
						Z_im2 = Z_im * Z_im;
						if (Z_re2 + Z_im2  > 4)
						{
							break;
						}
						Z_im = Z_re * Z_im;
						Z_im += Z_im;
						Z_im += c_im;
						Z_re = Z_re2 - Z_im2 + c_re;
						Z_re2 = sqrt(Z_re);
						Z_im2 = sqrt(Z_im);
						i++;
					}
					//color = convert_rgb(0x0, 0, 0,255*i / (*win)->Max_it);
					color = colormod(i, win);
					fill_pix(win,x,y, color);
				}
				x++;
		}
		y++;
	}
}
