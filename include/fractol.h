/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:46:10 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/14 12:04:19 by qlouisia         ###   ########.fr       */
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
	double zoom_scale;
	unsigned int color;
	double x;
	double y;
	
} t_lst_display;

int initialise_graphic(t_lst_display **win, void *mlx_serv, char *tittle);
void initialise_fractal_mandel(t_lst_display **win);
void	fill_pix(t_lst_display **img, int x, int y, int color);
void mandelbrot(t_lst_display **win);
void	refresh_image(t_lst_display **win);
int quit_program(t_lst_display **env);
int mouse_control(int m_code, int x, int y, t_lst_display **win);
int	move(int keycode, t_lst_display **param);
unsigned int	convert_rgb(unsigned int a, unsigned int r, unsigned int g,
	unsigned int b)
#endif

