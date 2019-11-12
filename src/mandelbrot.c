/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 15:52:03 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/12 15:12:33 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../libft/libft.h"
#include <math.h>
//  a retirer
#include  <stdio.h>

// a bouger dans la libft
unsigned int	convert_rgb(unsigned int a, unsigned int r, unsigned int g,
	unsigned int b)
{
	unsigned int nb;

	if (a > 0xff)
		a = 0xff;
	if (r > 0xff)
		r = 0xff;
	if (g > 0xff)
		g = 0xff;
	if (b > 0xff)
		b = 0xff;
	nb = ((a << 24) | (r << 16) | (g << 8) | (b));
	return (nb);
}

void initialise_fractal_mandel(t_lst_display **win)
{	(*win)->Minreal = -2.0;
	(*win)->Minima = -1.2;
	(*win)->Maxreal = 1.0;
	(*win)->Maxima = (*win)->Minima +((*win)->Maxreal - (*win)->Minreal) * ((*win)->w_height / (*win)->w_width); 
	(*win)->Real_scale = ((*win)->Maxreal - (*win)->Minreal) / (*win)->w_width; // (*win)->w_width - 1
	(*win)->Ima_scale = ((*win)->Maxima - (*win)->Minima) / (*win)->w_height; // (*win)->w_height - 1
	(*win)->Max_it = 30;
	(*win)->pt_function = &mandelbrot;
	(*win)->color = convert_rgb(0x0,255,0,0);
	(*win)->x = (*win)->w_width / 2;
	(*win)->y = (*win)->w_height / 2;
}
 

void mandelbrot(t_lst_display **win)
{
	int x;
	int y;
	int i;
	double c_im;
	double c_re;
	t_bool isin;
	double Z_re;
	double Z_im;
	double Z_re2;
	double Z_im2;
	unsigned int color;

	y = 0;
	
	while (y < (*win)->w_height)
	{
		c_im = (*win)->Maxima - y * (*win)->Ima_scale;
		x = 0;
		while (x < (*win)->w_width)
		{
				c_re = (*win)->Minreal + x * (*win)->Real_scale;
				isin = true;
				i = 0;
				Z_re = c_re;
				Z_im = c_im;
				while (i < (*win)->Max_it)
				{
					Z_re2 = pow(Z_re,2);
					Z_im2 = pow(Z_im,2);
					if (Z_re2 + Z_im2  > 4)
					{
						break;
					}
					Z_im = 2 * Z_re * Z_im + c_im;
					Z_re = Z_re2 - Z_im2 + c_re;
					i++;
				}
				color = convert_rgb(0x0, 255, 255,255 * (i < (*win)->Max_it));
				fill_pix(win,x,y, color);
				x++;
		}
		y++;
	}
}

