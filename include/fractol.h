/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:46:10 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/18 19:34:26 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include <pthread.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 1200
#define THREAD_NUMBER 4 
#define DISPLAY_WIDTH 800 
#define DISPLAY_HEIGHT 800



typedef struct s_lst_fractol 
{
	void *img_ptr;
	int *data;
	int size_l;
	int bpp;
	int endian;
	void *mlx_ptr;
	void *win_ptr;
	int display_w;
	int display_h;
	pthread_t id_tread[THREAD_NUMBER];
	void (*pt_function)(struct s_lst_fractol **, int);
	double Minreal;
	double Minima;
	double Maxreal;
	double Maxima; 
	double Real_scale;
	double Ima_scale;
	int Max_it;
	double zoom_scale;
	int color_mod;
	unsigned int palette[16];
	int palettte_size;
} t_lst_display;

int initialise_graphic(t_lst_display **win, void *mlx_serv, char *tittle);
void initialise_fractal_mandel(t_lst_display **win);
void	fill_pix(t_lst_display **img, int x, int y, int color);
void mandelbrot(t_lst_display **win, int start );
void	refresh_image(t_lst_display **win);
int quit_program(t_lst_display **env);
int mouse_control(int m_code, int x, int y, t_lst_display **win);
int	move(int keycode, t_lst_display **param);
unsigned int colormod (int n, t_lst_display **win);
void set_color_to_mode1(t_lst_display **win);
unsigned int	convert_rgb(unsigned int a, unsigned int r, unsigned int g,
	unsigned int b);
void set_color_to_rainbow(t_lst_display **win);
int initialise_thread(t_lst_display **win);
#endif

