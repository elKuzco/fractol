/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:46:10 by qlouisia          #+#    #+#             */
/*   Updated: 2019/10/23 17:22:03 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

typedef struct s_lst_fractol 
{
	void *img_ptr;
	int *data;
	int size_l;
	int bpp;
	int endian;
	void *mlx_ptr;
	void *win_ptr;
	int w_width;
	int w_height;
	void (*pt_function)(struct s_lst_fractol **);
	double Minreal;
	double Minima;
	double Maxreal;
	double Maxima; 
	double Real_scale;
	double Ima_scale;
	int Max_it;
	
} t_lst_display;

int initialise_graphic(t_lst_display **win, void *mlx_serv, char *tittle);
void initialise_fractal_mandel(t_lst_display **win);
void	fill_pix(t_lst_display **img, int x, int y, int color);
void mandelbrot(t_lst_display **win);
void	refresh_image(t_lst_display **win);
#endif