/*
void mandelbrot(t_lst_display **win)
{
	int x;
	int y;
	int i;
	double x1;
	double x2;
	double y1;
	double y2;
	double c_im;
	double c_re;
	double old_re;
	double old_im;
	double new_re;
	double new_im;
	double zoom_x;
	double zoom_y;
	unsigned int color;

//	printf("Debut Mandelbrot\n");
	y = 0;
	x1 = -2.1;
	x2 = 1.0;
	y1 = -1.2;
	y2 = y1 + x2 - x1 * ((*win)->w_height / (*win)->w_width);
	
	zoom_x = (*win)->w_width / (x2 -x1);
	zoom_y = (*win)->w_height /(y2 -y1);
	while (y < (*win)->w_height)
	{
	//	printf("Boucle\n");
		c_im = y / zoom_y + y1;
		x = 0;
		while (x < (*win)->w_width)
		{
		//		printf("Y: %d X: %d\n",y,x);
				c_re = x / zoom_x+ x1;
				
		//		printf("C_im: %f C_re: %f\n",c_im,c_re);
				i = 0;
				new_im = 0;
				old_im = 0;
				new_re = 0;
				old_re = 0;
				while (i < (*win)->Max_it)
				{
			//		printf("Boucle it\n");
					old_re = new_re;
					old_im = new_im;
					new_re = old_re * old_re - old_im * old_im + c_re;
			//		printf("new_re %f\n",new_re);
					new_im = 2 * old_re * old_im + c_im;
				//	printf("new_im %f\n",new_im);
					if ((new_re * new_re + new_im * new_im) > 4)
						break;
					i++;
				}
				color = convert_rgb(0x0, 255, 255,255 * (i < (*win)->Max_it));
				fill_pix(win,x,y, color);
				x++;
		}
		y++;
	}
//	printf("Fin Mandelbrot\n");
}
*/
/*
void mandelbrot(t_lst_display **win)
{
	int x;
	int y;
	int i;
	double c_im;
	double c_re;
	double old_re;
	double old_im;
	double new_re;
	double new_im;
	unsigned int color;

	y = 0;
	
	while (y < (*win)->w_height)
	{
//		printf(" cim/ %f\n",(0.5 * (*win)->zoom_scale * (*win)->w_height));
		c_im = (y - (*win)->y) / (0.5 * (*win)->zoom_scale * (*win)->w_height) ;
		// 2eme version
		//c_im = (y - ((*win)->w_height / 2) + (*win)->y) / (0.5 * (*win)->zoom_scale * (*win)->w_height) ;
		//c_im = (y - (*win)->w_height / 2) / (0.5 * (*win)->zoom_scale * (*win)->w_height) + (*win)->y;
		x = 0;

		while (x < (*win)->w_width)
		{
		//		printf(" cre/ %f\n",(0.5 * (*win)->zoom_scale * (*win)->w_width));
				c_re = 1.5 * (x - (*win)->y) / (0.5 * (*win)->zoom_scale * (*win)->w_width);
				//c_re = 1.5 * (x - ((*win)->w_width / 2) + (*win)->x)/ (0.5 * (*win)->zoom_scale * (*win)->w_width);
				//c_re = 1.5 * (x - (*win)->w_width / 2) / (0.5 * (*win)->zoom_scale * (*win)->w_width ) + (*win)->x;
				i = 0;
				new_im = 0;
				old_im = 0;
				new_re = 0;
				old_re = 0;
				while (i < (*win)->Max_it)
				{
					old_re = new_re;
					old_im = new_im;
					new_re = old_re * old_re - old_im * old_im + c_re;
					new_im = 2 * old_re * old_im + c_im;
					if (new_re * new_re + new_im * new_im > 4)
						break;
					i++;
				}
				//#error floating point
				color = convert_rgb(0x0, 255 % i, i % 255,255 * (i < (*win)->Max_it));
				fill_pix(win,x,y, color);
				x++;
		}
		y++;
	}
}
*/
/*
void mandelbrot(t_lst_display **win)
{
	int x;
	int y;
	int i;
	double c_im;
	double c_re;
	t_bool isin;
	double Z_re;
	double Z_im;
	double Z_re2;
	double Z_im2;

	y = 0;
	
	while (y < (*win)->w_height)
	{
		c_im = (*win)->Maxima - y * (*win)->Ima_scale;
		x = 0;
		while (x < (*win)->w_width)
		{
				c_re = (*win)->Minreal + x * (*win)->Real_scale;
				isin = true;
				i = 0;
				Z_re = c_re;
				Z_im = c_im;
				while (i < (*win)->Max_it)
				{
					Z_re2 = pow(Z_re,2);
					Z_im2 = pow(Z_im,2);
					if (Z_re2 + Z_im2  > 4)
					{
						isin = false;
						break;
					}
					Z_im = 2 * Z_re * Z_im + c_im;
					Z_re = Z_re2 - Z_im2 + c_re;
					i++;
				}
				if (isin == true)
				{
					fill_pix(win, x, y,(*win)->color);
				}
				x++;
		}
		y++;
	}
}
*/